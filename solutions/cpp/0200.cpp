class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    const int m = grid.size();
    const int n = grid[0].size();

    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (!visited[i][j] && grid[i][j] == '1') {
          ++ans;
          dfs(grid, i, j, visited);
        }

    return ans;
  }

 private:
  void dfs(vector<vector<char>>& grid, int i, int j,
           vector<vector<bool>>& visited) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        visited[i][j] || grid[i][j] == '0')
      return;

    visited[i][j] = true;

    dfs(grid, i + 1, j, visited);
    dfs(grid, i - 1, j, visited);
    dfs(grid, i, j + 1, visited);
    dfs(grid, i, j - 1, visited);
  }
};