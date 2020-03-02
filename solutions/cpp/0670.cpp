class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    unordered_map<char, int> map;

    for (int i = 0; i < s.length(); ++i) map[s[i]] = i;

    for (int i = 0; i < s.length(); ++i)
      for (char digit = '9'; digit > s[i]; --digit)
        if (map[digit] > i) {
          s[map[digit]] = s[i];
          s[i] = digit;
          return stoi(s);
        }

    return num;
  }
};