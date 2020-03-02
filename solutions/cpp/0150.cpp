class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    unordered_map<string, function<int(int, int)>> map{{"+", plus<int>()},
                                                       {"-", minus<int>()},
                                                       {"*", multiplies<int>()},
                                                       {"/", divides<int>()}};

    for (const string& token : tokens) {
      if (map.count(token)) {
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        stack.push(map[token](a, b));
      } else
        stack.push(stoi(token));
    }

    return stack.top();
  }
};