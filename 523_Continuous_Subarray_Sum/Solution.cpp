//
// Created by wesley shi on 2017/12/5.
//

#include "Solution.h"

#include <iostream>

bool Solution::checkSubarraySum(vector<int>& nums, int k){
    if (nums.size() <=1) return false;
    if (k == 1) return true;
    for (auto i = nums.begin(); i<nums.end(); i++){
        int sum = *i;
        for (auto j = i+1; j<nums.end(); j++){
            sum += *j;
            if (sum == k || (k != 0 && sum % k == 0)) {
                cout << *i << " " << *j << endl;
                return true;
            }
        }
    }
    return false;
}
