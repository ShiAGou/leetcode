//
// Created by wesley shi on 2017/12/9.
//

#include "Solution.h"

#include <vector>

int Solution::numDecodings(string s){
    auto size = s.length();
    if (size == 0)
        return 0;
    if (s[0] == '0')
        return 0;
    vector<long> dp(size+1, 0);
    dp[0] = 1;
    if (s[0] == '*'){
        dp[1] = 9;
    } else {
        dp[1] = 1;
    }
    for (decltype(size) i = 2; i<=size; i++){
        if (s[i-1] == '*'){
            dp[i] = dp[i-1] * 9;
            if (s[i-2] == '1') dp[i] += dp[i-2]*9;
            else if (s[i-2] == '2') dp[i] += dp[i-2]*6;
            else if (s[i-2] == '*') dp[i] += dp[i-2]*15;
        } else if (s[i-1] == '0'){
            if ((s[i-2] > '2' && s[i-2] <= '9') || s[i-2] == '0') return 0;
            if (s[i-2] == '*'){
                dp[i] = 2*dp[i-2];
            } else {
                dp[i] = dp[i-2];
            }
        } else {
            dp[i] = dp[i-1];
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')){
                dp[i] += dp[i-2];
            } else if (s[i-2] == '*'){
                if (s[i-1] > '6') dp[i] += dp[i-2];
                else dp[i] += 2*dp[i-2];
            }
        }
        dp[i] %= 1000000007;
    }
    return (int)dp[size];
}
