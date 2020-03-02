class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        set_ = set(nums1)

        for num in nums2:
            if num in set_:
                ans.append(num)
                set_.remove(num)

        return ans
