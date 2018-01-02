//
// Created by wesley shi on 2018/1/2.
//

#ifndef GRAPH_FLOW_H
#define GRAPH_FLOW_H

#include "Digraph.h"
#include <queue>

bool bfs(LGraph *graph, int s, int t, int *depth){
    queue<int> que;
    int vn = graph->vn;
    memset(depth, 0, sizeof(int)*vn);
    depth[s] = 1;
    que.push(s);
    while (!que.empty()){
        int u=que.front();
        que.pop();
        Edge* e = graph->lists[u].head;
        while (e != nullptr){
            if (e->w > 0 && depth[e->end] == 0){
                depth[e->end] = depth[u]+1;
                que.push(e->end);
            }
            e = e->next;
        }
    }
    return depth[t] != 0;
}

weight dfs(int node, weight flow, const int t, LGraph* graph, int* depth){
    if (node == t){
        return flow;
    }
    Edge* e = graph->lists[node].head;
    while (e != nullptr){
        if (depth[e->end] == depth[node]+1 && e->w != 0){
            int f = dfs(e->end, min(e->w, flow), t, graph, depth);
            if (f > 0){
                e->w -= f;
                e->rev->w += f;
                return f;
            }
        }
        e = e->next;
    }
    return 0;
}

/**
 * Dinic algorithm
 * @param graph
 * @return value of maxflow
 */
weight Dinic(LGraph* graph, int s, int t){
    int vn = graph->vn;
    LGraph* capacity = new LGraph(vn);
    for (int i=0; i<vn; i++){
        Edge* e = graph->lists[i].head;
        while (e != nullptr){
            Edge* e1 = capacity->addEdge(i, e->end, e->w);
            Edge* e2 = capacity->addEdge(e->end, i, 0);
            e1->rev = e2;
            e2->rev = e1;
            e = e->next;
        }
    }

    weight sum = 0;
    int depth[vn];

    while (bfs(capacity, s, t, depth)){
        while (weight d = dfs(s, INT32_MAX, t, capacity, depth)){
            sum += d;
        }
    }

    delete(capacity);
    return sum;
}
#endif //GRAPH_FLOW_H
