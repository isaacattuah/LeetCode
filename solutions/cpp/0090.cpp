class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;

    sort(begin(nums), end(nums));
    dfs(nums, 0, path, ans);

    return ans;
  }

 private:
  void dfs(vector<int>& nums, int s, vector<int>& path,
           vector<vector<int>>& ans) {
    ans.push_back(path);
    if (s == nums.size()) return;

    for (int i = s; i < nums.size(); ++i) {
      if (i > s && nums[i] == nums[i - 1]) continue;
      path.push_back(nums[i]);
      dfs(nums, i + 1, path, ans);
      path.pop_back();
    }
  }
};