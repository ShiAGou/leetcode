//
// Created by wesley shi on 2018/1/1.
//

#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H

#include "Digraph.h"
#include <iostream>
#include <queue>

using namespace std;

void DFS(int i, Vertex* list, bool* is_visited){
    Edge* e = list[i].head;
    is_visited[i] = true;
    while (e != nullptr){
        if (!is_visited[e->end]){
            DFS(e->end, list, is_visited);
        }
        e = e->next;
    }
    cout << i << endl;
}


void DFS(LGraph* graph){
    bool is_visited[graph->vn];
    memset(is_visited, 0, sizeof(is_visited));

    for (int i=0; i<graph->vn; i++){
        if (!is_visited[i]){
            DFS(i, graph->lists, is_visited);
        }
    }
}


void BFS(LGraph* graph){
    bool is_visited[graph->vn];
    memset(is_visited, 0, sizeof(is_visited));

    queue<int> que;

    for (int i=0; i<graph->vn; i++){
        if (!is_visited[i]){
            que.push(i);
            while (!que.empty()){
                is_visited[que.front()] = true;
                cout << que.front() << endl;
                Edge* e = graph->lists[que.front()].head;
                que.pop();
                while (e != nullptr){
                    que.push(e->end);
                    e = e->next;
                }
            }
        }
    }
}


void topological(LGraph *graph){
    // dfs...
}
#endif //GRAPH_SEARCH_H
