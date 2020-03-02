class Solution {
  public int smallestRepunitDivByK(int K) {
    if (K % 10 != 1 && K % 10 != 3 && K % 10 != 7 && K % 10 != 9)
      return -1;

    Set<Integer> set = new HashSet<>();
    int mod = 0;

    for (int N = 1; N <= K; ++N) {
      mod = (mod * 10 + 1) % K;
      if (mod == 0)
        return N;
      if (set.contains(mod))
        return -1;
      set.add(mod);
    }

    return -1;
  }
}