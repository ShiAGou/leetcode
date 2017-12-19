//
// Created by wesley shi on 2017/12/1.
//

#include "Solution.h"

int Solution::numDecodings(string s){
    if (s.size() == 0 || s == "0" || s[0] == '0')
        return 0;
    auto ways = new int[s.size()+1];
    ways[0] = 1;
    ways[1] = 1;
    for (unsigned long i=1; i<s.size(); i++){
        if (s[i] == '0'){
            if (s[i-1] > '2' || s[i-1] == '0'){
                return 0;
            } else {
                ways[i+1] = ways[i-1];
            }
        } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
            ways[i+1] = ways[i] + ways[i-1];
        } else {
            ways[i+1] = ways[i];
        }
    }
    return ways[s.size()];
}
