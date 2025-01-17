class Solution {
  public int[][] diagonalSort(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;

    Map<Integer, PriorityQueue<Integer>> count = new HashMap<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        count.putIfAbsent(i - j, new PriorityQueue<>());
        count.get(i - j).add(mat[i][j]);
      }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        mat[i][j] = count.get(i - j).poll();

    return mat;
  }
}