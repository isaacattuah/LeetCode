class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int sum = 0;

    for (int num : nums) {
      if (num == 0)
        sum = 0;
      else {
        sum += num;
        ans = max(ans, sum);
      }
    }

    return ans;
  }
};