class Solution {
  public List<Integer> findAnagrams(String s, String p) {
    List<Integer> ans = new ArrayList<>();
    int[] count = new int[26];
    int required = p.length();

    for (char c : p.toCharArray())
      ++count[c - 'a'];

    for (int l = 0, r = 0; r <= s.length();) {
      if (required > 0) {
        if (r == s.length())
          break;
        if (--count[s.charAt(r) - 'a'] >= 0)
          --required;
        ++r;
      } else {
        if (r - l == p.length())
          ans.add(l);
        if (++count[s.charAt(l) - 'a'] > 0)
          ++required;
        ++l;
      }
    }

    return ans;
  }
}