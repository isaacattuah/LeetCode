class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    const int n = digits.size();

    for (int i = n - 1; i >= 0; --i) {
      if (digits[i] < 9) {
        ++digits[i];
        return digits;
      }

      digits[i] = 0;
    }

    vector<int> ans(n + 1);
    ans[0] = 1;

    return ans;
  }
};