//
// Created by wesley shi on 2017/12/5.
//

#include "Solution.h"

#include <stack>

int Solution::longestValidParentheses(string s){
    int i = 0;
    stack<int> q;
    for (; i < s.size(); i++){
        if (s[i] == '('){
            q.push(i+1);
        } else {
            if (q.empty()) {
                q.push(-i - 1);
                continue;
            }
            int top = q.top();
            if (top > 0) {
                q.pop();
            } else {
                q.push(-i-1);
            }
        }
    }
    if (q.empty()) return (int)s.size();
    int back = abs(q.top());
    int max = (int)s.size() - back;
    q.pop();
    while (!q.empty()){
        int cur = abs(q.top());
        int tmp = back - cur -1;
        max = max < tmp? tmp:max;
        back = cur;
        q.pop();
    }
    max = max> --back?max:back;
    return max;
}
