class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> ans;

    auto it = begin(intervals);
    for (; it != end(intervals); ++it)
      if ((*it)[0] >= newInterval[0]) break;
    intervals.insert(it, newInterval);

    for (vector<int>& interval : intervals) {
      if (ans.empty() || interval[0] > ans.back()[1])
        ans.push_back(interval);
      else
        ans.back()[1] = max(ans.back()[1], interval[1]);
    }

    return ans;
  }
};