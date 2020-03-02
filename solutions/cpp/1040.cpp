class Solution {
 public:
  vector<int> numMovesStonesII(vector<int>& stones) {
    const int n = stones.size();

    int minMoves = n;

    sort(begin(stones), end(stones));

    for (int i = 0, j = 0; j < n; j++) {
      while (stones[j] - stones[i] + 1 > n) ++i;
      int stored = j - i + 1;
      if (stored == n - 1 && stones[j] - stones[i] + 1 == n - 1)
        minMoves = 2;
      else
        minMoves = min(minMoves, n - stored);
    }

    return {minMoves, max(stones[n - 1] - stones[1] - n + 2,
                          stones[n - 2] - stones[0] - n + 2)};
  }
};