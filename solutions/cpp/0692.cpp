class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> ans;
    vector<vector<string>> bucket(words.size() + 1);
    unordered_map<string, int> count;

    for (const string& word : words) ++count[word];

    for (const auto& [word, freq] : count) bucket[freq].push_back(word);

    for (int freq = bucket.size() - 1; freq >= 0; --freq) {
      sort(begin(bucket[freq]), end(bucket[freq]));
      for (const string& word : bucket[freq]) {
        ans.push_back(word);
        if (ans.size() == k) return ans;
      }
    }

    throw;
  }
};