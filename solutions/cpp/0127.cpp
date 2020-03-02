class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> set{begin(wordList), end(wordList)};

    if (!set.count(endWord)) return 0;

    int ans = 0;

    unordered_set<string> set1{beginWord};
    unordered_set<string> set2{endWord};

    while (!set1.empty() && !set2.empty()) {
      ++ans;
      if (set1.size() > set2.size()) swap(set1, set2);
      unordered_set<string> tempSet;
      for (string word : set1)
        for (int i = 0; i < word.length(); ++i) {
          char c = word[i];
          for (char j = 'a'; j <= 'z'; ++j) {
            word[i] = j;
            if (set2.count(word)) return ans + 1;
            if (!set.count(word)) continue;
            set.erase(word);
            tempSet.insert(word);
          }
          word[i] = c;
        }
      swap(set1, tempSet);
    }

    return 0;
  }
};