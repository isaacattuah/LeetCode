class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        set_ = set(nums)

        for num in nums:
            if num - 1 not in set_:
                length = 0
                while num in set_:
                    num += 1
                    length += 1
                ans = max(ans, length)

        return ans
