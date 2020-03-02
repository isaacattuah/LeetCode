class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;

    for (int num : nums) {
      int index = abs(num) - 1;
      nums[index] = -abs(nums[index]);
    }

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] > 0) ans.push_back(i + 1);

    return ans;
  }
};