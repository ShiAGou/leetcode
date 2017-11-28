//
//  Solution.cpp
//  65_Valid_Number
//
//  Created by wesley shi on 2017/11/28.
//  Copyright © 2017年 self. All rights reserved.
//

#include "Solution.hpp"

bool Solution::isNumber(string s){
    int state = 0;
    for (unsigned long cursor = 0; cursor < s.size(); cursor++){
        char cur = s[cursor];
        switch (state) {
            case 0:
                if (cur == ' '){
                    continue;
                }else if (cur == '+' || cur == '-'){
                    state = -2;
                } else if (cur >= '0' && cur <= '9'){
                    state = 1;
                } else if (cur == '.'){
                    state = 2;
                } else{
                    return false;
                }
                break;
            case -2:
                if (cur >= '0' && cur <= '9'){
                    state = 1;
                } else if (cur == '.'){
                    state = 2;
                } else {
                    return false;
                }
                break;
            case 1:
                if (cur == '.'){
                    state = 3;
                } else if (cur >= '0' && cur <= '9'){
                    continue;
                } else if (cur == ' '){
                    state = 7;
                } else if (cur == 'e'){
                    state = 4;
                } else {
                    return cur == '\0';
                }
                break;
            case 2:
                if (cur >= '0' && cur <= '9'){
                    state = 3;
                } else {
                    return false;
                }
                break;
            case 3:
                if (cur >= '0' && cur <= '9'){
                    continue;
                } else if (cur == 'e') {
                    state = 4;
                } else if (cur == ' '){
                    state = 7;
                } else {
                    return cur == '\0';
                }
                break;
            case 4:
                if (cur >= '0' && cur <= '9'){
                    state = 5;
                } else if (cur == '+' || cur == '-'){
                    state = 8;
                } else{
                    return false;
                }
                break;
            case 5:
                if (cur >= '0' && cur <= '9'){
                    continue;
                } else if (cur == ' '){
                    state = 7;
                } else {
                    return cur == '\0';
                }
                break;
            case 8:
                if (cur >= '0' && cur <= '9'){
                    state = 5;
                } else {
                    return false;
                }
                break;
            case 7:
                if (cur != ' '){
                    return cur == '\0';
                }
                break;
        }
    }
    return state%2 == 1 ;
}
