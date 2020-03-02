class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        def dfs(root: TreeNode, level: int) -> None:
            if not root:
                return
            if level > len(ans):
                ans.append(root.val)

            dfs(root.right, level + 1)
            dfs(root.left, level + 1)

        ans = []

        dfs(root, 1)

        return ans
