//
// Created by wesley shi on 2017/12/21.
//

#include "Solution.h"

#include <stack>

int Solution::largestRectangleArea(vector<int>& heights){
    if (heights.size() ==0)
        return 0;
    else if (heights.size() ==1)
        return heights[0];
    vector<int> anchor_heights(heights.size()+2, -1);
    stack<int> stck;
    stck.push(0);
    int maxa = 0;
    for (int i=1; i<anchor_heights.size(); i++){
        if (i != anchor_heights.size()-1)
            anchor_heights[i] = heights[i-1];
        while (anchor_heights[stck.top()] > anchor_heights[i]){
            int top = stck.top();
            stck.pop();
            maxa = max(anchor_heights[top]*(i-stck.top()-1), maxa);
        }
        stck.push(i);
    }
    return maxa;
}
