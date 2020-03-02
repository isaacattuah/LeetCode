class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(iLeft: int, iRight: int, pLeft: int, pRight: int) -> TreeNode:
            if iLeft > iRight or pLeft > pRight:
                return None

            i = dict[postorder[pRight]]
            curr = TreeNode(postorder[pRight])
            curr.left = helper(iLeft, i - 1, pLeft, pLeft + i - iLeft - 1)
            curr.right = helper(i + 1, iRight, pLeft + i - iLeft, pRight - 1)

            return curr

        dict = {val: i for i, val in enumerate(inorder)}

        return helper(0, len(inorder) - 1, 0, len(postorder) - 1)
