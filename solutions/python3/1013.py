class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum_ = sum(A)
        prefixSum = 0
        parts = 1

        for a in A:
            prefixSum += a
            if prefixSum == sum_ * parts // 3:
                parts += 1

        return sum_ % 3 == 0 and parts >= 3
