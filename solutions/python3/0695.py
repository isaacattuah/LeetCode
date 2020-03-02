class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            if not 0 <= i < len(grid) or not 0 <= j < len(grid[0]) or visited[i][j] or grid[i][j] == 0:
                return 0

            visited[i][j] = True

            return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1)

        m = len(grid)
        n = len(grid[0])

        ans = 0
        visited = [[False] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if not visited[i][j]:
                    ans = max(ans, dfs(i, j))

        return ans
