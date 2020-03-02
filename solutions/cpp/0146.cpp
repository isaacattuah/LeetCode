class LRUCache {
 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!map.count(key)) return -1;

    const auto& node = map[key];
    cache.splice(begin(cache), cache, node);
    return node->value;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      const auto& node = map[key];
      node->value = value;
      cache.splice(begin(cache), cache, node);
      return;
    }

    if (cache.size() == capacity) {
      Node& lastNode = cache.back();
      map.erase(lastNode.key);
      cache.pop_back();
    }

    cache.push_front(Node(key, value));
    map[key] = begin(cache);
  }

 private:
  struct Node {
    int key;
    int value;
    Node(int key, int value) : key(key), value(value) {}
  };

  int capacity;
  list<Node> cache;
  unordered_map<int, list<Node>::iterator> map;
};