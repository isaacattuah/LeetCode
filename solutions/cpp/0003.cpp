class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<char, int> lastSeen;

    for (int i = 0, j = 0; i < s.length(); ++i) {
      char c = s[i];
      if (lastSeen.count(c)) j = max(j, lastSeen[c] + 1);
      ans = max(ans, i - j + 1);
      lastSeen[c] = i;
    }

    return ans;
  }
};