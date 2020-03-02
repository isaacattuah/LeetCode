class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(pLeft: int, pRight: int, iLeft: int, iRight: int) -> TreeNode:
            if pLeft > pRight or iLeft > iRight:
                return None

            i = dict[preorder[pLeft]]
            curr = TreeNode(preorder[pLeft])
            curr.left = helper(pLeft + 1, pLeft + i - iLeft, iLeft, i - 1)
            curr.right = helper(pLeft + i - iLeft + 1, pRight, i + 1, iRight)

            return curr

        dict = {val: i for i, val in enumerate(inorder)}

        return helper(0, len(preorder) - 1, 0, len(inorder) - 1)
