class Twitter {
 public:
  void postTweet(int userId, int tweetId) {
    tweets[userId].push_front({timer++, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> ans;
    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first < b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);
    for (const pair<int, int>& tweet : tweets[userId]) pq.push(tweet);
    for (auto it = begin(followees[userId]); it != end(followees[userId]); ++it)
      for (const pair<int, int>& tweet : tweets[*(it)]) pq.push(tweet);
    for (int i = min(10, (int)pq.size()); i > 0; --i)
      ans.push_back(pq.top().second), pq.pop();
    return ans;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) return;
    followees[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId) return;
    followees[followerId].erase(followeeId);
  }

 private:
  int timer = 0;
  unordered_map<int, deque<pair<int, int>>> tweets;
  unordered_map<int, unordered_set<int>> followees;
};