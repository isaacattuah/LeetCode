class Solution {
 public:
  bool isPowerOfTwo(int n) {
    return n < 0 ? false : bitset<32>(n).count() == 1;
  }
};