//
// Created by wesley shi on 2017/12/31.
//

#include "SegmentTree.h"



void SegmentTree::build(int node, int begin, int end, int A[]){
    if (node == 0){
        memset(M, 0, sizeof(M));
        memset(add, 0, sizeof(add));
        sbegin = begin;
        send = end;
    }
    if (begin == end){
        M[node] = A[begin];
        return;
    }
    int mid = (begin+end)<<1;
    int next = node << 1;
    build(next, begin, mid, A);
    build(next+1, mid+1, end, A);
    M[node] = min(M[next], M[next+1]);
}



int SegmentTree::query(int node, int begin, int end, int left, int right){
    if (left <= begin && right >= end) return M[node];
    pushDown(node);
    int mid = (begin+end)>>1;
    int q1=INT32_MAX, q2=INT32_MAX;
    if (mid >= left && begin <= right){
        q1 = query(node<<1, begin, mid, left, right);
    }
    if (mid+1 <= right && end >= left){
        q2 = query(node<<1+1, mid+1, end, left, right);
    }
    return min(q1, q2);
}

void SegmentTree::change(int node, int begin, int end, int ind, int add) {
    if (begin == end){
        M[node] += add;
        return;
    }
    pushDown(node);
    // binary search
    int mid = (begin+end) >> 1;
    if (ind <= mid){
        change(node<<1, begin, mid, ind, add);
    } else {
        change(node<<1+1, mid+1, end, ind, add);
    }
    // update parent node
    pushUp(node);
}

/**
 * add a num to a segment [left, right]
 * @param node
 * @param begin begin index of the segment the node represents
 * @param end end index...
 * @param left begin index of the segment that need to add a num
 * @param right end index...
 * @param add the num to add
 */
void SegmentTree::change(int node, int begin, int end, int left, int right, int a){
    if (begin >= left && end <= right){
        add[node] += a;
        M[node] += a;
        return;
    }
    pushDown(node);
    int mid = (begin+end)>>1;
    if (mid >= left) change(node<<1, begin, mid, left, right, a);
    if (mid < right) change(node<<1+1, mid+1, end, left, right, a);
    pushUp(node);
}

/**
 * update the direct children of the node
 * @param node
 */
void SegmentTree::pushDown(int node){
    if (add[node]){
        add[node<<1] += add[node];
        add[node<<1+1] += add[node];
        M[node<<1] += add[node];
        M[node<<1+1] += add[node];
        add[node] = 0;
    }
}

void SegmentTree::pushUp(int node){
    M[node] = min(M[node<<1], M[node<<1+1]);
}


