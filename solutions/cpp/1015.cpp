class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    if (K % 10 != 1 && K % 10 != 3 && K % 10 != 7 && K % 10 != 9) return -1;

    unordered_set<int> set;
    int mod = 0;

    for (int N = 1; N <= K; ++N) {
      mod = (mod * 10 + 1) % K;
      if (mod == 0) return N;
      if (set.count(mod)) return -1;
      set.insert(mod);
    }

    return -1;
  }
};