class Solution {
  public int leastInterval(char[] tasks, int n) {
    int[] count = new int[26];
    for (char task : tasks)
      ++count[task - 'A'];

    int maxFreq = 0;
    for (int c : count)
      maxFreq = Math.max(maxFreq, c);

    int ans = (maxFreq - 1) * (n + 1);
    for (int c : count)
      if (c == maxFreq)
        ++ans;

    return Math.max(ans, tasks.length);
  }
}