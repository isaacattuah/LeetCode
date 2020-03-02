class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> ans;

    for (int i = 0; i < input.size(); ++i)
      if (ispunct(input[i])) {
        vector<int> left = diffWaysToCompute(input.substr(0, i));
        vector<int> right = diffWaysToCompute(input.substr(i + 1));
        for (int a : left)
          for (int b : right)
            ans.push_back(input[i] == '+' ? a + b
                                          : input[i] == '-' ? a - b : a * b);
      }

    return ans.empty() ? vector<int>{stoi(input)} : ans;
  }
};