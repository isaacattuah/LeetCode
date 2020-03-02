class Solution {
  public int maximumSwap(int num) {
    char[] s = Integer.toString(num).toCharArray();
    int[] map = new int[10];

    for (int i = 0; i < s.length; ++i)
      map[s[i] - '0'] = i;

    for (int i = 0; i < s.length; ++i)
      for (int j = 9; j > s[i] - '0'; --j)
        if (map[j] > i) {
          s[map[j]] = s[i];
          s[i] = (char) ('0' + j);
          return Integer.valueOf(new String(s));
        }

    return num;
  }
}