class Solution {
 public:
  int trap(vector<int>& height) {
    int ans = 0;
    int l = 0;
    int r = height.size() - 1;
    int maxLeft = 0;
    int maxRight = 0;

    while (l < r) {
      if (height[l] < height[r]) {
        maxLeft = max(maxLeft, height[l]);
        ans += maxLeft - height[l];
        ++l;
      } else {
        maxRight = max(maxRight, height[r]);
        ans += maxRight - height[r];
        --r;
      }
    }

    return ans;
  }
};