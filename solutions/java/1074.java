class Solution {
  public int numSubmatrixSumTarget(int[][] matrix, int target) {
    final int m = matrix.length;
    final int n = matrix[0].length;

    int ans = 0;

    for (int[] row : matrix)
      for (int j = 1; j < row.length; ++j)
        row[j] += row[j - 1];

    for (int col = 0; col < n; ++col)
      for (int j = col; j < n; ++j) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int sum = 0;
        for (int i = 0; i < m; ++i) {
          sum += matrix[i][j] - (col > 0 ? matrix[i][col - 1] : 0);
          ans += count.getOrDefault(sum - target, 0);
          count.put(sum, count.getOrDefault(sum, 0) + 1);
        }
      }

    return ans;
  }
}