class Solution {
 public:
  string multiply(string num1, string num2) {
    const int m = num1.length();
    const int n = num2.length();

    string ans;
    vector<int> pos(m + n);

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        int multiply = (num1[i] - '0') * (num2[j] - '0');
        int sum = multiply + pos[i + j + 1];
        pos[i + j] += sum / 10;
        pos[i + j + 1] = (sum) % 10;
      }

    for (int p : pos)
      if (!(ans.length() == 0 && p == 0)) ans += to_string(p);

    return ans.length() == 0 ? "0" : ans;
  }
};