class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0

        m = len(matrix)
        n = len(matrix[0])

        dp = [0] * n
        max_ = 0
        prev = 0

        for i in range(m):
            for j in range(n):
                temp = dp[j]
                if i == 0 or j == 0 or matrix[i][j] == '0':
                    dp[j] = ord(matrix[i][j]) - ord('0')
                else:
                    dp[j] = min(dp[j], dp[j - 1], prev) + 1
                max_ = max(max_, dp[j])
                prev = temp

        return max_ * max_
