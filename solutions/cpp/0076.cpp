class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> count(128);
    int required = t.length();
    int bestLeft = 0;
    int minLength = INT_MAX;

    for (char c : t) ++count[c];

    for (int l = 0, r = 0; r <= s.length();) {
      if (required > 0) {
        if (r == s.length()) break;
        if (--count[s[r]] >= 0) --required;
        ++r;
      } else {
        if (r - l < minLength) {
          bestLeft = l;
          minLength = r - l;
        }
        if (++count[s[l]] > 0) ++required;
        ++l;
      }
    }

    return minLength == INT_MAX ? "" : s.substr(bestLeft, minLength);
  }
};