class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int length = 0;
    for (ListNode* curr = head; curr; curr = curr->next) ++length;

    k %= length;
    if (k == 0) return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while (k--) fast = fast->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* ans = slow->next;
    slow->next = nullptr;
    fast->next = head;

    return ans;
  }
};