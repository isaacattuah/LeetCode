class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> seen;

    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        string c(1, board[i][j]);
        if (c == ".") continue;
        if (!seen.insert(c + " in row " + to_string(i)).second ||
            !seen.insert(c + " in col " + to_string(j)).second ||
            !seen.insert(c + " in box " + to_string(i / 3) + to_string(j / 3))
                 .second)
          return false;
      }

    return true;
  }
};