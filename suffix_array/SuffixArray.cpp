//
// Created by wesley shi on 2017/12/27.
//

#include "SuffixArray.h"

const int maxn = 20000;
int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
int rank[maxn], height[maxn];

int cmp(int* r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void SuffixArray::bucketSort(int* r, int* sa, int n, int m){
    int i, j, p, *x = wa, *y = wb, *t;
    // sort the first num
    for (i=0; i<m; i++) ws[i] = 0;
    for (i=0; i<n; i++) ws[x[i] = r[i]]++;
    for (i=1; i<m; i++) ws[i] += ws[i-1];
    for (i=n-1; i>=0; i--) sa[--ws[x[i]]] = i;

    for (int j=1, p=1; p<n; j*=2, m=p){
        // y[k] is the index of the kth first suffix
        // for the suffix that length <= j, set to the front
        for (p=0, i=n-j; i<n; i++) y[p++] = i;
        for (i=0; i<n; i++) if (sa[i]>=j) y[p++]=sa[i]-j;
        // x saves the ranks
        // wv[k] is the former ranks of kth first suffix in y
        for (i=0; i<n; i++) wv[i] = x[y[i]];
        for (i=0; i<m; i++) ws[i] = 0;
        for (i=0; i<n; i++) ws[wv[i]]++;
        for (i=1; i<m; i++) ws[i] += ws[i-1];
        for (i=n-1; i>=0; i--) sa[--ws[wv[i]]] = y[i];

        for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j)? p-1:p++;
    }

}

void SuffixArray::lcp(const int* r, const int* sa, int n){
    int i,j,k=0;
    for (i=1; i<=n; i++) rank[sa[i]] = i;
    for (i=0; i<n; height[rank[i++]] = k)
        // for ith suffix, find the longest from the position k
        for (k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
}
