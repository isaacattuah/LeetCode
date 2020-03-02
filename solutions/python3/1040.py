class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        n = len(stones)

        minMoves = n

        stones.sort()

        i = 0
        for j in range(n):
            while stones[j] - stones[i] + 1 > n:
                i += 1
            stored = j - i + 1
            if stored == n - 1 and stones[j] - stones[i] + 1 == n - 1:
                minMoves = 2
            else:
                minMoves = min(minMoves, n - stored)

        return [minMoves, max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2)]
