class MyLinkedList {
 public:
  int get(int index) {
    if (index < 0 || index >= length) return -1;
    ListNode* curr = dummy.next;
    for (int i = 0; i < index; ++i) curr = curr->next;
    return curr->val;
  }

  void addAtHead(int val) {
    ListNode* curr = dummy.next;
    dummy.next = new ListNode(val);
    dummy.next->next = curr;
    ++length;
  }

  void addAtTail(int val) {
    ListNode* curr = &dummy;
    while (curr->next) curr = curr->next;
    curr->next = new ListNode(val);
    ++length;
  }

  void addAtIndex(int index, int val) {
    if (index > length) return;
    ListNode* curr = &dummy;
    for (int i = 0; i < index; ++i) curr = curr->next;
    ListNode* temp = curr->next;
    curr->next = new ListNode(val);
    curr->next->next = temp;
    ++length;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= length) return;
    ListNode* curr = &dummy;
    for (int i = 0; i < index; ++i) curr = curr->next;
    ListNode* temp = curr->next;
    curr->next = temp->next;
    --length;
    delete temp;
  }

 private:
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
  };

  int length = 0;
  ListNode dummy = ListNode(0);
};
