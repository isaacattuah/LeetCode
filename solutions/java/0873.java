class Solution {
  public int lenLongestFibSubseq(int[] A) {
    final int n = A.length;

    int ans = 0;
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < n; ++i)
      map.put(A[i], i);
    int[][] dp = new int[n][n];
    for (int[] row : dp)
      Arrays.fill(row, 2);

    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        int ai = A[k] - A[j];
        if (ai < A[j] && map.containsKey(ai)) {
          int i = map.get(ai);
          dp[j][k] = dp[i][j] + 1;
          ans = Math.max(ans, dp[j][k]);
        }
      }

    return ans;
  }
}