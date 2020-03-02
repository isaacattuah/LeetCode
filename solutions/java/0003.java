class Solution {
  public int lengthOfLongestSubstring(String s) {
    int ans = 0;
    Map<Character, Integer> lastSeen = new HashMap<>();

    for (int i = 0, j = 0; i < s.length(); ++i) {
      char c = s.charAt(i);
      if (lastSeen.containsKey(c))
        j = Math.max(j, lastSeen.get(c) + 1);
      ans = Math.max(ans, i - j + 1);
      lastSeen.put(c, i);
    }

    return ans;
  }
}