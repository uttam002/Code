struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* nextTmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTmp;
    }
    
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    struct ListNode* reversed = reverseList(slow->next);
    
    while (reversed != NULL) {
        if (head->val != reversed->val)
            return false;
        head = head->next;
        reversed = reversed->next;
    }
    
    return true;
}

