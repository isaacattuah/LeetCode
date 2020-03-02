class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int l = matrix[0][0];
    int r = matrix.back().back();

    while (l < r) {
      int m = (l + r) >> 1;
      int count = 0;
      for (const auto& row : matrix)
        count += upper_bound(begin(row), end(row), m) - begin(row);
      if (count >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};