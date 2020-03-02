class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    const int n = A.size();

    vector<int> ans = {0, 1};
    double l = 0;
    double r = 1;

    while (true) {
      double m = (l + r) / 2;
      ans[0] = 0;
      int count = 0;
      int j = 1;

      for (int i = 0; i < n; ++i) {
        while (j < n && A[i] > m * A[j]) ++j;
        count += n - j;
        if (j == n) break;
        if (ans[0] * A[j] < ans[1] * A[i]) {
          ans[0] = A[i];
          ans[1] = A[j];
        }
      }

      if (count < K)
        l = m;
      else if (count > K)
        r = m;
      else
        return ans;
    }
  }
};