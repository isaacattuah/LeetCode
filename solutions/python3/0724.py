class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        sum_ = sum(nums)
        prefixSum = 0

        for i, num in enumerate(nums):
            if prefixSum == sum_ - prefixSum - num:
                return i
            prefixSum += num

        return -1
