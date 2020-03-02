class Solution {
 public:
  string customSortString(string S, string T) {
    string ans;
    vector<int> count(26);

    for (char c : T) ++count[c - 'a'];

    for (char c : S)
      while (count[c - 'a']-- > 0) ans += c;

    for (int i = 0; i < 26; ++i)
      while (count[i]-- > 0) ans += i + 'a';

    return ans;
  }
};