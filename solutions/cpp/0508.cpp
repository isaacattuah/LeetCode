class Solution {
 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> ans;
    unordered_map<int, int> count;
    int maxFreq = 0;

    dfs(root, count);

    for (auto&& [_, freq] : count) maxFreq = max(maxFreq, freq);

    for (auto&& [sum, freq] : count)
      if (freq == maxFreq) ans.push_back(sum);

    return ans;
  }

 private:
  int dfs(TreeNode* root, unordered_map<int, int>& count) {
    if (!root) return 0;

    int sum = root->val + dfs(root->left, count) + dfs(root->right, count);
    ++count[sum];

    return sum;
  }
};