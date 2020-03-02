class Solution {
 public:
  int characterReplacement(string s, int k) {
    int ans = 0;
    int maxFreq = 0;
    vector<int> count(26);

    for (int l = 0, r = 0; r <= s.length();) {
      if (r - l - maxFreq <= k) {
        ans = max(ans, r - l);
        if (r == s.length()) break;
        maxFreq = max(maxFreq, ++count[s[r] - 'A']);
        ++r;
      } else {
        --count[s[l] - 'A'];
        ++l;
      }
    }

    return ans;
  }
};