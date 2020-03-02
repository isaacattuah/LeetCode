class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> ans;
    unordered_map<string, int> restaurantToIndex;
    int minSum = INT_MAX;

    for (int i = 0; i < list1.size(); ++i) restaurantToIndex[list1[i]] = i;

    for (int i = 0; i < list2.size(); ++i) {
      if (restaurantToIndex.count(list2[i])) {
        int sum = restaurantToIndex[list2[i]] + i;
        if (sum < minSum) ans.clear();
        if (sum <= minSum) {
          ans.push_back(list2[i]);
          minSum = sum;
        }
      }
    }

    return ans;
  }
};