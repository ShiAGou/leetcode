//
// Created by wesley shi on 2017/11/28.
//

#include "Solution.h"

/**
 * what should we take into consideration?
 * 1. 1234
 * 2. +1234/-1234
 * 3. 00012345
 * 4. 1239127581927591 overflow
 * @param str
 * @return
 */

int Solution::myAtoi(string str) {
    unsigned long size = str.size();
    int state = 0;
    int result = 0;
    int sign = 1;
    int negative_max10 = INT32_MIN/10;
    int positive_max10 = INT32_MAX/10;
    int bitcount = 0;
    for (unsigned long i=0; i<size; i++){
        char c = str[i];
        switch(state){
            case 0:
                if (c>='0' && c<= '9'){
                    state = 1;
                    result = (int)(c - '0');
                    bitcount ++;
                } else if (c == ' ' || c == '\n'){
                    continue;
                } else if (c == '+'){
                    state = 1;
                } else if (c == '-'){
                    sign = -1;
                    state = 1;
                } else {
                    state = 2;
                }
                break;
            case 1:
                if (c >='0' && c<= '9'){
                    bitcount++;
                    int val = c -'0';
                    if (sign == 1){
                        if (bitcount >= 10 && result > positive_max10){
                            result = INT32_MAX;
                            state = 2;
                            break;
                        }
                        result *= 10;
                        if (bitcount >= 10 && result > INT32_MAX - val){
                            result = INT32_MAX;
                            state = 2;
                            break;
                        }
                        result += val;
                    } else {
                        if (bitcount >= 10 && result < negative_max10){
                            result = INT32_MIN;
                            state = 2;
                            break;
                        }
                        result *= 10;
                        if (bitcount >= 10 && result < INT32_MIN + val){
                            result = INT32_MIN;
                            state = 2;
                            break;
                        }
                        result -= val;
                    }
                } else{
                    state = 2;
                }
                break;
            default:
                // end
                break;
        }
    }
    return result;
}