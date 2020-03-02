class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans;

    for (ans = 0; n != 0; ++ans) n &= n - 1;

    return ans;
  }
};