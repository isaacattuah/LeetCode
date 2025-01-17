class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def dfs(s: int, path: List[int]) -> None:
            ans.append(path)
            if s == len(nums):
                return

            for i in range(s, len(nums)):
                dfs(i + 1, path + [nums[i]])

        ans = []

        dfs(0, [])

        return ans
