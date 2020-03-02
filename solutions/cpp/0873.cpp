class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& A) {
    const int n = A.size();

    int ans = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) map[A[i]] = i;
    vector<vector<int>> dp(n, vector<int>(n, 2));

    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        int ai = A[k] - A[j];
        if (ai < A[j] && map.count(ai)) {
          int i = map[ai];
          dp[j][k] = dp[i][j] + 1;
          ans = max(ans, dp[j][k]);
        }
      }

    return ans;
  }
};