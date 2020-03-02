class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans = 0
        max_ = float('-inf')

        for i, a in enumerate(arr):
            max_ = max(max_, a)
            if max_ == i:
                ans += 1

        return ans
