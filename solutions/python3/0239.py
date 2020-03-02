class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        deque = collections.deque()

        for i in range(len(nums)):
            while deque and nums[i] > deque[-1]:
                deque.pop()
            deque.append(nums[i])
            if i - k + 1 >= 0:
                ans.append(deque[0])
                if nums[i - k + 1] == deque[0]:
                    deque.popleft()

        return ans
