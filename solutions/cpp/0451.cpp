class Solution {
 public:
  string frequencySort(string s) {
    string ans;
    vector<vector<char>> bucket(s.length() + 1);
    vector<int> count(128);

    for (char c : s) ++count[c];

    for (int i = 0; i < count.size(); ++i) {
      int freq = count[i];
      if (freq > 0) bucket[freq].push_back((char)i);
    }

    for (int freq = bucket.size() - 1; freq >= 0; --freq)
      for (char c : bucket[freq])
        for (int i = 0; i < freq; ++i) ans += c;

    return ans;
  }
};