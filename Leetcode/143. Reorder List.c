void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) return;
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *prev = NULL, *curr = slow->next, *nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    slow->next = NULL;
    struct ListNode *p1 = head, *p2 = prev;
    while (p1 != NULL && p2 != NULL) {
        struct ListNode *temp1 = p1->next;
        struct ListNode *temp2 = p2->next;
        p1->next = p2;
        p2->next = temp1;
        p1 = temp1;
        p2 = temp2;
    }
}
