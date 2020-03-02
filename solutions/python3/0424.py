class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        maxFreq = 0
        count = collections.defaultdict(int)
        l = 0
        r = 0

        while r <= len(s):
            if r - l - maxFreq <= k:
                ans = max(ans, r - l)
                if r == len(s):
                    break
                count[s[r]] += 1
                maxFreq = max(maxFreq, count[s[r]])
                r += 1
            else:
                count[s[l]] -= 1
                l += 1

        return ans
