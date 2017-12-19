//
// Created by wesley shi on 2017/12/10.
//

#include "Solution.h"

#include <vector>

bool Solution::isInterleave(string s1, string s2, string s3){
    auto size1 = s1.size();
    auto size2 = s2.size();
    auto size3 = s3.size();
    if (size1 + size2 != size3)
        return false;
    if (size1 == 0)
        return s2 == s3;
    else if (size2 == 0)
        return s1 == s3;
    vector<bool> dp(size1+1, false);
    dp[0] = true;
    for (decltype(size1) k=1; k<=size1; k++){
        dp[k] = dp[k-1] && s1[k-1] == s3[k-1];
    }
    for (decltype(size2) j=1; j<=size2; j++){
        for (decltype(size1) i=0; i<=size1; i++){
            dp[i] = (i!=0 && dp[i-1] && s1[i-1] == s3[j+i-1])
                    || (dp[i] && s2[j-1] == s3[j+i-1]);
        }
    }
    return dp[size1];
}
