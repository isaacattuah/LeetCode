class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    for (const string& word : words) insert(word);

    return dfs(S, 0, &root);
  }

 private:
  struct TrieNode {
    TrieNode() : children(26), count(0) {}
    ~TrieNode() {
      for (TrieNode* child : children) delete child;
    }

    vector<TrieNode*> children;
    int count;
  };

  void insert(const string& word) {
    TrieNode* node = &root;
    for (char c : word) {
      TrieNode*& next = node->children[c - 'a'];
      if (!next) next = new TrieNode;
      node = next;
    }
    ++node->count;
  }

  int dfs(const string& S, int s, TrieNode* node) {
    int ans = node->count;

    if (s >= S.length()) return ans;

    for (int i = 0; i < 26; ++i)
      if (node->children[i]) {
        int index = indexOf(S, i + 'a', s);
        if (index != -1) ans += dfs(S, index + 1, node->children[i]);
      }

    return ans;
  }

  int indexOf(const string& S, char c, int s) {
    for (int i = s; i < S.length(); ++i)
      if (S[i] == c) return i;
    return -1;
  }

  TrieNode root;
};