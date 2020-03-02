class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    int prevMin = nums[0];
    int prevMax = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      int min = prevMin * nums[i];
      int max = prevMax * nums[i];
      prevMin = std::min(nums[i], std::min(min, max));
      prevMax = std::max(nums[i], std::max(min, max));
      ans = std::max(ans, prevMax);
    }

    return ans;
  }
};