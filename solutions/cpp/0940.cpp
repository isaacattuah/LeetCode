class Solution {
 public:
  int distinctSubseqII(string S) {
    vector<long> map(26);

    for (char c : S)
      map[c - 'a'] = accumulate(begin(map), end(map), 1L) % int(1e9 + 7);

    return accumulate(begin(map), end(map), 0L) % int(1e9 + 7);
  }
};