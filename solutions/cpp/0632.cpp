class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    auto compare = [](const Elem& a, const Elem& b) {
      return a.value > b.value;
    };
    priority_queue<Elem, vector<Elem>, decltype(compare)> pq(compare);

    int maxRange = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      pq.push(Elem(nums[i][0], i, 0));
      maxRange = max(maxRange, nums[i][0]);
    }
    int minRange = pq.top().value;

    vector<int> ans{minRange, maxRange};

    while (pq.size() == nums.size()) {
      auto [value, r, c] = pq.top();
      pq.pop();
      if (c + 1 < nums[r].size()) {
        pq.push(Elem(nums[r][c + 1], r, c + 1));
        maxRange = max(maxRange, nums[r][c + 1]);
        minRange = pq.top().value;
        if (maxRange - minRange < ans[1] - ans[0]) {
          ans[0] = minRange;
          ans[1] = maxRange;
        }
      }
    }

    return ans;
  }

 private:
  struct Elem {
    int value;
    int r;
    int c;

    Elem(int value, int r, int c) : value(value), r(r), c(c) {}
  };
};