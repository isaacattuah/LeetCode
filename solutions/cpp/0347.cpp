class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    vector<vector<int>> bucket(nums.size() + 1);
    unordered_map<int, int> count;

    for (int num : nums) ++count[num];

    for (const auto& [num, freq] : count) bucket[freq].push_back(num);

    for (int freq = bucket.size() - 1; freq >= 0; --freq) {
      for (int num : bucket[freq]) ans.push_back(num);
      if (ans.size() == k) return ans;
    }

    throw;
  }
};