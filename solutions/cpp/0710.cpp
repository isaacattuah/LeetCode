class Solution {
 public:
  Solution(int N, vector<int>& blacklist) {
    validRange = N - blacklist.size();

    for (int b : blacklist) map[b] = -1;

    for (int b : blacklist)
      if (b < validRange) {
        while (map.count(N - 1)) --N;
        map[b] = --N;
      }
  }

  int pick() {
    int value = rand() % validRange;

    if (map.count(value)) return map[value];

    return value;
  }

 private:
  int validRange;
  unordered_map<int, int> map;
};