class Solution {
 public:
  int longestOnes(vector<int>& A, int K) {
    int i = 0;

    for (int a : A) {
      if (a == 0) --K;
      if (K < 0) {
        if (A[i] == 0) ++K;
        ++i;
      }
    }

    return A.size() - i;
  }
};