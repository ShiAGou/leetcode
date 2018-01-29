//
// Created by wesley shi on 2018/1/29.
//

#include "Solution.h"

#include <iostream>

int Solution::candy(vector<int>& ratings){
    if (ratings.size() == 0)
        return 0;
    stack<int> stk;
    vector<int> per_min(ratings.size(), 1);
    stk.push(0);
    for (int i=1; i<ratings.size(); i++){
        if (stk.empty()){
            stk.push(i);
            continue;
        }
        int top = stk.top();
        if (ratings[i] < ratings[top]){
            per_min[i] = 1;
        } else {
            if (ratings[i] == ratings[top]){
                per_min[i] = 1;
            } else {
                per_min[i] = per_min[top]+1;
            }
            int pre = top;
            stk.pop();
            while (!stk.empty()){
                per_min[stk.top()] = max(per_min[pre]+1, per_min[stk.top()]);
                pre = stk.top();
                stk.pop();
            }
        }
        stk.push(i);
    }
    if (!stk.empty()){
        int pre = stk.top();
        stk.pop();
        while (!stk.empty()){
            per_min[stk.top()] = max(per_min[pre]+1, per_min[stk.top()]);
            pre = stk.top();
            stk.pop();
        }
    }
    int sum = 0;
    for (int i=0; i<per_min.size(); i++){
        sum += per_min[i];
        cout << per_min[i] << ' ';
    }
    cout << endl;
    return sum;
}
