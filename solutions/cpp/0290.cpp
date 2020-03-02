class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    const int n = pattern.length();

    vector<int> charMap(26);
    unordered_map<string, int> strMap;
    istringstream iss(str);

    int i = 0;
    for (string word; iss >> word; ++i) {
      if (i == n || charMap[pattern[i] - 'a'] != strMap[word]) return false;
      charMap[pattern[i] - 'a'] = i + 1;
      strMap[word] = i + 1;
    }

    return i == n;
  }
};