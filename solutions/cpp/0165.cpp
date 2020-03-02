class Solution {
 public:
  int compareVersion(string version1, string version2) {
    istringstream iss1(version1);
    istringstream iss2(version2);
    int num1;
    int num2;
    char c;

    while (bool(iss1 >> num1) + bool(iss2 >> num2)) {
      if (num1 < num2) return -1;
      if (num1 > num2) return 1;
      iss1 >> c;
      iss2 >> c;
      num1 = 0;
      num2 = 0;
    }

    if (num1 == num2) return 0;

    return 0;
  };
};