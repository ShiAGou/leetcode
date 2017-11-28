#ifndef INC_2_ADD_TWO_NUMBERS_LIBRARY_H
#define INC_2_ADD_TWO_NUMBERS_LIBRARY_H

#include <iostream>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};
#endif