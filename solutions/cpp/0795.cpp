class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int ans = 0;
    int l = -1;
    int r = -1;

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] > R) l = i;
      if (A[i] >= L) r = i;
      ans += r - l;
    }

    return ans;
  }
};