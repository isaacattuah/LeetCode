class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> deque;

    for (int i = 0; i < nums.size(); ++i) {
      while (!deque.empty() && nums[i] > deque.back()) deque.pop_back();
      deque.push_back(nums[i]);
      if (i - k + 1 >= 0) {
        ans.push_back(deque.front());
        if (nums[i - k + 1] == deque.front()) deque.pop_front();
      }
    }

    return ans;
  }
};