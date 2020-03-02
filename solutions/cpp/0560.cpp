class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    int prefixSum = 0;
    unordered_map<int, int> count{{0, 1}};

    for (int num : nums) {
      prefixSum += num;
      ans += count[prefixSum - k];
      ++count[prefixSum];
    }

    return ans;
  }
};