/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* temp;
    struct ListNode* first = head;
    struct ListNode* second = head;
    for (int i = 0; i < n; i++) {
     if (second->next == NULL) {
       if (i == n - 1) {
                temp = head;
                head = head->next;
                free(temp);
            }
            return head;
        }
        second = second->next;
    }
     while (second->next != NULL) {
        first = first->next;
        second = second->next;
    }
    temp = first->next;
    first->next = first->next->next;
    free(temp);
    return head;
}
