//
// Created by wesley shi on 2017/11/29.
//

#include "Solution.h"

Solution::Solution() {
    TMP = new int[32];
    for (int i = 0; i<32; i++){
        TMP[i] = 1 << i;
    }
}

int Solution::divide(int dividend, int divisor) {
    if (divisor == 0){
        return 0x7fffffff;
    } else if (dividend == 0){
        return 0;
    } else if (dividend == 0x80000000 && divisor == -1){
        return 0x7fffffff;
    }
    int result = 0;
    bool sign = false;
    if ((dividend & TMP[31]) == (divisor & TMP[31])){
        sign = true;
    }
    auto p_dividend = (unsigned int)dividend;
    auto p_divisor = (unsigned int)divisor;
    if (dividend < 0) p_dividend = (unsigned int)-dividend;
    if (divisor < 0) p_divisor = (unsigned int)-divisor;
    int cursor = 31;
    while (cursor >= 0){
        while (cursor >= 0 && (p_dividend >> cursor) < p_divisor){
            cursor --;
        }
        if (cursor < 0){
            break;
        }
        p_dividend -= p_divisor << cursor;
        result |= TMP[cursor];
    }
    return sign? result:-result;
}