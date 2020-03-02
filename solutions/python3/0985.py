class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        sum_ = sum(a for a in A if a % 2 == 0)

        for query in queries:
            if A[query[1]] % 2 == 0:
                sum_ -= A[query[1]]
            A[query[1]] += query[0]
            if A[query[1]] % 2 == 0:
                sum_ += A[query[1]]
            ans.append(sum_)

        return ans
