class Solution {
  public int maxAreaOfIsland(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;

    int ans = 0;
    boolean[][] visited = new boolean[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = Math.max(ans, dfs(grid, i, j, visited));

    return ans;
  }

  private int dfs(int[][] grid, int i, int j, boolean[][] visited) {
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || visited[i][j] == true || grid[i][j] == 0)
      return 0;

    visited[i][j] = true;

    return 1 + dfs(grid, i + 1, j, visited) + dfs(grid, i - 1, j, visited) + dfs(grid, i, j + 1, visited)
        + dfs(grid, i, j - 1, visited);
  }
}