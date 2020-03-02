class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));

    int l = 0;
    int r = nums.back() - nums.front();

    while (l < r) {
      int m = l + (r - l) / 2;
      int count = 0;

      for (int i = 0, j = 0; i < nums.size(); ++i) {
        while (j < nums.size() && nums[j] <= nums[i] + m) ++j;
        count += j - i - 1;
      }

      if (count < k)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};