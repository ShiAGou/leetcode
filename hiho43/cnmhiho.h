//
// Created by wesley shi on 2018/1/7.
//

#ifndef HIHO43_CNMHIHO_H
#define HIHO43_CNMHIHO_H

#include <vector>

using namespace std;

vector<vector<vector<int>>> dp(100, vector<vector<int>>(3, vector<int>(4, 0)));


void init(int max){
    // h
    dp[0][0][0] = 1;
    // i
    dp[0][1][1] = 1;
    // o
    dp[0][2][2] = 1;
    // total
    dp[0][0][3] = 1;
    dp[0][1][3] = 1;
    dp[0][2][3] = 1;
    for (int i=1; i<max; i++){
        for (int j=0; j<3; j++){
            dp[i][j][0] = dp[i-1][j][3];
            dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][2] = dp[i-1][j][0]+dp[i-1][j][2];
            dp[i][j][3] = dp[i][j][0]+dp[i][j][1]+dp[i][j][2];
        }
    }
}

int intervals(int cnt[], int &K){
    for (int i=0; i<3; i++){
        if (K <= cnt[i]){
            return i;
        }
        K -= cnt[i];
    }
    return 0;
}

char search(int N, char c, int K){
    if (N == 0)
        return c;
    int cnt[3] = {0};
    int index = 0;
    switch (c){
        case 'h':
            cnt[0] = dp[N-1][0][3];
            cnt[1] = dp[N-1][1][3];
            cnt[2] = dp[N-1][2][3];
            index = intervals(cnt, K);
            if (index == 0) return search(N-1, 'h', K);
            else if (index == 1) return search(N-1, 'i', K);
            else return search(N-1, 'o', K);
        case 'i':
            cnt[0] = dp[N-1][0][3];
            cnt[1] = dp[N-1][1][3];
            index = intervals(cnt, K);
            if (index == 0) return search(N-1, 'h', K);
            else return search(N-1, 'i', K);
        default: // 'o'
            cnt[0] = dp[N-1][0][3];
            cnt[1] = dp[N-1][2][3];
            index = intervals(cnt, K);
            if (index == 0) return search(N-1, 'h', K);
            else return search(N-1, 'o', K);
    }
}

#endif //HIHO43_CNMHIHO_H
