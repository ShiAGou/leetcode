//
// Created by wesley shi on 2017/12/31.
//

#include "UnionSet.h"

int UnionSet::find(int x){
    if (pre[x] != x){
        pre[x] = find(pre[x]);
    }
    return pre[x];
}

void UnionSet::join(int x1, int x2){
    int f1 = find(x1);
    int f2 = find(x2);
    if (f1 == f2) {
        return;
    }
    if (rank[f1] > rank[f2]){
        pre[f2] = f1;
        rank[f1] += rank[f2];
    } else{
        pre[f1] = f2;
        rank[f2] += rank[f1];
    }
}
