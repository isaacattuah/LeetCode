class Solution {
 public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    unordered_map<string, vector<vector<string>>> map;
    unordered_set<string> ans;

    for (const string& transaction : transactions) {
      istringstream ss(transaction);
      vector<string> token(4, "");
      for (int i = 0; getline(ss, token[i++], ',');)
        ;
      if (stoi(token[2]) > 1000) ans.insert(transaction);
      for (const auto& val : map[token[0]])
        if (abs(stoi(val[1]) - stoi(token[1])) <= 60 && val[3] != token[3]) {
          ans.insert(transaction);
          ans.insert(val[0] + "," + val[1] + "," + val[2] + "," + val[3]);
        }
      map[token[0]].push_back({token[0], token[1], token[2], token[3]});
    }

    return {begin(ans), end(ans)};
  }
};