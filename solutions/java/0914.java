class Solution {
  public boolean hasGroupsSizeX(int[] deck) {
    Map<Integer, Integer> numCounts = new HashMap<>();
    for (int d : deck)
      numCounts.put(d, numCounts.getOrDefault(d, 0) + 1);

    int gcd = 0;
    for (int value : numCounts.values())
      gcd = __gcd(gcd, value);

    return gcd >= 2;
  }

  private int __gcd(int a, int b) {
    return b > 0 ? __gcd(b, a % b) : a;
  }
}