class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        def subarraysWithAtMostKDistinct(k: int) -> int:
            ans = 0
            count = [0] * (len(A) + 1)
            l = 0
            r = 0

            while r <= len(A):
                if k >= 0:
                    ans += r - l
                    if r == len(A):
                        break
                    count[A[r]] += 1
                    if count[A[r]] == 1:
                        k -= 1
                    r += 1
                else:
                    count[A[l]] -= 1
                    if count[A[l]] == 0:
                        k += 1
                    l += 1

            return ans

        return subarraysWithAtMostKDistinct(K) - subarraysWithAtMostKDistinct(K - 1)
