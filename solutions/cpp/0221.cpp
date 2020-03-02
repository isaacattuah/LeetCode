class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    const int m = matrix.size();
    const int n = matrix[0].size();

    vector<int> dp(n);
    int max = 0;
    int prev = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int temp = dp[j];
        dp[j] = (i == 0 || j == 0 || matrix[i][j] == '0')
                    ? matrix[i][j] - '0'
                    : min(dp[j], min(dp[j - 1], prev)) + 1;
        max = std::max(max, dp[j]);
        prev = temp;
      }

    return max * max;
  }
};