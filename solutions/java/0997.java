class Solution {
  public int findJudge(int N, int[][] trust) {
    int[] count = new int[N];

    for (int[] t : trust) {
      --count[t[0] - 1];
      ++count[t[1] - 1];
    }

    for (int i = 0; i < N; ++i)
      if (count[i] == N - 1)
        return i + 1;

    return -1;
  }
}