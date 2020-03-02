class Solution {
 public:
  string countOfAtoms(string formula) {
    string ans;
    int i = 0;

    for (const auto& [elem, freq] : parse(formula, i))
      ans += elem + (freq == 1 ? "" : to_string(freq));

    return ans;
  }

  map<string, int> parse(string& s, int& i) {
    const int n = s.length();
    map<string, int> count;

    while (i < n) {
      if (s[i] == '(') {
        ++i;
        for (const auto& [elem, freq] : parse(s, i)) count[elem] += freq;
      } else if (s[i] == ')') {
        int numStart = ++i;
        while (i < n && isdigit(s[i])) ++i;
        int factor = stoi(s.substr(numStart, i - numStart));
        for (auto&& [_, freq] : count) freq *= factor;
        return count;
      } else if (isupper(s[i])) {
        int elemStart = i++;
        while (i < n && islower(s[i])) ++i;
        string elem = s.substr(elemStart, i - elemStart);
        int numStart = i;
        while (i < n && isdigit(s[i])) ++i;
        string num = s.substr(numStart, i - numStart);
        count[elem] += num.empty() ? 1 : stoi(num);
      }
    }

    return count;
  }
};