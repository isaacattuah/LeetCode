class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    dfs(root, 1, ans);

    return ans;
  }

 private:
  void dfs(TreeNode* root, int level, vector<int>& ans) {
    if (!root) return;
    if (level > ans.size()) ans.push_back(root->val);

    dfs(root->right, level + 1, ans);
    dfs(root->left, level + 1, ans);
  }
};