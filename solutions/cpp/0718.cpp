class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int ans = 0;
    vector<int> dp(B.size() + 1);

    for (int i = A.size() - 1; i >= 0; --i)
      for (int j = 0; j < B.size(); ++j) {
        dp[j] = A[i] == B[j] ? dp[j + 1] + 1 : 0;
        ans = max(ans, dp[j]);
      }

    return ans;
  }
};