//
// Created by wesley shi on 2017/12/31.
//

#ifndef UNION_SET_COUNTINGISLAND2_H
#define UNION_SET_COUNTINGISLAND2_H

#include <algorithm>

using namespace std;


/**
 * a example of union set
 * http://hihocoder.com/contest/hiho183/problem/1
 */
const int M=1000;

class CountingIsland2 {
    int A[M*M];
    int x_offset[4]={0, -1, 0, 1};
    int y_offset[4]={-1, 0, 1, 0};
public:
    int count=0;
    CountingIsland2();
    void mark(int x, int y);
    void join(int x1, int x2);
    int find(int x);
};


#endif //UNION_SET_COUNTINGISLAND2_H
