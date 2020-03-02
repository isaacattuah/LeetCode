class Solution {
  public int totalFruit(int[] tree) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int i = 0, j = 0; i < tree.length; ++i) {
      count.put(tree[i], count.getOrDefault(tree[i], 0) + 1);
      while (count.size() > 2) {
        count.put(tree[j], count.get(tree[j]) - 1);
        count.remove(tree[j], 0);
        ++j;
      }
      ans = Math.max(ans, i - j + 1);
    }

    return ans;
  }
}