class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    string ans = "****************";
    vector<int> count(26);

    for (char c : licensePlate)
      if (isalpha(c)) ++count[tolower(c) - 'a'];

    for (const string& word : words)
      if (word.length() < ans.length() && isMatch(word, count)) ans = word;

    return ans;
  }

 private:
  bool isMatch(const string& word, vector<int>& count) {
    vector<int> wordCount(26);

    for (char c : word) ++wordCount[c - 'a'];

    for (int i = 0; i < 26; ++i)
      if (wordCount[i] < count[i]) return false;

    return true;
  }
};