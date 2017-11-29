//
// Created by wesley shi on 2017/11/29.
//

#include "Solution.h"
#include <math.h>
#include <vector>
using namespace std;

/**
unsigned long long stoull(string s){
    stringstream stringstream1(s);
    unsigned long long lln = 0;
    stringstream1 >> lln;
    return lln;
}
 **/

string naivePalindromic(string n){
    unsigned long cur = n.size()/2;
    string result = n;
    for (unsigned long i = 0; i < cur; i++){
        result[n.size() - 1 - i] = result[i];
    }
    return result;
}

Solution::Solution() {
    TMP = new unsigned long long[18];
    TMP[0] = 1;
    for (int i =1; i < 18; i++){
        TMP[i] = TMP[i-1]*10;
    }
}


string Solution::nearestPalindromic(string n) {
    unsigned long long ull_n = stoull(n);
    if (n.size() == 1) {
        return ull_n == 0 ? string("1") : to_string(ull_n - 1);
    }
    string result = naivePalindromic(n);

    vector<unsigned long long> v;
    v.push_back(ull_n - TMP[n.size() / 2]);
    v.push_back(ull_n - (n[n.size() / 2] - '0' + 1) * TMP[n.size() / 2 - 1]);
    v.push_back(stoull(result));
    v.push_back(ull_n + (n[n.size() / 2] - '0' + 1) * TMP[n.size() / 2 - 1]);
    v.push_back(ull_n + TMP[n.size() / 2]);
    unsigned long min_index = 0;
    unsigned long long min = ULONG_LONG_MAX;
    for (unsigned long i = 0; i < v.size(); i++) {
        v[i] = stoull(naivePalindromic(to_string(v[i])));
        unsigned long long r = v[i] > ull_n ? v[i] - ull_n : ull_n - v[i];
        if (r == 0) {
            continue;
        }
        if (r < min) {
            min = r;
            min_index = i;
        }
    }
    return to_string(v[min_index]);
}
