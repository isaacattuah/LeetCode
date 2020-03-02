class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;

    for (const string& word : words) insert(word);

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j) dfs(board, i, j, &root, ans);

    return ans;
  }

 private:
  struct TrieNode {
    TrieNode() : children(26), word(nullptr) {}
    ~TrieNode() {
      for (TrieNode* child : children) delete (child);
    }

    vector<TrieNode*> children;
    const string* word;
  };

  TrieNode root;

  void insert(const string& word) {
    TrieNode* node = &root;
    for (char c : word) {
      TrieNode*& next = node->children[c - 'a'];
      if (!next) next = new TrieNode;
      node = next;
    }
    node->word = &word;
  }

  void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
           vector<string>& ans) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] == '*')
      return;

    char c = board[i][j];
    TrieNode* next = node->children[c - 'a'];
    if (!next) return;
    if (next->word) {
      ans.push_back(*next->word);
      next->word = nullptr;
    }

    board[i][j] = '*';
    dfs(board, i + 1, j, next, ans);
    dfs(board, i - 1, j, next, ans);
    dfs(board, i, j + 1, next, ans);
    dfs(board, i, j - 1, next, ans);
    board[i][j] = c;
  }
};