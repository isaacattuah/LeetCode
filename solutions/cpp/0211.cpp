class WordDictionary {
 public:
  void addWord(string word) {
    TrieNode* node = &root;
    for (char c : word) {
      TrieNode*& next = node->children[c - 'a'];
      if (!next) next = new TrieNode;
      node = next;
    }
    node->isWord = true;
  }

  bool search(string word) { return dfs(word, 0, &root); }

 private:
  struct TrieNode {
    TrieNode() : children(26), isWord(false) {}
    ~TrieNode() {
      for (TrieNode* child : children) delete child;
    }

    vector<TrieNode*> children;
    bool isWord;
  };

  TrieNode root;

  bool dfs(const string& word, int depth, TrieNode* node) {
    if (depth == word.length()) return node->isWord;
    if (word[depth] != '.') {
      TrieNode* next = node->children[word[depth] - 'a'];
      return next ? dfs(word, depth + 1, next) : false;
    }

    for (int i = 0; i < 26; ++i)
      if (node->children[i] && dfs(word, depth + 1, node->children[i]))
        return true;

    return false;
  }
};