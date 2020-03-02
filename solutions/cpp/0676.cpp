class MagicDictionary {
 public:
  void buildDict(vector<string> dict) {
    for (const string& word : dict)
      for (int i = 0; i < word.length(); ++i) {
        string modifiedWord = word.substr(0, i) + '*' + word.substr(i + 1);
        if (!map.count(modifiedWord))
          map[modifiedWord] = word[i];
        else if (map[modifiedWord] != word[i])
          map[modifiedWord] = '*';
      }
  }

  bool search(string word) {
    for (int i = 0; i < word.length(); ++i) {
      string modifiedWord = word.substr(0, i) + '*' + word.substr(i + 1);
      if (map.count(modifiedWord) && map[modifiedWord] != word[i]) return true;
    }

    return false;
  }

 private:
  unordered_map<string, char> map;
};