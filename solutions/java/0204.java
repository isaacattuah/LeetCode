class Solution {
  public int countPrimes(int n) {
    if (n <= 2)
      return 0;

    int ans = 0;
    boolean[] prime = new boolean[n];
    Arrays.fill(prime, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 0; i < Math.sqrt(n); ++i)
      if (prime[i])
        for (int j = i * 2; j < n; j += i)
          prime[j] = false;

    for (boolean p : prime)
      if (p)
        ++ans;

    return ans;
  }
}