//
// Created by wesley shi on 2017/12/21.
//

#include "Solution.h"

int Solution::maximalRectangle(vector<vector<char>>& matrix){
    int h = matrix.size();
    if (h == 0)
        return 0;
    int w = matrix[0].size();
    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (int i=0; i<w; i++){
        if (matrix[0][i] == '1')
            dp[0][i] = 1;
    }
    for (int i=1; i<h; i++){
        for (int j=0; j<w; j++){
            dp[i][j] = matrix[i][j]=='1'?dp[i-1][j]+1:0;
        }
    }
    int maxa = matrix[0][0]=='1'?1:0;
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (matrix[i][j] == '0'){
                continue;
            }
            int minH = i+1;
            for (int k=j; k>=0 && matrix[i][k]=='1'; k--){
                minH = min(minH, dp[i][k]);
                maxa = max(maxa, minH * (j-k+1));
            }
        }
    }
    return maxa;
}
