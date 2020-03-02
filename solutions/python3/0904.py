class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        ans = 0
        count = collections.Counter()

        j = 0
        for i, t in enumerate(tree):
            count[t] += 1
            while len(count) > 2:
                count[tree[j]] -= 1
                if count[tree[j]] == 0:
                    del count[tree[j]]
                j += 1
            ans = max(ans, i - j + 1)

        return ans
