class Solution {
 public:
  string longestWord(vector<string>& words) {
    for (const string& word : words) insert(word);

    return dfs(&root);
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

  string dfs(TrieNode* node) {
    string ans = node->word ? *node->word : "";

    for (TrieNode* child : node->children)
      if (child && child->word && child->word->length() > 0) {
        string childWord = dfs(child);
        if (childWord.length() > ans.length()) ans = childWord;
      }

    return ans;
  }
};