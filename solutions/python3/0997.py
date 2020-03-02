class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        count = [0] * N

        for t in trust:
            count[t[0] - 1] -= 1
            count[t[1] - 1] += 1

        for i in range(len(count)):
            if count[i] == N - 1:
                return i + 1

        return -1
