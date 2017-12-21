//
// Created by wesley shi on 2017/12/19.
//

#include "Solution.h"
#include <iostream>
#include <map>

int Solution::numberOfArithmeticSlices(vector<int>& A){
    int size = A.size();
    int total=0;
    vector<map<long, int>> DP(size, map<long,int>());
    vector<map<long, int>> DP2(size, map<long,int>());
    for (int i=1; i<size; i++){
        for (int j=i-1; j>=0; j--){
            if (A[i] == 1058030317){
                cout << A[j]<< endl;
            }
            long lstep = (long)A[i] - A[j];
            if (lstep > INT32_MAX || lstep < INT32_MIN){
                continue;
            }
            int step = (int)lstep;
            /**
            long step = (long)A[i]-A[j];
             **/
            int value = 0;
            auto itr = DP[j].find(step);
            if (itr != DP[j].end()){
                value += itr->second;
            }
            itr = DP2[j].find(step);
            if (itr != DP2[j].end()){
                value += itr->second;
            }
            if (value != 0){
                itr = DP[i].find(step);
                if (itr == DP[i].end()){
                    DP[i][step]=value;
                } else{
                    DP[i][step] += value;
                }
                cout << A[i] << " "<< A[j] << endl;
            }
            itr = DP2[i].find(step);
            if (itr == DP2[i].end()){
                DP2[i][step] = 1;
            } else{
                DP2[i][step]++;
            }
        }
    }
    for (int i=2; i<size; i++){
        for (auto itr=DP[i].begin(); itr!=DP[i].end(); itr++){
            total+= itr->second;
        }
    }
    return total;
}
