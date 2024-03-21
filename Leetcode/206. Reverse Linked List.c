/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* current,struct ListNode* prev){
    if(current->next == NULL){
        current->next = prev;
        return current;
    }
    struct ListNode* head = reverse(current->next,current);
    current->next = prev;
    return head;
}

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    return reverse(head,NULL);
}
