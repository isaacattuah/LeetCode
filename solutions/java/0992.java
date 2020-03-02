class Solution {
  public int subarraysWithKDistinct(int[] A, int K) {
    return subarraysWithAtMostKDistinct(A, K) - subarraysWithAtMostKDistinct(A, K - 1);
  }

  private int subarraysWithAtMostKDistinct(int[] A, int K) {
    int ans = 0;
    int[] count = new int[A.length + 1];

    for (int l = 0, r = 0; r <= A.length;) {
      if (K >= 0) {
        ans += r - l;
        if (r == A.length)
          break;
        if (++count[A[r]] == 1)
          --K;
        ++r;
      } else {
        if (--count[A[l]] == 0)
          ++K;
        ++l;
      }
    }

    return ans;
  }
}