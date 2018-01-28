//
// Created by wesley shi on 2018/1/11.
//

#ifndef GRAPH_MINTREEGRAPH_H
#define GRAPH_MINTREEGRAPH_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <sstream>

#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define REP(i, n)       for((i) = 0; (i) < (n); ++(i))
#define FOR(i, l, h)    for((i) = (l); (i) <= (h); ++(i))
#define FORD(i, h, l)   for((i) = (h); (i) >= (l); --(i))
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   x < y ? x : y
#define Max(x, y)   x < y ? y : x
#define E(x)    (1 << (x))

const double eps = 1e-6;
const double inf = ~0u>>1;
typedef long long LL;

using namespace std;

const int N = 110;
const int M = 10010;

struct node { // 有向图的点
    int num; // 点原始编号
} point[N];

struct edg { // 有向图的边
    int u, v;
    double cost;
} E[M];

double In[N]; // 点的最小入边
int ID[N]; // 记录点的新编号
int vis[N];
int pre[N];
int NV, NE;// 边和点的个数

double Directed_MST(int root) {
    double ret = 0;
    int i, u, v;
    while(true) {
        REP(i, NV)   In[i] = inf;
        REP(i, NE) {    //找最小入边
            u = E[i].u;
            v = E[i].v;
            if(E[i].cost < In[v] && u != v) {
                In[v] = E[i].cost;
                pre[v] = u;
            }
        }
        REP(i, NV) {    //如果存在除root以外的孤立点，则不存在最小树形图
            if(i == root)   continue;
            //printf("%.3lf ", In[i]);
            if(In[i] == inf)    return -1;
        }

        int cnt = 0;
        CL(ID, -1);
        CL(vis, -1);
        In[root] = 0;

        REP(i, NV) {    //找环
            ret += In[i];
            int v = i;
            while(vis[v] != i && ID[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && ID[v] == -1) {  //重新标号
                for(u = pre[v]; u != v; u = pre[u]) {
                    ID[u] = cnt;
                }
                ID[v] = cnt++;
            }
        }
        if(cnt == 0)    break;
        REP(i, NV) {
            if(ID[i] == -1) ID[i] = cnt++;    //重新标号
        }
        REP(i, NE) {    //更新其他点到环的距离
            v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if(E[i].u != E[i].v) {
                E[i].cost -= In[v];
            }
        }
        NV = cnt;
        root = ID[root];
    }
    return ret;
}

void test(){
    for (int i=0; i<7; i++){
        point[i].num = i;
    }

    int cnt = 0;
    E[cnt].u = 1; E[cnt].v = 2; E[cnt++].cost = 9;
    E[cnt].u = 4; E[cnt].v = 1; E[cnt++].cost = 3;
    E[cnt].u = 3; E[cnt].v = 5; E[cnt++].cost = 5;
    E[cnt].u = 2; E[cnt].v = 3; E[cnt++].cost = 3;
    E[cnt].u = 3; E[cnt].v = 2; E[cnt++].cost = 7;
    E[cnt].u = 2; E[cnt].v = 4; E[cnt++].cost = 9;
    E[cnt].u = 5; E[cnt].v = 4; E[cnt++].cost = 4;
    E[cnt].u = 6; E[cnt].v = 5; E[cnt++].cost = 3;
    E[cnt].u = 4; E[cnt].v = 3; E[cnt++].cost = 8;
    E[cnt].u = 4; E[cnt].v = 6; E[cnt++].cost = 5;
    E[cnt].u = 3; E[cnt].v = 6; E[cnt++].cost = 9;
    E[cnt].u = 3; E[cnt].v = 7; E[cnt++].cost = 6;
    E[cnt].u = 7; E[cnt].v = 3; E[cnt++].cost = 4;
    E[cnt].u = 6; E[cnt].v = 4; E[cnt++].cost = 4;
    E[cnt].u = 7; E[cnt].v = 6; E[cnt++].cost = 8;

    NE = cnt;
    NV = 7;
    cout << Directed_MST(0) << endl;
}


#endif //GRAPH_MINTREEGRAPH_H
