class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    const int k = primes.size();

    vector<int> nums{1};
    vector<int> indices(k);

    while (nums.size() < n) {
      vector<int> nexts(k);
      for (int i = 0; i < k; ++i) nexts[i] = nums[indices[i]] * primes[i];
      int next = accumulate(begin(nexts), end(nexts), INT_MAX,
                            [](const int a, const int b) { return min(a, b); });

      for (int i = 0; i < k; ++i)
        if (next == nexts[i]) ++indices[i];

      nums.push_back(next);
    }

    return nums.back();
  }
};