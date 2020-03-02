class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> set{begin(wordList), end(wordList)};

    if (!set.count(endWord)) return ans;

    unordered_set<string> set1{beginWord};
    unordered_map<string, vector<string>> map;
    bool isFound = false;

    while (!set1.empty() && !isFound) {
      for (const string& word : set1) set.erase(word);
      unordered_set<string> tempSet;
      for (const string& parent : set1) {
        string word = parent;
        for (int i = 0; i < word.length(); ++i) {
          char c = word[i];
          for (char j = 'a'; j <= 'z'; ++j) {
            word[i] = j;
            if (word == endWord) {
              map[parent].push_back(word);
              isFound = true;
            } else if (set.count(word) && !isFound) {
              tempSet.insert(word);
              map[parent].push_back(word);
            }
          }
          word[i] = c;
        }
      }
      swap(set1, tempSet);
    }

    if (isFound) {
      vector<string> path{beginWord};
      dfs(map, beginWord, endWord, path, ans);
    }

    return ans;
  }

 private:
  void dfs(const unordered_map<string, vector<string>>& map, const string& word,
           const string& endWord, vector<string>& path,
           vector<vector<string>>& ans) {
    if (word == endWord) {
      ans.push_back(path);
      return;
    }
    if (!map.count(word)) return;

    for (const string& child : map.at(word)) {
      path.push_back(child);
      dfs(map, child, endWord, path, ans);
      path.pop_back();
    }
  }
};