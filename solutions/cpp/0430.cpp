class Solution {
 public:
  Node* flatten(Node* head) {
    for (Node* curr = head; curr; curr = curr->next)
      if (curr->child) {
        Node* next = curr->next;
        curr->next = curr->child;
        curr->child->prev = curr;
        curr->child = nullptr;
        Node* tail = curr->next;
        while (tail->next) tail = tail->next;
        tail->next = next;
        if (next) next->prev = tail;
      }

    return head;
  }
};