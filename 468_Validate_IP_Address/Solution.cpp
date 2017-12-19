//
// Created by wesley shi on 2017/12/2.
//

#include "Solution.h"

string Solution::validIPAddress(string IP){
    if (string::npos != IP.find('.')){
        IP.append(".");
        string::size_type anchor = IP.find('.');
        string::size_type start = 0;
        int phase = 0;
        while (string::npos != anchor){
            phase ++;
            if (phase > 4 || anchor-start >3 || anchor == start){
                return "Neither";
            }
            int tmp = 0;
            for (string::size_type i= start; i<anchor; i++){
                if (IP[i] < '0' || IP[i] > '9'){
                    return "Neither";
                }
                if (i == start && IP[i] == '0' && anchor - start != 1){
                    return "Neither";
                }
                tmp = tmp*10 + IP[i] - '0';
            }
            if (tmp > 255){
                return "Neither";
            }
            start = anchor+1;
            anchor = IP.find('.', start);
        }
        if (phase == 4){
            return "IPv4";
        }
    } else if (string::npos != IP.find(':')) {
        IP.append(":");
        string::size_type anchor = IP.find(':');
        string::size_type start = 0;
        int phase = 0;
        while (string::npos != anchor) {
            phase++;
            if (phase > 8 || anchor - start > 4 || anchor == start) {
                return "Neither";
            }
            for (string::size_type i = start; i < anchor; i++) {
                if (!(IP[i] >= '0' && IP[i] <= '9')
                    && !(IP[i] >= 'a' && IP[i] <= 'f')
                        && !(IP[i] >= 'A' && IP[i] <= 'F')) {
                    return "Neither";
                }
            }
            start = anchor + 1;
            anchor = IP.find(':', start);
        }
        if (phase == 8){
            return "IPv6";
        }
    }
    return "Neither";
}
