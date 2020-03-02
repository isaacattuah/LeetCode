class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        lastSeen = {}

        j = 0
        for i, c in enumerate(s):
            if c in lastSeen:
                j = max(j, lastSeen[c] + 1)
            ans = max(ans, i - j + 1)
            lastSeen[c] = i

        return ans
