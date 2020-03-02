class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> numCounts;
    for (int d : deck) ++numCounts[d];

    int gcd = 0;
    for (const auto& [_, value] : numCounts) gcd = __gcd(gcd, value);

    return gcd >= 2;
  }
};