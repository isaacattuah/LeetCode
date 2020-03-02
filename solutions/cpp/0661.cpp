class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    const int m = M.size();
    const int n = M[0].size();

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int ones = 0;
        int count = 0;
        for (int y = max(0, i - 1); y < min(m, i + 2); ++y)
          for (int x = max(0, j - 1); x < min(n, j + 2); ++x) {
            ones += M[y][x];
            ++count;
          }
        ans[i][j] = ones / count;
      }

    return ans;
  }
};