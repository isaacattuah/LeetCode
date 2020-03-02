class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        min = float('inf')
        secondMin = float('inf')
        max_ = float('-inf')
        secondMax = float('-inf')
        thirdMax = float('-inf')

        for num in nums:
            if num <= min:
                secondMin = min
                min = num
            elif num <= secondMin:
                secondMin = num

            if num >= max_:
                thirdMax = secondMax
                secondMax = max_
                max_ = num
            elif num >= secondMax:
                thirdMax = secondMax
                secondMax = num
            elif num >= thirdMax:
                thirdMax = num

        return max(min * secondMin * max_, max_ * secondMax * thirdMax)
