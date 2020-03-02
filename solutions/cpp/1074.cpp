class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    int ans = 0;

    for (vector<int>& row : matrix)
      for (int j = 1; j < row.size(); ++j) row[j] += row[j - 1];

    for (int col = 0; col < n; ++col)
      for (int j = col; j < n; ++j) {
        unordered_map<int, int> count;
        count[0] = 1;
        int sum = 0;
        for (int i = 0; i < m; ++i) {
          sum += matrix[i][j] - (col > 0 ? matrix[i][col - 1] : 0);
          ans += count[sum - target];
          ++count[sum];
        }
      }

    return ans;
  }
};