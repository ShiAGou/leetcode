//
// Created by wesley shi on 2018/1/3.
//

#ifndef GRAPH_2SAT_H
#define GRAPH_2SAT_H

#include "Digraph.h"
#include <stack>

const int maxn = 10000;

int flag[maxn] = {0}, dfn[maxn]={0}, low[maxn] ={0}, tpArr[maxn]={0};
int tpNum = 0, _index = 0;
stack<int> st;


void Tarjan(int n, VGraph *graph){
    st.push(n);
    flag[n] = 1; // has been visited
    dfn[n] = ++_index;
    low[n] = _index; // important! suppose for a tree, every node will be a component
    vector<int> &es = graph->edges[n];
    for (int i=0; i < es.size(); i++){
        if (dfn[es[i]] == 0){
            Tarjan(es[i], graph);
            low[n] = min(low[es[i]], low[n]);
        } else if (flag[es[i]] == 1){
            // for node that has been visited
            low[n] = min(low[n], dfn[es[i]]);
        }
    }

    if (dfn[n] == low[n]){
        tpNum ++; // the component index
        do {
            n = st.top();
            st.pop();
            flag[n] = 0; // line 11: we do not need to consider the node in further searching
            tpArr[n] = tpNum;
        } while (dfn[n] != low[n]); // pop until meet current node
    }
}


void addMutex(int n1, int n2, int state, vector<int> &edges[]){
    if (state) {
        // if n1,n2 can not be open at the same time
        // n1 open, n2 must close
        edges[n1<<1&1].push_back(n2<<1);
        // n2 open, n1 must close
        edges[n2<<1&1].push_back(n1<<1);
    }else{
        edges[n1<<1].push_back(n2<<1&1);
        edges[n2<<1].push_back(n1<<1&1);
    }
}

bool judge(int N){
    for (int i = 0; i < N; i++) {
        // if the components of two states of any switch are the same one, failure.
        if (tpArr[2*i+1] == tpArr[2*i]) {
            return false;
        }
    }
    return true;
}

/**
 * 2-SAT problem
 * judge whether N switches have a solution satisfying all mutex
 * @param N
 * @param T
 * @param mutex mutex relation of switchs.
 *  mutex[i][0],mutex[i][1] is two switch, mutex[i][2] is relation, close(0)/open(1)
 * @return
 */
bool TwoSAT(int N, int T, int** mutex){
    // for switch i, i*2 means the close state, i*2+1 means the open state
    VGraph* graph = new VGraph(2*N);
    for (int i=0; i<T; i++){
        if (mutex[i][2]){
            addMutex(mutex[i][0], mutex[i][1], mutex[i][2], graph->edges);
        }
    }

    for (int i=0; i<2*N; i++){
        if (!dfn[i]){
            Tarjan(i, graph);
        }
    }

    return judge(N);
}

#endif //GRAPH_2SAT_H
