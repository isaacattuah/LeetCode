class MinStack {
 public:
  void push(int x) {
    int min = stack.empty() ? x : std::min(stack.top().second, x);
    stack.push({x, min});
  }

  void pop() { stack.pop(); }

  int top() { return stack.top().first; }

  int getMin() { return stack.top().second; }

 private:
  std::stack<pair<int, int>> stack;
};