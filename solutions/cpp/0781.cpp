class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    int ans = 0;
    vector<int> count(1000);

    for (int answer : answers) {
      if (count[answer] % (answer + 1) == 0) ans += answer + 1;
      ++count[answer];
    }

    return ans;
  }
};