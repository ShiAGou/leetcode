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

    void addEdge(int x, int y, weight w){
        matrix[x][y] = w;
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

#endif //GRAPH_GRAPH_H
