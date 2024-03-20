struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode *beforeSubListEnd = list1, *afterSubListEnd = list1;
    
    for (int i = 0; i < a - 1; i++)
        beforeSubListEnd = beforeSubListEnd->next;
    
    for (int i = 0; i < b + 1; i++)
        afterSubListEnd = afterSubListEnd->next;
    
    beforeSubListEnd->next = list2;
    
    while (list2->next != NULL)
        list2 = list2->next;
    
    list2->next = afterSubListEnd;
    
    return list1;
}
