class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        satisfied = 0
        madeSatisfied = 0
        windowSatisfied = 0

        for i in range(len(customers)):
            if grumpy[i] == 0:
                satisfied += customers[i]
            else:
                windowSatisfied += customers[i]
            if i >= X and grumpy[i - X] == 1:
                windowSatisfied -= customers[i - X]
            madeSatisfied = max(madeSatisfied, windowSatisfied)

        return satisfied + madeSatisfied
