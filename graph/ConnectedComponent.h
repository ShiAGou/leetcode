//
// Created by wesley shi on 2018/1/2.
//

#ifndef GRAPH_CONNECTEDCOMPONENT_H
#define GRAPH_CONNECTEDCOMPONENT_H

#include <iostream>
#include <stack>
#include "Digraph.h"

void rank_dfs(int node, int &cur, int *old, bool *is_visited, Vertex *lists){
    is_visited[node] = true;
    Edge* e = lists[node].head;
    while (e != nullptr){
        if (is_visited[e->end]) {
            e = e->next;
            continue;
        }
        rank_dfs(e->end, cur, old, is_visited, lists);
        e = e->next;
    }
    old[node] = cur;
    cur++;
}

void search_dfs(int node, bool *is_visited, Vertex* lists){
    cout << node << " ";
    is_visited[node] = true;
    Edge* e = lists[node].head;
    while (e != nullptr){
        if (is_visited[e->end]) {
            e = e->next;
            continue;
        }
        search_dfs(e->end, is_visited, lists);
        e = e->next;
    }
}


void Korasaju(LGraph* graph){
    int vn = graph->vn;
    int old[vn], rev_old[vn];
    bool is_visited[vn];
    memset(old, 0, sizeof(old));
    memset(is_visited, 0, sizeof(is_visited));
    int cur = 0;
    for (int i=0; i<vn; i++){
        if (!is_visited[i]){
            rank_dfs(i, cur, old, is_visited, graph->lists);
        }
    }
    for (int i=0; i<vn; i++){
        rev_old[vn -old[i] -1] = i;
    }
    memset(is_visited, 0, sizeof(is_visited));
    LGraph* rev_graph = graph->reverse();
    for (int i=0; i<vn; i++){
        if (!is_visited[rev_old[i]]){
            search_dfs(rev_old[i], is_visited, rev_graph->lists);
            cout << endl;
        }
    }
    delete(rev_graph);
}

void tarjan_dfs(int node, int &cur, int* rank, int* low, Vertex* lists, stack<int>* stck){
    rank[node] = cur;
    low[node] = INT32_MAX;//有bug，应该设为cur
    stck->push(node);
    cur++;
    Edge* e = lists[node].head;
    while (e != nullptr){
        // haven't visited
        if (!rank[e->end]) {
            tarjan_dfs(e->end, cur, rank, low, lists, stck);
            low[node] = min(low[node], low[e->end]);
        } else if (rank[e->end] > 0){
            // if the end has been visited and not popped out
            low[node] = min(low[node], rank[e->end]);
        }
        e = e->next;
    }

    if (rank[node] == low[node] || low[node] == INT32_MAX){
        while (!stck->empty() && stck->top() != node){
            cout << stck->top() << " ";
            rank[stck->top()] = -1;
            stck->pop();
        }
        cout << node << endl;
        rank[node] = -1;
        stck->pop();
    }
}


void Tarjan(LGraph* graph){
    int vn = graph->vn;
    int rank[vn], low[vn];
    memset(rank, 0, sizeof(rank));
    stack<int> stck;
    int cur = 1;
    for (int i=0; i<vn; i++){
        if (!rank[i]){
            tarjan_dfs(i, cur, rank, low, graph->lists, &stck);
        }
    }
}

#endif //GRAPH_CONNECTEDCOMPONENT_H
