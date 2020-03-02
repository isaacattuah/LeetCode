class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;

    int ans = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) map[nums[i]] = i;

    for (int i = 0; i < nums.size(); ++i) {
      int target = nums[i] + k;
      if (map.count(target) && map[target] != i) {
        ++ans;
        map.erase(target);
      }
    }

    return ans;
  }
};