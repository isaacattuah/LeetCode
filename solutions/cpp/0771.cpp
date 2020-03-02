class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    int ans = 0;
    unordered_set<char> jewels;

    for (char j : J) jewels.insert(j);

    for (char s : S)
      if (jewels.count(s)) ++ans;

    return ans;
  }
};