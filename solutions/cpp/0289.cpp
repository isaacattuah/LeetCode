class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    const int m = board.size();
    const int n = board[0].size();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int ones = 0;
        for (int y = max(0, i - 1); y < min(m, i + 2); ++y)
          for (int x = max(0, j - 1); x < min(n, j + 2); ++x)
            ones += board[y][x] & 1;
        if ((board[i][j] == 1 && (ones == 3 || ones == 4)) ||
            (board[i][j] == 0 && ones == 3))
          board[i][j] |= 0b10;
      }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) board[i][j] >>= 1;
  }
};