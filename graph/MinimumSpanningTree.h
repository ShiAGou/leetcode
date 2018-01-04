//
// Created by wesley shi on 2018/1/4.
//

#ifndef GRAPH_MINIMUMSPANNINGTREE_H
#define GRAPH_MINIMUMSPANNINGTREE_H

#include "Digraph.h"

#include <iostream>

/**
 * a coarse implementation of prim algorithm
 * time complexity: O(n^2)
 * @param graph
 */
void Prim(MGraph *graph){
    int vn = graph->vn;
    int** matrix = graph->matrix;
    weight lowcost[vn];
    int mst[vn], path[vn];
    memset(mst, 0, sizeof(mst));
    memset(path, 0, sizeof(path));
    memset(lowcost, 0, sizeof(lowcost));

    // add node 0 to the set
    path[0] = 0;
    lowcost[0] = -1;

    for (int i=1; i<vn; i++){
        int cur = path[i-1];
        int mn = INT32_MAX;
        int next=-1;
        for (int j=0; j<vn; j++){
            if (matrix[cur][j] && (lowcost[j] == 0 || matrix[cur][j] < lowcost[j])){
                lowcost[j] = matrix[cur][j];
                mst[j] = cur;
            }
            if (lowcost[j] > 0 && mn > lowcost[j]){
                mn = lowcost[j];
                next = j;
            }
        }
        if (next == -1){
            cout << "err";
            return;
        }
        path[i] = next;
        lowcost[next] = -1;
    }
    for (int i=1; i<vn; i++){
        cout << path[i] << " -- " << mst[path[i]] << ":" << matrix[path[i]][mst[path[i]]] << endl;
    }
}


struct line{
    int n1,n2;
    weight w;
    line(int n1, int n2, weight w){
        this->n1=n1;
        this->n2=n2;
        this->w=w;
    }
};

bool cmp(line l1, line l2){
    return l1.w < l2.w;
}

int find(int a, int parent[]){
    int p = parent[a];
    if (p == a){
        return p;
    }
    parent[a] = find(p, parent);
    return parent[a];
}

void join(int a, int b, int parent[]){
    int pa = find(a, parent);
    int pb = find(b, parent);
    if (pa != pb){
        parent[pa] = pb;
    }
}

void Kruskal(VGraph *graph){
    vector<line> lines;
    int parent[graph->vn];
    for (int i=0; i<graph->vn; i++){
        vector<int> &e = graph->edges[i];
        vector<int> &w = graph->ws[i];
        parent[i] = i;
        for (int j=0; j<e.size(); j++){
            lines.emplace_back(i, e[j], w[j]);
        }
    }

    sort(lines.begin(), lines.end(), cmp);
    vector<line> path;

    int cnt = 0;
    for (int i=0; i<lines.size() && cnt<graph->vn-1; i++){
        line &l = lines[i];
        int p1 = find(l.n1, parent);
        int p2 = find(l.n2, parent);
        if (p1 == p2) continue;
        join(p1, p2, parent);
        path.push_back(l);
    }

    for (int i=0; i<graph->vn-1; i++){
        cout << path[i].n1 << " -- " << path[i].n2 << ":" << path[i].w <<endl;
    }
}

#endif //GRAPH_MINIMUMSPANNINGTREE_H
