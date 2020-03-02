class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); ++i) map[inorder[i]] = i;

    return helper(preorder, 0, preorder.size() - 1, inorder, 0,
                  inorder.size() - 1, map);
  }

  TreeNode* helper(vector<int>& preorder, int pLeft, int pRight,
                   vector<int>& inorder, int iLeft, int iRight,
                   unordered_map<int, int>& map) {
    if (pLeft > pRight || iLeft > iRight) return nullptr;

    int i = map[preorder[pLeft]];
    TreeNode* curr = new TreeNode(preorder[pLeft]);
    curr->left = helper(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft,
                        i - 1, map);
    curr->right = helper(preorder, pLeft + i - iLeft + 1, pRight, inorder,
                         i + 1, iRight, map);

    return curr;
  }
};