#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {} //构造函数初始值列表
};

/*start*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p3 = new ListNode(0);     //new动态分配和初始化对象
    ListNode* l3 = p3;
    int flag(0);
    int i(0);

    while (l1 != NULL && l2 != NULL) {
        i = l1->val + l2->val + flag;
        if(i < 10){
            ListNode* node = new ListNode(i);
            p3->next = node;
            flag = 0;
        }else{
            ListNode* node = new ListNode(i % 10);
            p3->next = node;
            flag = i / 10;
        }
        l1 = l1->next;
        l2 = l2->next;
        p3 = p3->next;
    }
    if(l1 != NULL && l2 == NULL){
        while(l1 != NULL) {
            i = l1->val + flag;
            if (i < 10) {
                ListNode *node = new ListNode(i);
                p3->next = node;
                flag = 0;
            } else {
                ListNode *node = new ListNode(i % 10);
                p3->next = node;
                flag = i / 10;
            }
            l1 = l1->next;
            p3 = p3->next;
        }
    }
    if(l1 == NULL && l2 != NULL){
        while(l2 != NULL) {
            i = l2->val + flag;
            if (i < 10) {
                ListNode *node = new ListNode(i);
                p3->next = node;
                flag = 0;
            } else {
                ListNode *node = new ListNode(i % 10);
                p3->next = node;
                flag = i / 10;
            }
            l2 = l2->next;
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
/*end*/

int main() {
    ListNode* l1= new ListNode(2);
    ListNode* node1 = new ListNode(4);
    l1->next = node1;
    ListNode* node2 = new ListNode(3);
    node1->next = node2;

    ListNode* l2 = new ListNode(5);
    ListNode* node3 = new ListNode(6);
    l2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;

    ListNode* l3 = addTwoNumbers(l1, l2);
    ListNode* p = l3;

    while (p != NULL) {
        cout << p->val << ' ';
        p = p->next;
    }
    return 0;
}
