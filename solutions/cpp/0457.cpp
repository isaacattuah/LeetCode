class Solution {
 public:
  bool circularArrayLoop(vector<int>& nums) {
    if (nums.size() < 2) return false;

    function<int(int)> advance = [&](int i) {
      const int n = nums.size();
      int val = (i + nums[i]) % n;
      return i + nums[i] >= 0 ? val : n + val;
    };

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) continue;

      int slow = i;
      int fast = advance(slow);
      while (nums[i] * nums[fast] > 0 && nums[i] * nums[advance(fast)] > 0) {
        if (slow == fast) {
          if (slow == advance(slow)) break;
          return true;
        }
        slow = advance(slow);
        fast = advance(advance(fast));
      }

      slow = i;
      int sign = nums[i];
      while (sign * nums[slow] > 0) {
        int next = advance(slow);
        nums[slow] = 0;
        slow = next;
      }
    }

    return false;
  }
};