//
// Created by wesley shi on 2017/12/31.
//

#ifndef UNION_SET_UNIONSET_H
#define UNION_SET_UNIONSET_H

const int maxn = 10000;

class UnionSet {
    int pre[maxn];
    int rank[maxn];
public:
    int make(int x);
    int find(int x);
    void join(int i1, int i2);


};


#endif //UNION_SET_UNIONSET_H
