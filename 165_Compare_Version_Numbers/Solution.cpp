//
// Created by wesley shi on 2017/12/2.
//

#include "Solution.h"


int Solution::compareVersion(string version1, string version2){
    if (version1 == version2)
        return 0;
    version1.append(".");
    version2.append(".");
    auto anchor1 = version1.find('.');
    auto anchor2 = version2.find('.');
    string::size_type s1 = 0, s2 = 0;
    while (string::npos != anchor1 && string::npos != anchor2){
        while(version1[s1] == '0'){
            s1 ++;
        }
        while(version2[s2] == '0'){
            s2 ++;
        }
        if (anchor1 + s2 != anchor2 + s1){
            return anchor1 + s2 > anchor2 + s1? 1:-1;
        }
        for (string::size_type i = s1, j=s2; i < anchor1; i++, j++){
            if (version1[i] != version2[j]){
                return version1[i] > version2[j]? 1:-1;
            }
        }
        s1 = anchor1 + 1;
        s2 = anchor2 + 1;
        anchor1 = version1.find('.', s1);
        anchor2 = version2.find('.', s2);
    }
    if (anchor1 == anchor2){
        return 0;
    } else if (anchor1 == string::npos){
        for (; s2 < version2.size(); s2++){
            if (version2[s2] != '0' && version2[s2] !='.'){
                return -1;
            }
        }
        return 0;
    } else {
        for (; s1 < version1.size(); s1++){
            if (version1[s1] != '0' && version1[s1] !='.'){
                return 1;
            }
        }
        return 0;
    }
}
