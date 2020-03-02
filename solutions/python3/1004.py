class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        i = 0

        for a in A:
            K -= 1 - a
            if K < 0:
                K += 1 - A[i]
                i += 1

        return len(A) - i
