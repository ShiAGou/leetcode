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

void dfs(int p, VGraph* graph, vector<int> &maxp){
    vector<int> &v = graph->edges[p];
    vector<int> &w = graph->ws[p];
    for (int i=0; i<v.size(); i++){
        maxp[v[i]] = max(maxp[p], w[i]);
        dfs(v[i], graph, maxp);
    }
}


/**
 * use Prim algorithm to get second minimal spanning tree
 * 1. find the minimum spanning tree
 * 2. compute the maximum edge from node i to j
 * 3. try every edge i-j, add it and remove the maximum edge in the path i-j in the initial tree
 * @param graph
 */
void secondMinPrim(MGraph *graph){
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

    VGraph* minspan = new VGraph(vn);
    // create a new tree
    for (int i=1; i<vn; i++){
        cout << path[i] << " -- " << mst[path[i]] << ":" << matrix[path[i]][mst[path[i]]] << endl;
        minspan->addBiedge(path[i], mst[path[i]], matrix[path[i]][mst[path[i]]]);
        // remove so that we will not search it
        matrix[path[i]][mst[path[i]]] = 0;
    }
    // dfs it to find bottleneck edge
    vector<vector<int>> maxp(vn, vector<int>(vn, 0));
    for (int i=0; i<vn; i++){
        dfs(i, minspan, maxp[i]);
    }

    weight min = INT32_MAX;
    int mini=0, minj=1;
    for (int i=0; i<vn; i++){
        for (int j=i+1; j<vn; j++){
            // no i--j edge exists
            if (!matrix[i][j]) continue;
            weight dis = matrix[i][j]-maxp[i][j];
            if (dis < min){
                min = dis;
                mini = i, minj =j;
            }
        }
    }

    cout << "remove the edge of maximum weight from" << mini << " to "<< minj<<endl;

}

#endif //GRAPH_MINIMUMSPANNINGTREE_H
