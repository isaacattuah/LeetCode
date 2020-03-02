class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        required = len(p)
        count = collections.Counter(p)
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
                if r - l == len(p):
                    ans.append(l)
                count[s[l]] += 1
                if count[s[l]] > 0:
                    required += 1
                l += 1

        return ans
