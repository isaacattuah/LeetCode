class Solution:
    def minWindow(self, s: str, t: str) -> str:
        required = len(t)
        bestLeft = 0
        minLength = float('inf')
        count = collections.Counter(t)
        l = 0
        r = 0

        while r <= len(s):
            if required > 0:
                if r == len(s):
                    break
                count[s[r]] -= 1
                if count[s[r]] >= 0:
                    required -= 1
                r += 1
            else:
                if r - l < minLength:
                    bestLeft = l
                    minLength = r - l
                count[s[l]] += 1
                if count[s[l]] > 0:
                    required += 1
                l += 1

        return "" if minLength == float('inf') else s[bestLeft:bestLeft + minLength]
