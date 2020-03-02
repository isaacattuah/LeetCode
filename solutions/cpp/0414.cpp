class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    auto compare = [](const int a, const int b) { return a > b; };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);
    unordered_set<int> seen;

    for (int num : nums)
      if (!seen.count(num)) {
        seen.insert(num);
        pq.push(num);
        if (pq.size() > 3) pq.pop();
      }

    if (pq.size() == 2) pq.pop();

    return pq.top();
  }
};