class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        prevMin = nums[0]
        prevMax = nums[0]

        for i in range(1, len(nums)):
            min_ = prevMin * nums[i]
            max_ = prevMax * nums[i]
            prevMin = min(nums[i], min_, max_)
            prevMax = max(nums[i], min_, max_)
            ans = max(ans, prevMax)

        return ans
