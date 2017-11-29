//
// Created by wesley shi on 2017/11/29.
//

#include "Solution.h"
#include <vector>
#include <map>

string Solution::fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
        return string("0");
    if (numerator == INT32_MIN && denominator == -1){
        long tmp = (long)INT32_MAX +1;
        return to_string(tmp);
    }
    bool sign = (numerator > 0 && denominator < 0)||(numerator < 0 && denominator > 0);
    int head = numerator/denominator;
    long long llnumerator = numerator>0?(long long)numerator:-(long long)numerator;
    long long lldenominator = denominator>0?(long long)denominator:-(long long)denominator;
    long long remainer = llnumerator%lldenominator;
    string shead = to_string(head);
    if (head == 0 && sign){
        shead = "-0";
    }

    if (remainer == 0){
        return shead;
    }
    map<long long, unsigned long> rmap;
    vector<long long> qv;
    unsigned long fbit = 0;

    while (remainer < lldenominator){
        if (remainer == 0){
            fbit = ULONG_MAX;
            break;
        }
        auto itr = rmap.find(remainer);
        if (itr == rmap.end()){
            rmap.insert(map<long long, unsigned long>::value_type(remainer, qv.size()));
        } else {
            fbit = itr->second;
            break;
        }
        remainer *= 10;
        qv.push_back(remainer/lldenominator);
        remainer %= lldenominator;
    }

    shead += '.';
    if (fbit == ULONG_MAX ){
        for (unsigned long i=0; i< qv.size(); i++){
            shead += (char)('0'+ qv[i]);
        }
        return shead;
    } else {
        for (unsigned long i=0; i< fbit; i++){
            shead += (char)('0'+ qv[i]);
        }
        shead += '(';
        for (unsigned long i=fbit; i<qv.size(); i++){
            shead += (char)('0' + qv[i]);
        }
        shead += ')';
    }
    return shead;
}
