class BSTIterator {
 public:
  BSTIterator(TreeNode* root) { helper(root); }

  int next() {
    TreeNode* node = stack.top();
    stack.pop();

    if (node->right) helper(node->right);

    return node->val;
  }

  bool hasNext() { return !stack.empty(); }

 private:
  std::stack<TreeNode*> stack;

  void helper(TreeNode* root) {
    while (root) {
      stack.push(root);
      root = root->left;
    }
  }
};