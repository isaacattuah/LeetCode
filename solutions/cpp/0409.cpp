class Solution {
 public:
  int longestPalindrome(string s) {
    int ans = 0;
    vector<int> count(128);

    for (char c : s) ++count[c];

    for (int c : count) ans += c % 2 == 0 ? c : c - 1;

    bool hasOddCount =
        any_of(begin(count), end(count), [](int c) { return c & 1; });

    return ans + hasOddCount;
  }
};