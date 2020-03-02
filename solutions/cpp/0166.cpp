class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";

    string ans;

    if (numerator < 0 ^ denominator < 0) ans += "-";

    long n = abs((long)numerator);
    long d = abs((long)denominator);
    ans += to_string(n / d);

    if (n % d == 0) return ans;

    ans += '.';
    unordered_map<long, int> map;

    for (long r = n % d; r; r %= d) {
      if (map.count(r)) {
        ans.insert(map[r], 1, '(');
        ans += ')';
        break;
      }
      map[r] = ans.length();
      r *= 10;
      ans += to_string(r / d);
    }

    return ans;
  }
};