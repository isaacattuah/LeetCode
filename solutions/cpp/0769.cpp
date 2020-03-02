class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int ans = 0;
    int max = INT_MIN;

    for (int i = 0; i < arr.size(); ++i) {
      max = std::max(max, arr[i]);
      if (max == i) ++ans;
    }

    return ans;
  }
};