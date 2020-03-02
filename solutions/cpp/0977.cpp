class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    int n = A.size();
    int l = 0;
    int r = n - 1;
    vector<int> ans(n);

    while (l <= r)
      ans[--n] = abs(A[l]) > abs(A[r]) ? A[l] * A[l++] : A[r] * A[r--];

    return ans;
  }
};