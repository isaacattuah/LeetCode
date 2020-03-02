class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    return subarrayWithAtMostKDistinct(A, K) -
           subarrayWithAtMostKDistinct(A, K - 1);
  }

 private:
  int subarrayWithAtMostKDistinct(vector<int>& A, int K) {
    int ans = 0;
    vector<int> count(A.size() + 1);

    for (int l = 0, r = 0; r <= A.size();) {
      if (K >= 0) {
        ans += r - l;
        if (r == A.size()) break;
        if (++count[A[r]] == 1) --K;
        ++r;
      } else {
        if (--count[A[l]] == 0) ++K;
        ++l;
      }
    }

    return ans;
  }
};