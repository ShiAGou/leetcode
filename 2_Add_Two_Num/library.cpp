#include "library.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* header = new ListNode(-1);
    ListNode* trail = header;
    int add;
    while(l1 != NULL&& l2 != NULL){
        int val = l1->val+l2->val+add;
        if (val > 9){
            add = 1;
            val -= 10;
        }else{
            add = 0;
        }
        ListNode *current = new ListNode(val);
        trail->next = current;
        trail = current;
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode* remain = l1== nullptr?l2:l1;
    if (remain == NULL&& add == 1){
        trail->next = new ListNode(1);
        return header->next;
    }
    while (remain != NULL){
        int val = remain->val + add;
        if (val > 9){
            val = 0;
            add = 1;
        } else{
            add = 0;
        }
        ListNode *current = new ListNode(val);
        trail->next = current;
        trail = current;
        remain = remain->next;
    }
    if (add == 1){
        trail->next = new ListNode(1);
    }
    return header->next;
}

