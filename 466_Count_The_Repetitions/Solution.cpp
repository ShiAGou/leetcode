//
// Created by wesley shi on 2017/12/19.
//

#include "Solution.h"

int Solution::getMaxRepetitions(string s1, int n1, string s2, int n2){
    int times = 0;
    int anchor = 0;
    auto s1len = s1.length();
    auto s2len = s2.length();
    for (int i=0; i<n1; i++){
        for (decltype(s1len) j=0; j<s1len; j++){
            if (s1[j] == s2[anchor]){
                anchor++;
                if (anchor == s2len){
                    times++;
                    anchor = 0;
                }
            }
        }
    }
    return times/n2;
}