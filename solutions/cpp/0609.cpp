class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> files;

    for (const string& path : paths) {
      stringstream ss(path);
      string root;
      string s;
      getline(ss, root, ' ');
      while (getline(ss, s, ' ')) {
        string filePath = root + '/' + s.substr(0, s.find('('));
        string fileContent =
            s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
        files[fileContent].push_back(filePath);
      }
    }

    for (const auto& [_, filePath] : files)
      if (filePath.size() > 1) ans.push_back(filePath);

    return ans;
  }
};