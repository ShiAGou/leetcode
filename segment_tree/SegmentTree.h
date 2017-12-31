//
// Created by wesley shi on 2017/12/31.
//

#ifndef SEGMENT_TREE_SEGMENTTREE_H
#define SEGMENT_TREE_SEGMENTTREE_H

const int maxn = 10000;

#include <algorithm>

using namespace std;

/**
 * find the minimum in a segment
 */
class SegmentTree {
public:
    int M[maxn];
    int add[maxn];
    int sbegin,send;
    void build(int node, int begin, int end, int A[]);
    int query(int node, int begin, int end, int left, int right);
    // element add
    void change(int node, int begin, int end, int ind, int a);
    // segment add
    void change(int node, int begin, int end, int left, int right, int add);

private:
    void pushDown(int node);
    void pushUp(int node);

};


#endif //SEGMENT_TREE_SEGMENTTREE_H
