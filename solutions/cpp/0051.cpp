class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<bool> cols(n);
    vector<bool> diag1(2 * n - 1);
    vector<bool> diag2(2 * n - 1);

    dfs(0, cols, diag1, diag2, board, ans);

    return ans;
  }

 private:
  void dfs(int i, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
           vector<string>& board, vector<vector<string>>& ans) {
    if (i == cols.size()) {
      ans.push_back(board);
      return;
    }

    for (int j = 0; j < cols.size(); ++j) {
      if (cols[j] || diag1[i + j] || diag2[j - i + cols.size() - 1]) continue;
      board[i][j] = 'Q';
      cols[j] = diag1[i + j] = diag2[j - i + cols.size() - 1] = true;
      dfs(i + 1, cols, diag1, diag2, board, ans);
      cols[j] = diag1[i + j] = diag2[j - i + cols.size() - 1] = false;
      board[i][j] = '.';
    }
  }
};