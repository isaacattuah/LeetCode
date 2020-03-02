class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> ans;
    vector<int> rows{2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
                     3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};

    for (const string& word : words) {
      string lowerWord = word;
      transform(begin(lowerWord), end(lowerWord), begin(lowerWord),
                [](char c) { return tolower(c); });
      int row = rows[lowerWord[0] - 'a'];
      bool isValid = true;
      for (int i = 1; i < lowerWord.length(); ++i)
        if (rows[lowerWord[i] - 'a'] != row) {
          isValid = false;
          break;
        }
      if (isValid) ans.push_back(word);
    }

    return ans;
  }
};