//
// Created by wesley shi on 2017/12/4.
//

#include "Solution.h"

Solution::Solution() {
    num2s.emplace_back("Zero");
    num2s.emplace_back("One");
    num2s.emplace_back("Two");
    num2s.emplace_back("Three");
    num2s.emplace_back("Four");
    num2s.emplace_back("Five");
    num2s.emplace_back("Six");
    num2s.emplace_back("Seven");
    num2s.emplace_back("Eight");
    num2s.emplace_back("Nine");
    num2s.emplace_back("Ten");
    num2s.emplace_back("Eleven");
    num2s.emplace_back("Twelve");
    num2s.emplace_back("Thirteen");
    num2s.emplace_back("Fourteen");
    num2s.emplace_back("Fifteen");
    num2s.emplace_back("Sixteen");
    num2s.emplace_back("Seventeen");
    num2s.emplace_back("Eighteen");
    num2s.emplace_back("Nineteen");
    num2s.emplace_back("Twenty");
    num2s.emplace_back("Thirty");
    num2s.emplace_back("Forty");
    num2s.emplace_back("Fifty");
    num2s.emplace_back("Sixty");
    num2s.emplace_back("Seventy");
    num2s.emplace_back("Eighty");
    num2s.emplace_back("Ninety");

    tens = new int[10];
    tens[0] = 1;
    for (int i=1; i<10; i++){
        tens[i] = tens[i-1]*10;
    }
}



string Solution::numts(int num, int begin, int end, bool need_and){
    begin = begin > 9? 9: begin;
    while (begin >= end && num/tens[begin]%10 == 0){
        begin --;
    }
    if (begin < end){
        return "";
    }
    if (begin == end){
        int i = num/tens[begin]%10;
        string s = num2s[i];
        if (need_and){
            return string("and ").append(s);
        }
        return num2s[i];
    } else if (begin == end + 1){
        int bi = num/tens[begin]%10;
        int ei = num/tens[end]%10;
        if (bi == 1) return num2s[bi*10+ei];
        else {
            string s = num2s[20+bi-2];
            if (ei == 0){
                return s;
            }
            s.append(" ");
            s.append(num2s[ei]);
            return s;
        }
    } else {
        int bi = num/tens[begin]%10;
        string hundred = num2s[bi];
        hundred.append(" Hundred");
        // string ten = numts(num, begin-1, end, true);
        string ten = numts(num, begin-1, end, false);
        if (!ten.empty()){
            hundred.append(" ").append(ten);
        }
        return hundred;
    }
}

string Solution::numberToWords(int num){
    string ns;
    int maxbit = 9;
    for (; maxbit>=0; maxbit--){
        if (num / tens[maxbit] != 0){
            break;
        }
    }
    int start = maxbit/3+1;
    for (int i = start; i>0; i--){
        // string tmp = numts(num, i*3-1, i*3-3, i!=start);
        string tmp = numts(num, i*3-1, i*3-3, false);
        if (tmp.empty()){
            continue;
        }
        if (i != start)ns.append(" ");
        ns.append(tmp);
        if (i == 4){
            ns.append(" Billion");
        } else if (i == 3){
            ns.append(" Million");
        } else if (i == 2){
            ns.append(" Thousand");
        }
    }
    if (ns.empty()){
        return num2s[0];
    }
    return ns;
}
