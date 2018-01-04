//
// Created by wesley shi on 2018/1/1.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include <vector>

typedef int weight;

using namespace std;

class MGraph{
public:
    int vn;
    weight ** matrix;
    MGraph(int vn){
        this->vn = vn;
        matrix = new weight*[vn];
        for (int i=0; i<vn; i++){
            matrix[i] = new weight[vn];
            memset(matrix[i], 0, sizeof(weight)*vn);
        }
    }

    void addEdge(int x, int y, weight w=1){
        matrix[x][y] = w;
    }

    void addBiedge(int x, int y, weight w=1){
        matrix[x][y] = w;
        matrix[y][x] = w;

    }

    ~MGraph(){
        for (int i=0; i<vn; i++){
            delete[](matrix[i]);
        }
        delete[](matrix);
    }
};

struct Edge{
    int end;
    weight w;
    Edge *next = nullptr;
    Edge *rev = nullptr;
};

struct Vertex{
    int index;
    Edge* head = nullptr;
};

class LGraph{
public:
    int vn;
    Vertex* lists;
    LGraph(int vn){
        this->vn = vn;
        lists = new Vertex[vn];
        for (int i=0; i<vn; i++){
            lists[i].index = i;
        }
    }

    Edge* addEdge(int x, int y, weight w){
        auto *e = new Edge;
        e->end = y;
        e->w = w;
        e->next = lists[x].head;
        lists[x].head = e;
        return e;
    }

    LGraph* reverse(){
        auto result = new LGraph(vn);
        for (int i=0; i<vn; i++){
            Edge *e = lists[i].head;
            while (e != nullptr){
                result->addEdge(e->end, i, e->w);
                e = e->next;
            }
        }
        return result;
    }

    ~LGraph(){
        delete[](lists);
    }
};


class VGraph{
public:
    const int maxn = 1000;
    int vn;
    vector<int> edges[1000];
    vector<int> ws[1000];

    VGraph(int vn){
        this->vn = vn;
    }

    void addEdge(int a1, int a2, weight w=1){
        edges[a1].push_back(a2);
        ws[a1].push_back(w);
    }

    void addBiedge(int a1, int a2, weight w=1){
        edges[a1].push_back(a2);
        ws[a1].push_back(w);
        edges[a2].push_back(a1);
        ws[a2].push_back(w);
    }

};

#endif //GRAPH_GRAPH_H
