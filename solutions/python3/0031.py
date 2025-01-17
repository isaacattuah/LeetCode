class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        i = len(nums) - 2
        while i >= 0:
            if nums[i] < nums[i + 1]:
                break
            i -= 1

        if i >= 0:
            for j in range(len(nums) - 1, -1, -1):
                if nums[j] > nums[i]:
                    break
            nums[i], nums[j] = nums[j], nums[i]

        self.reverse(nums, i + 1, len(nums) - 1)

    def reverse(self, nums: List[int], l: int, r: int):
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
