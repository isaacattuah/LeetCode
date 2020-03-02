class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans = 0;

    for (vector<int>& p1 : points) {
      unordered_map<int, int> count;
      for (vector<int>& p2 : points)
        ans += 2 * count[pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)]++;
    }

    return ans;
  }
};