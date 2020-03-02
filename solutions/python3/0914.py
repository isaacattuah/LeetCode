from functools import reduce


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(a, b):
            return gcd(b, a % b) if b > 0 else a

        numCounts = collections.Counter(deck)

        return reduce(gcd, numCounts.values()) >= 2
