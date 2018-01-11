//
// Created by wesley shi on 2018/1/7.
//
#include "LCS.h"
#include <iostream>

const int maxn = 100002;
int was[maxn], wbs[maxn], wvs[maxn], wss[maxn];
int ranks[maxn];
int heights[maxn];

int cmp(int* r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void bucketSort(vector<int> &r, vector<int> &sa, int n, int m){
    int i, j, p, *x = was, *y = wbs, *t;
    // sort the first num
    for (i=0; i<m; i++) wss[i] = 0;
    for (i=0; i<n; i++) wss[x[i] = r[i]]++;
    for (i=1; i<m; i++) wss[i] += wss[i-1];
    for (i=n-1; i>=0; i--) sa[--wss[x[i]]] = i;

    for (j=1, p=1; p<n; j*=2, m=p){
        // y[k] is the index of the kth first suffix
        // for the suffix that length <= j, set to the front
        for (p=0, i=n-j; i<n; i++) y[p++] = i;
        for (i=0; i<n; i++) if (sa[i]>=j) y[p++]=sa[i]-j;
        // x saves the ranks
        // wvs[k] is the former ranks of kth first suffix in y
        for (i=0; i<n; i++) wvs[i] = x[y[i]];
        for (i=0; i<m; i++) wss[i] = 0;
        for (i=0; i<n; i++) wss[wvs[i]]++;
        for (i=1; i<m; i++) wss[i] += wss[i-1];
        for (i=n-1; i>=0; i--) sa[--wss[wvs[i]]] = y[i];

        for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j)? p-1:p++;
    }

}

void lcp(vector<int>& r, vector<int>& sa, int n){
    int i,j,k=0;
    for (i=1; i<=n; i++) ranks[sa[i]] = i;
    for (i=0; i<n; heights[ranks[i++]] = k)
        // for ith suffix, find the longest from the position k
        for (k?k--:0,j=sa[ranks[i]-1]; r[i+k]==r[j+k]; k++);
}


bool haveone(vector<int> &tp, int w, int k,int size, int n){
    k--;
    bool is_v[n];
    memset(is_v, 0, sizeof(is_v));
    int tmpk=0;
    for (int i=1; i<size; i++){
        if (heights[i] >= w){
            if (!tmpk) {
                is_v[tp[i-1]]= true;
                tmpk++;
            }
            tmpk ++;
            is_v[tp[i]] = true;
            if (k == tmpk) return true;
        } else if (heights[i+1] < w){
            tmpk = 0;
            memset(is_v, 0, sizeof(is_v));
        }
    }
    return false;
}

int lcs(vector<string> &ss, int m){
    int size =0;
    int maxs = 0;
    vector<int> cnt(ss.size(), 0);
    for (int i=0; i<ss.size(); i++){
        size += ss[i].length()+1;
        cnt[i] = size-1;
        maxs = ss[i].length()>maxs? ss[i].length():maxs;
    }
    vector<int> r(size,0), sa(size,0);
    int d = 0;
    int cur =0;
    for (int i=0; i<ss.size(); i++){
        for (int j=0; j<ss[i].size(); j++){
            r[cur++] = ss[i][j] - 'a' + ss.size();
        }
        r[cur++] = d++;
    }
    bucketSort(r, sa, size, 26+ss.size());
    lcp(r, sa, size);
    for (int i=0; i<size; i++){
        cout << heights[i] << endl;
    }
    vector<int> tp(size,0);
    for (int i=0; i<size; i++){
        int j=0;
        while (cnt[j++] < sa[i]);
        tp[i] = j;
    }

    int l=1,h=maxs;
    int mid = (l+h)>>1;
    while (l!=h){
        if (haveone(tp, mid, m, size, ss.size())){
            l = mid+1;
        } else {
            h = mid;
        }
        mid = (l+h)>>1;
    }
    return haveone(tp, mid, m, size, ss.size())?mid:mid-1;
}
