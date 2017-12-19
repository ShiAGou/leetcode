//
// Created by wesley shi on 2017/12/3.
//

#include "Solution.h"

#include <iostream>

#include <map>

inline void insert(int i, int j, int k, vector<vector<int>> &vv){
    vector<int> v(3);
    v[0] = i; v[1] = j; v[2] = k;
    vv.push_back(v);
}

vector<vector<int>> Solution::threeSum(vector<int>& nums){
    vector<vector<int>> vv;
    if (nums.size() < 3){
        return vv;
    }
    map<int, int> m;
    for (auto i = nums.begin(); i<nums.end(); i++){
        auto itr = m.find(*i);
        if (itr == m.end()){
            m.insert(map<int, int>::value_type(*i, 1));
        } else {
            itr ->second ++;
        }
    }
    auto zero = m.find(0);
    if (m.end() != zero && zero->second > 2){
        insert(0, 0, 0, vv);
    }
    for (auto i = m.begin(); i!= m.end(); i++){
        for (auto j=i; j!= m.end(); j++){
            if (j==i){
                // cout << i->first << " "<< i->second << endl;
                if (i->first != 0 && i->second > 1){
                    int need = - i->first - i->first;
                    if (m.end() != m.find(need)){
                        insert(i->first, i->first, need, vv);
                    }
                }
            } else {
                int need = -i->first - j->first;
                if (need < i->first && need < j->first
                    && m.end() != m.find(need)){
                    insert(i->first, j->first, need, vv);
                }
            }
        }
    }
    return vv;
}
