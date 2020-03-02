class MyCalendar {
 public:
  bool book(int start, int end) {
    for (pair<int, int>& book : books)
      if (max(book.first, start) < min(book.second, end)) return false;
    books.push_back({start, end});

    return true;
  }

 private:
  vector<pair<int, int>> books;
};