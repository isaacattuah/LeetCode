class Solution {
 public:
  int totalFruit(vector<int>& tree) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int i = 0, j = 0; i < tree.size(); ++i) {
      ++count[tree[i]];
      while (count.size() > 2) {
        if (--count[tree[j]] == 0) count.erase(tree[j]);
        ++j;
      }
      ans = max(ans, i - j + 1);
    }

    return ans;
  }
};