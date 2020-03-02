class Solution {
  public int characterReplacement(String s, int k) {
    int ans = 0;
    int maxFreq = 0;
    int[] count = new int[26];

    for (int l = 0, r = 0; r <= s.length();) {
      if (r - l - maxFreq <= k) {
        ans = Math.max(ans, r - l);
        if (r == s.length())
          break;
        maxFreq = Math.max(maxFreq, ++count[s.charAt(r) - 'A']);
        ++r;
      } else {
        --count[s.charAt(l) - 'A'];
        ++l;
      }
    }

    return ans;
  }
}