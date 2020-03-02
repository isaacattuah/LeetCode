class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    vector<int> count(26);
    int required = p.length();

    for (char c : p) ++count[c - 'a'];

    for (int l = 0, r = 0; r <= s.length();) {
      if (required > 0) {
        if (r == s.length()) break;
        if (--count[s[r] - 'a'] >= 0) --required;
        ++r;
      } else {
        if (r - l == p.length()) ans.push_back(l);
        if (++count[s[l] - 'a'] > 0) ++required;
        ++l;
      }
    }

    return ans;
  }
};