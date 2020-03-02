class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    int maxFreq = 0;
    unordered_map<int, int> count;

    for (vector<int>& row : wall) {
      int prefixSum = 0;
      for (int i = 0; i < row.size() - 1; ++i) {
        prefixSum += row[i];
        maxFreq = max(maxFreq, ++count[prefixSum]);
      }
    }

    return wall.size() - maxFreq;
  }
};