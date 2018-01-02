//
// Created by wesley shi on 2018/1/1.
//

#ifndef GRAPH_CUT_H
#define GRAPH_CUT_H

#include <vector>
#include <iostream>
#include "Undigraph.h"

using namespace std;

/**
 *
 * @param cur current node index
 * @param parent its parent index
 * @param root the root index
 * @param index current time
 * @param matrix edge matrix of the graph
 * @param num ...
 * @param low ...
 * @param vn number of vertexes
 * @param is_node to get the cut vertex or cut edge
 */
void dfs(int cur, int parent, int root, int index, int** const matrix, int* const num, int* const low, const int vn
        , bool is_node){
    int child=0;
    index++;
    num[cur] = index;
    low[cur] = index;
    for (int i=0; i<vn; i++){
        if (!matrix[cur][i]) continue;
        if (!num[i]){
            // node i haven't been visited
            child++;
            dfs(i, cur, root, index, matrix, num, low, vn, is_node);
            low[cur] = min(low[i], low[cur]);
            if (is_node){
                if (cur != root && low[i] >= num[cur]){
                    cout << cur << endl;
                } else if (cur == root && child == 2){
                    cout << cur << endl;
                }
            } else {
                if (cur != root && low[i] > num[cur]){
                    cout << cur << " -- " << i << endl;
                } else if (cur == root && child == 2){
                    cout << cur << " -- " << i << endl;
                }

            }
        } else if (i!=parent){
            low[cur] = min(low[cur], num[i]);
        }
    }
}

void cutNode(MGraph* graph){
    /**
     * num[]: the visiting time of the node
     * low[]: the minimum time of nodes one node can reach
     */
    int num[graph->vn], low[graph->vn];
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    dfs(0, 0, 0, 0, graph->matrix, num, low, graph->vn, true);
}

void cutEdge(MGraph* graph){
    int num[graph->vn], low[graph->vn];
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    dfs(0, 0, 0, 0, graph->matrix, num, low, graph->vn, false);
}



#endif //GRAPH_CUT_H
