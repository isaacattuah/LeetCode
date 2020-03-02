class Solution {
  public String minWindow(String s, String t) {
    int required = t.length();
    int bestLeft = 0;
    int minLength = Integer.MAX_VALUE;
    int[] count = new int[128];

    for (char c : t.toCharArray())
      ++count[c];

    for (int l = 0, r = 0; r <= s.length();) {
      if (required > 0) {
        if (r == s.length())
          break;
        if (--count[s.charAt(r)] >= 0)
          --required;
        ++r;
      } else {
        if (r - l < minLength) {
          bestLeft = l;
          minLength = r - l;
        }
        if (++count[s.charAt(l)] > 0)
          ++required;
        ++l;
      }
    }

    return minLength == Integer.MAX_VALUE ? "" : s.substring(bestLeft, bestLeft + minLength);
  }
}