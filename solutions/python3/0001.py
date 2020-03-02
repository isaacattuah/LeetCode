class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}

        for i, num in enumerate(nums):
            if num in dict:
                return dict[num], i
            dict[target - num] = i
