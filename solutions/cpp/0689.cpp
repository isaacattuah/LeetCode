class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<int> ans = {-1, -1, -1};
    int subarrayCount = nums.size() - k + 1;
    vector<int> dp(subarrayCount);
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (i >= k) sum -= nums[i - k];
      if (i >= k - 1) dp[i - k + 1] = sum;
    }

    vector<int> left(subarrayCount);
    int maxIndex = 0;

    for (int i = 0; i < subarrayCount; ++i) {
      if (dp[i] > dp[maxIndex]) maxIndex = i;
      left[i] = maxIndex;
    }

    vector<int> right(subarrayCount);
    maxIndex = subarrayCount - 1;

    for (int i = subarrayCount - 1; i >= 0; --i) {
      if (dp[i] >= dp[maxIndex]) maxIndex = i;
      right[i] = maxIndex;
    }

    for (int i = k; i < subarrayCount - k; ++i)
      if (ans[0] == -1 || dp[left[i - k]] + dp[i] + dp[right[i + k]] >
                              dp[ans[0]] + dp[ans[1]] + dp[ans[2]])
        ans = {left[i - k], i, right[i + k]};

    return ans;
  }
};