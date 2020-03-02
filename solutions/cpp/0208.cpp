class Trie {
 public:
  void insert(string word) {
    TrieNode* node = &root;
    for (char c : word) {
      TrieNode*& next = node->children[c - 'a'];
      if (!next) next = new TrieNode;
      node = next;
    }
    node->isWord = true;
  }

  bool search(string word) {
    TrieNode* node = find(word);
    return node && node->isWord;
  }

  bool startsWith(string prefix) { return find(prefix); }

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

  TrieNode* find(string& prefix) {
    TrieNode* node = &root;
    for (char c : prefix) {
      TrieNode*& next = node->children[c - 'a'];
      if (!next) return nullptr;
      node = next;
    }
    return node;
  }
};