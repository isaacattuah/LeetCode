class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> count(26);

    for (char c : s) ++count[c - 'a'];

    for (int i = 0; i < t.length(); ++i)
      if (--count[t[i] - 'a'] < 0) return t[i];

    throw;
  }
};