class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    string ans;

    for (const string& word : dict) insert(word);

    stringstream ss(sentence);
    string s;
    while (getline(ss, s, ' ')) ans += ' ' + search(s);

    return ans.substr(1);
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

  string search(const string& word) {
    TrieNode* node = &root;
    for (char c : word) {
      if (node->word) return *node->word;
      TrieNode* next = node->children[c - 'a'];
      if (!next) return word;
      node = next;
    }
    return word;
  }
};