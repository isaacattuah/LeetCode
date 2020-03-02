class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        def dfs(word: str, path: List[str]) -> None:
            if word == endWord:
                ans.append(path)
                return
            if word not in dict:
                return

            for child in dict[word]:
                dfs(child, path + [child])

        ans = []
        set_ = set(wordList)

        if endWord not in set_:
            return ans

        set1 = set([beginWord])
        dict = collections.defaultdict(list)
        isFound = False

        while set1 and not isFound:
            for word in set1:
                set_.discard(word)
            tempSet = set()
            for parent in set1:
                for i in range(len(parent)):
                    for j in string.ascii_lowercase:
                        newWord = parent[:i] + j + parent[i + 1:]
                        if newWord == endWord:
                            dict[parent].append(newWord)
                            isFound = True
                        elif newWord in set_ and not isFound:
                            tempSet.add(newWord)
                            dict[parent].append(newWord)
            set1 = tempSet

        if isFound:
            dfs(beginWord, [beginWord])

        return ans
