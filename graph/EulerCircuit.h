//
// Created by wesley shi on 2018/1/4.
//

#ifndef GRAPH_EULERCIRCUIT_H
#define GRAPH_EULERCIRCUIT_H

#include "Digraph.h"
#include <stack>
#include <iostream>

/**
 * Hierholzer's algorithm
 * @param graph
 */
void Hierholzer(VGraph *graph){
    int edge_count[graph->vn];
    memset(edge_count, 0, sizeof(edge_count));
    vector<int>* adj = graph->edges;
    for (int i=0; i<graph->vn; i++)
    {
        //find the count of edges to keep track
        //of unused edges
        edge_count[i] = adj[i].size();
    }

    stack<int> cur_path;
    vector<int> circuit;

    int cur_v = 0;
    cur_path.push(cur_v);

    while (!cur_path.empty()){
        if (!edge_count[cur_v]){
            // no edges left in current vertex
            circuit.push_back(cur_v);
            cur_v = cur_path.top();
            cur_path.pop();
        } else {
            // find a circuit from cur_v
            cur_path.push(cur_v);

            int next = adj[cur_v].back();
            edge_count[cur_v]--;
            adj[cur_v].pop_back();

            cur_v = next;
        }
    }

    for (int i=circuit.size()-1; i>=0; i--){
        cout << circuit[i];
        if (i) cout << " -> ";
    }
}

#endif //GRAPH_EULERCIRCUIT_H
