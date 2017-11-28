#include "library.h"
using namespace std;

int main(){
    Solution *s = new Solution();
    // 2->4->3
    ListNode *num1 = new ListNode(2);
    ListNode *tmp = num1;
    tmp->next = new ListNode(4); tmp = tmp->next;
    tmp->next = new ListNode(3); tmp = tmp->next;
    // 5->6->4
    ListNode *num2 = new ListNode(5);
    tmp = num2;
    tmp->next = new ListNode(6); tmp = tmp->next;
    tmp->next = new ListNode(4); tmp = tmp->next;

    ListNode *result = s->addTwoNumbers(num1, num2);
    while( result!= nullptr){
        cout << result->val << "->";
        result = result->next;
    }
}
