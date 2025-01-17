class Solution {
 public:
  bool isHappy(int n) {
    int slow = helper(n);
    int fast = helper(helper(n));

    while (slow != fast) {
      slow = helper(slow);
      fast = helper(helper(fast));
    }

    return slow == 1;
  }

 private:
  int helper(int n) {
    int sum = 0;

    while (n) {
      sum += pow(n % 10, 2);
      n /= 10;
    }

    return sum;
  }
};