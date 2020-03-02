class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<string> path;

    dfs(s, 0, path, ans);

    return ans;
  }

 private:
  void dfs(const string& s, int index, vector<string>& path,
           vector<string>& ans) {
    if (path.size() == 4 && index == s.length()) {
      ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
      return;
    }
    if (path.size() == 4 || index == s.length()) return;

    for (int i = 1; i <= 3; ++i) {
      if (index + i > s.length()) return;
      if (i > 1 && s[index] == '0') return;
      string num = s.substr(index, i);
      if (stoi(num) > 255) return;
      path.push_back(num);
      dfs(s, index + i, path, ans);
      path.pop_back();
    }
  }
};