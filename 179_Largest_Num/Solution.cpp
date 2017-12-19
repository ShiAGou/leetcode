//
// Created by wesley shi on 2017/12/4.
//

#include "Solution.h"
#include <iostream>
#include <algorithm>

long long tens[] = {1, 10, 100, 1000, 10000, 100000,
                    1000000, 10000000, 100000000, 1000000000, 10000000000};

bool comp(const int &a, const int &b){
    if (a == 0)
        return false;
    else if (b == 0){
        return true;
    }
    int i = 9, j = 9;
    while(i >= 0 && a / tens[i] == 0){
        i --;
    }
    while (j >= 0 && b/tens[j]==0){
        j --;
    }
    if (i == j){
        return a > b;
    }
    int small, big, biglen, smalllen;
    if (i > j){
        smalllen = j;
        biglen = i;
        small = b;
        big = a;
    } else {
        smalllen = i;
        biglen = j;
        small = a;
        big = b;
    }

    int tmp = 0;
    while (biglen > smalllen){
        tmp = big/tens[biglen - smalllen] - small;
        if (tmp != 0){
            break;
        }
        biglen -= smalllen;
        big %= tens[biglen];
        biglen --;
    }
    bool choice;
    if (tmp == 0) choice = big*tens[smalllen - biglen] > small;
    else choice = tmp > 0;
    return i>j == choice;
}


bool comp2(const int& a, const int& b){
    if (a == b){
        return false;
    }
    if (a == 0)
        return false;
    if (b == 0)
        return true;
    int i = 9, j = 9;
    while(i >= 0 && a / tens[i] == 0){
        i --;
    }
    while (j >= 0 && b/tens[j]==0){
        j --;
    }
    long long l1 = a*tens[j+1] + b;
    long long l2 = a + b*tens[i+1];
    return l1 > l2;
}



bool comp3(const int& a, const int& b){
    string sa = to_string(a);
    string sb = to_string(b);

    return sa + sb > sb + sa;
}

void compcnm(vector<int> &nums){
    for (auto i = nums.begin(); i!= nums.end(); i++){
        for (auto j = i; j!= nums.end(); j++){
            if (comp2(*i, *j) != comp3(*i, *j)){
                cout << *i << " " << *j << endl;
            }
        }
    }
}

string Solution::largestNumber(vector<int>& nums){
    sort(nums.begin(), nums.end(), comp2);
    string s;

    for (auto itr = nums.begin(); itr != nums.end(); itr++){
        cout << *itr << endl;
        s.append(to_string(*itr));
    }
    if (s.size() == 0 || s[0] == '0'){
        return "0";
    }
    return s;
}
