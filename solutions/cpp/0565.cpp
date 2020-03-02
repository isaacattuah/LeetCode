class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ans = 0;

    for (int num : nums) {
      if (num == -1) continue;
      int index = num;
      int count = 0;
      while (nums[index] != -1) {
        int temp = index;
        index = nums[index];
        nums[temp] = -1;
        ++count;
      }
      ans = max(ans, count);
    }

    return ans;
  }
};