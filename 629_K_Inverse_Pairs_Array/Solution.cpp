//
// Created by wesley shi on 2017/12/19.
//

#include "Solution.h"

#include <vector>
using namespace std;

int Solution::kInversePairs(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i=0; i<n+1; i++)
        dp[i][0] = 1;
    for (int i=1; i<n+1; i++){
        for (int j=1; j<k+1; j++){
            dp[i][j] = (dp[i][j-1]+dp[i-1][j])%1000000007;
            if (i <= j)
                dp[i][j] -= dp[i-1][j-i];
            if (dp[i][j] < 0)
                dp[i][j] += 1000000007;
        }
    }
    return dp[n][k];
    // return dp[n][k]<0?dp[n][k]+1000000007:dp[n][k];
}