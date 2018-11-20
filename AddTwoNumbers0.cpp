ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* p3 = new ListNode(0);
    ListNode* l3 = p3;
    int flag(0);
    int i(0);

    while (p1 != NULL && p2 != NULL) {
        i = p1->val + p2->val + flag;
        if(i < 10){
            ListNode* node = new ListNode(i);
            p3->next = node;
            flag = 0; 
        }else{
            ListNode* node = new ListNode(i % 10);
            p3->next = node;
            flag = i / 10; 
        }
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next; 
    }
    if(p1 != NULL && p2 == NULL){
        while(p1 != NULL) {
            i = p1->val + flag;
            if (i < 10) {
                ListNode *node = new ListNode(i);
                p3->next = node;
                flag = 0; 
            } else {
                ListNode *node = new ListNode(i % 10);
                p3->next = node;
                flag = i / 10; 
            }
            p1 = p1->next;
            p3 = p3->next; 
        }
    }
    if(p1 == NULL && p2 != NULL){
        while(p2 != NULL) {
            i = p2->val + flag;
            if (i < 10) {
                ListNode *node = new ListNode(i);
                p3->next = node;
                flag = 0; 
            } else {
                ListNode *node = new ListNode(i % 10);
                p3->next = node;
                flag = i / 10; 
            }
            p2 = p2->next;
            p3 = p3->next; 
        }
    }
    if(flag != 0){
        ListNode *node = new ListNode(flag);
        p3->next = node;
        flag = 0; 
    }
    ListNode* firstNode = l3;
    l3 = l3->next;
    free(firstNode);
    return l3; 
}
