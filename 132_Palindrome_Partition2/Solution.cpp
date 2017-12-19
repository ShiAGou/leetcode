//
// Created by wesley shi on 2017/12/9.
//

#include "Solution.h"

#include <vector>

inline bool isPalindrom(string &s, int i, int j){
    while(i<j){
        if (s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int Solution::minCut(string s){
    auto size = (int)s.length();
    if(size <= 1) return 0;
    vector<int> dp(size+1, -1);
    vector<vector<bool>> m(size, vector<bool>(size, false));
    for (int i=0; i<size; i++){
        for (int j=0; j<=i; j++){
            if (i == j) m[j][i] = true;
            else if (i == j+1) m[j][i] = s[i] == s[j];
            else m[j][i] = s[i] == s[j] && m[j+1][i-1];
        }
    }
    for (int i=1; i<=size; i++){
        int tmp = INT32_MAX;
        for (int j = 1; j<=i; j++){
            if (m[j-1][i-1]){
                tmp = min(tmp, dp[j-1]+1);
            }
        }
        dp[i] = tmp;
    }
    return dp[size];
}
