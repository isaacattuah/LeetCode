class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    vector<vector<int>> ans;
    short i = 0;
    short j = 0;

    while (i < A.size() && j < B.size()) {
      int start = max(A[i][0], B[j][0]);
      int end = min(A[i][1], B[j][1]);
      if (end >= start) ans.push_back({start, end});
      if (A[i][1] > B[j][1])
        ++j;
      else
        ++i;
    }

    return ans;
  }
};