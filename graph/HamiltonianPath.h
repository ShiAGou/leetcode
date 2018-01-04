//
// Created by wesley shi on 2018/1/4.
//

#ifndef GRAPH_HAMILTONIANPATH_H
#define GRAPH_HAMILTONIANPATH_H

#include "Digraph.h"

#include <stack>
#include <iostream>


bool util(weight** edges, int path[], bool is_visited[], int pos, const int vn){
    if (pos == vn-1){
        return edges[path[pos]][path[0]] != 0;
    }

    for (int v = 0; v < vn; v++){
        if (v == path[0] || v == path[pos] || is_visited[v] || edges[path[pos]][v]==0) continue;
        // suppose that the next node is v
        path[pos+1] = v;
        is_visited[v]= true;
        if (util(edges, path, is_visited, pos+1, vn)){
            return true;
        }
        path[pos+1]=-1;
        is_visited[v]=false;
    }
    return false;
}

void hamiltonianPath(MGraph* graph){
    int path[graph->vn];
    bool is_visited[graph->vn];
    memset(path, -1, sizeof(path));
    memset(is_visited, 0, sizeof(is_visited));
    path[0] = 0;
    is_visited[0] = true;
    if (util(graph->matrix, path, is_visited, 0, graph->vn)){
        for (int i=0; i<graph->vn; i++){
            cout << path[i];
            if (i < graph->vn-1){
                cout << " -> ";
            }
        }
    }else {
        cout << "no Hamiltonian path!";
    }

}

#endif //GRAPH_HAMILTONIANPATH_H
