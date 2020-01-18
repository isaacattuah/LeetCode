from secret import *
from helper import *
from config import *
from threading import Thread
from requests_toolbelt import MultipartEncoder

import sys
import os
import re
import json
import requests
import argparse


class LeetCode():
    def __init__(self):
        self.session = requests.Session()
        self.session.cookies['LEETCODE_SESSION'] = LEETCODE_SESSION

    def getPercentage(self, API_URL: str):
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
        res = self.session.get(API_URL, headers=headers, timeout=10)
        res = json.loads(res.content.decode('utf-8'))

        return res['num_solved'], res['num_total'], res['ac_easy'], res['ac_medium'], res['ac_hard']

    def getProblemsStatAndStatus(self, API_URL: str) -> [dict, list]:
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
        res = self.session.get(API_URL, headers=headers, timeout=10)
        res = json.loads(res.content.decode('utf-8'))

        problems = res['stat_status_pairs']
        problems.reverse()

        return problems

    def getSubmissionStatus(self, questionSlug: str) -> dict:
        params = {
            'operationName': 'Submissions',
            'variables': {
                'offset': 0,
                'limit': 20,
                'lastKey': '',
                'questionSlug': questionSlug
            },
            'query':
            """
            query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {
                submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {
                    lastKey
                    hasNext
                    submissions {
                        id
                        statusDisplay
                        lang
                        runtime
                        timestamp
                        url
                        isPending
                        memory
                        __typename
                    }
                    __typename
                }
            }
            """
        }

        jsonData = json.dumps(params).encode('utf8')
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive', 'Referer': LOGIN_URL,
                   'Content-Type': 'application/json'}
        res = self.session.post(GRAPHQL_URL, data=jsonData,
                                headers=headers, timeout=10)
        content = res.json()

        submissions = {}
        for submission in content['data']['submissionList']['submissions']:
            if submission['statusDisplay'] == 'Accepted' and \
                    submission['lang'] not in submissions.keys() and \
                    submission['lang'] in langs.keys():
                submissions[submission['lang']] = submission

        return submissions

    def getCodeByID(self, submissionID: str) -> str:
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive',
                   'Content-Type': 'application/json'}
        codeContent = self.session.get(DETAIL_URL + submissionID,
                                       headers=headers,
                                       timeout=1000)
        pattern = re.compile(
            r'submissionCode: \'(?P<code>.*)\',\n  editCodeUrl',
            re.S)

        m1 = pattern.search(codeContent.text)
        code = m1.groupdict()['code'] if m1 else "Error"
        code = code.encode('utf8').decode('unicode_escape')

        return code

    def writeREADME(self, problems: list, writeSolutions: bool):
        if writeSolutions:
            if not os.path.exists('solutions'):
                os.makedirs('solutions')

            for lang in langs.keys():
                if not os.path.exists('solutions/' + lang):
                    os.makedirs('solutions/' + lang)

        readme = open('../README.md', 'w')
        try:
            with open('PREFIX.md') as f:
                for line in f:
                    readme.write(line)
        except FileNotFoundError:
            print("No such file or directory: 'PREFIX.md'")

        num_solved, num_total, ac_easy, ac_medium, ac_hard = self.getPercentage(
            API_URL)

        solved = SHIELDS_URL + str(num_solved) + '/' + str(num_total) + '%20=%20' + str(
            round((num_solved / num_total) * 100, 2)) + '%25%20' + 'Solved-blue.svg" />'
        easy = SHIELDS_URL + 'Easy%20' + str(ac_easy) + '-brightgreen.svg" />'
        medium = SHIELDS_URL + 'Medium%20' + str(ac_medium) + '-yellow.svg" />'
        hard = SHIELDS_URL + 'Hard%20' + str(ac_hard) + '-red.svg" />'

        readme.write('\n## Problem Sets\n\n')
        readme.write('<p align="center">\n')
        readme.write(solved + '\n')
        readme.write(easy + '\n')
        readme.write(medium + '\n')
        readme.write(hard + '\n')
        readme.write('</p>\n\n')
        readme.write('|#|Title|Solution|Difficulty|\n')
        readme.write('|:--:|:--|:--:|:--:|\n')

        for problem in problems:
            problemID = str(problem['stat']['frontend_question_id']).zfill(4)

            print('Write README.md: ' + problemID)
            readme.write('|' + problemID + '|')
            readme.write('[' + problem['stat']['question__title'] +
                         '](https://leetcode.com/problems/' + problem['stat']['question__title_slug'] + ')')
            readme.write(' 🔒|' if problem['paid_only'] else '|')

            if problem['status'] == 'ac':
                solutions = []
                submissions = self.getSubmissionStatus(
                    problem['stat']['question__title_slug'])

                for lang in langs:
                    if lang in submissions.keys():
                        directory = getDirectory(lang=lang,
                                                 problemID=problemID,
                                                 extension=langs[lang]['extension'])
                        solutions.append(
                            '[' + langs[lang]['display_lang'] + '](' + directory + ')')
                readme.write(', '.join(solutions))
            readme.write('|')

            if problem['status'] == 'ac' and writeSolutions:
                self.writeSolutions(problem=problem)

            if problem['difficulty']['level'] == 1:
                readme.write('Easy')
            elif problem['difficulty']['level'] == 2:
                readme.write('Medium')
            elif problem['difficulty']['level'] == 3:
                readme.write('Hard')
            readme.write('|\n')

    def writeSolutions(self, problem: list):
        problemID = str(problem['stat']['frontend_question_id']).zfill(4)
        submissions = self.getSubmissionStatus(
            problem['stat']['question__title_slug'])

        for lang in langs:
            if lang in submissions.keys():
                directory = getDirectory(lang=lang,
                                         problemID=problemID,
                                         extension=langs[lang]['extension'])

                with open('.' + directory, encoding='utf-8', mode='w+') as f:
                    print('Write solutions: ' + problemID +
                          langs[lang]['extension'])
                    code = self.getCodeByID(
                        submissionID=submissions[lang]['id'])
                    f.write(code)

    def writeMkdocs(self, problems: list, lang: str, highlight: str, extension: str):
        if not os.path.exists('../docs'):
            os.makedirs('../docs')

        if not os.path.exists('../docs/' + lang):
            os.makedirs('../docs/' + lang)

        for i, problem in enumerate(problems):
            if i % 100 == 0:
                path = '../docs/' + lang + '/' + getMkdocsPathName(i)
                if not os.path.exists(path):
                    os.makedirs(path)

            if i % 10 == 0:
                file = path + '/' + getMkdocsFileName(i)
                f = open(file, 'w+')
            else:
                f = open(file, 'a+')

            f.write('## ' + str(i + 1) + '. ' +
                    problem['stat']['question__title'] + ' ')
            f.write('[$')
            f.write('\\star' * problem['difficulty']['level'])
            f.write('$]')
            f.write('(https://leetcode.com/problems/' +
                    problem['stat']['question__title_slug'] + ')\n')

            try:
                daima = open('../solutions/' + lang + '/' +
                             str(i + 1).zfill(4) + extension, 'r').read()
                f.write('\n')
                f.write('```' + highlight + '\n')
                f.write(daima)
                if lang == 'python3':
                    f.write('```\n')
                else:
                    f.write('\n```\n')
            except FileNotFoundError:
                pass
                # print('No such file or directory:',
                #       str(i + 1).zfill(4) + extension)

            if i % 10 != 9:
                f.write('\n')


if __name__ == '__main__':
    LeetCode = LeetCode()

    problems = LeetCode.getProblemsStatAndStatus(API_URL)
    problems.sort(key=lambda x: x['stat']['frontend_question_id'])

    print('Get problems!')
    print('There are', len(problems), 'problems!')

    parser = argparse.ArgumentParser(description='Crawl LeetCode submissions.')
    parser.add_argument('--problem', '-p', type=int,
                        help='get a specific problem')
    parser.add_argument('--range', '-r', type=int, nargs='*',
                        help='get problems of range [a, b]')
    parser.add_argument('--mkdocs', '-m', type=str,
                        help='write mkdocs markdown files')
    parser.add_argument('--readme', '-rm', action='store_true',
                        help='write readme only')
    args = parser.parse_args()

    if len(sys.argv) < 2:
        # pylint: disable=no-value-for-parameter
        LeetCode.writeREADME(problems=problems,
                             writeSolutions=True)

    if args.problem:
        question_id = args.problem
        # pylint: disable=no-value-for-parameter
        LeetCode.writeSolutions(problems[question_id - 1])

    if args.range:
        start = args.range[0]
        end = args.range[1]
        problems = problems[start - 1: end]
        for problem in problems:
            # pylint: disable=no-value-for-parameter
            LeetCode.writeSolutions(problem)

    if args.mkdocs:
        arg = args.mkdocs
        if arg == 'all':
            for lang in langs.keys():
                LeetCode.writeMkdocs(problems=problems,
                                     lang=lang,
                                     highlight=langs[lang]['highlight'],
                                     extension=langs[lang]['extension'])
        else:
            # pylint: disable=no-value-for-parameter
            LeetCode.writeMkdocs(problems=problems,
                                 lang=arg,
                                 highlight=langs[arg]['highlight'],
                                 extension=langs[arg]['extension'])

    if args.readme:
        # pylint: disable=no-value-for-parameter
        LeetCode.writeREADME(problems=problems, writeSolutions=False)
