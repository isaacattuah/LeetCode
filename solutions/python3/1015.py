class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 10 not in {1, 3, 7, 9}:
            return -1

        set_ = set()
        mod = 0

        for N in range(1, K + 1):
            mod = (mod * 10 + 1) % K
            if mod == 0:
                return N
            if mod in set_:
                return -1
            set_.add(mod)

        return -1
