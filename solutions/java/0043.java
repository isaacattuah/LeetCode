class Solution {
  public String multiply(String num1, String num2) {
    final int m = num1.length();
    final int n = num2.length();

    StringBuilder ans = new StringBuilder();
    int[] pos = new int[m + n];

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        int multiply = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
        int sum = multiply + pos[i + j + 1];
        pos[i + j] += sum / 10;
        pos[i + j + 1] = (sum) % 10;
      }

    for (int p : pos)
      if (!(ans.length() == 0 && p == 0))
        ans.append(p);

    return ans.length() == 0 ? "0" : ans.toString();
  }
}