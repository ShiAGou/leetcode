//
// Created by wesley shi on 2017/12/18.
//

#include "Solution.h"

int Solution::maxProduct(vector<int>& nums){
    auto len = nums.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[0];
    vector<vector<int>> dp(3, vector<int>(len, 0));
    dp[0][0] = dp[1][0] = dp[2][0] = nums[0];
    for (decltype(len) i = 1; i<len; i++){
        int num = nums[i];
        if (num >= 0){
            dp[1][i] = max(dp[1][i-1]*num, num);
            dp[2][i] = min(dp[2][i-1]*num, num);
            dp[0][i] = max(dp[0][i-1], dp[1][i]);
        } else {
            dp[1][i] = max(dp[2][i-1]*num, num);
            dp[2][i] = min(dp[1][i-1]*num, num);
            dp[0][i] = max(dp[0][i-1], dp[1][i]);
        }
    }
    return dp[0][len-1];
}
