class Solution {
  public TreeNode buildTree(int[] inorder, int[] postorder) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < inorder.length; ++i)
      map.put(inorder[i], i);

    return helper(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1, map);
  }

  private TreeNode helper(int[] inorder, int iLeft, int iRight, int[] postorder, int pLeft, int pRight,
      Map<Integer, Integer> map) {
    if (iLeft > iRight || pLeft > pRight)
      return null;

    int i = map.get(postorder[pRight]);
    TreeNode curr = new TreeNode(postorder[pRight]);
    curr.left = helper(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1, map);
    curr.right = helper(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1, map);

    return curr;
  }
}