class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); ++i) map[inorder[i]] = i;

    return helper(inorder, 0, inorder.size() - 1, postorder, 0,
                  postorder.size() - 1, map);
  }

  TreeNode* helper(vector<int>& inorder, int iLeft, int iRight,
                   vector<int>& postorder, int pLeft, int pRight,
                   unordered_map<int, int>& map) {
    if (iLeft > iRight || pLeft > pRight) return nullptr;

    int i = map[postorder[pRight]];
    TreeNode* curr = new TreeNode(postorder[pRight]);
    curr->left = helper(inorder, iLeft, i - 1, postorder, pLeft,
                        pLeft + i - iLeft - 1, map);
    curr->right = helper(inorder, i + 1, iRight, postorder, pLeft + i - iLeft,
                         pRight - 1, map);

    return curr;
  }
};