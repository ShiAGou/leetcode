//
// Created by wesley shi on 2018/1/1.
//

#ifndef GRAPH_UNDIGRAPH_H
#define GRAPH_UNDIGRAPH_H

#include <vector>

typedef int weight;

using namespace std;

class MGraph {
public:
    int vn;
    weight **matrix;

    MGraph(int vn) {
        this->vn = vn;
        matrix = new weight *[vn];
        for (int i = 0; i < vn; i++) {
            matrix[i] = new weight[vn];
            memset(matrix[i], 0, sizeof(weight) * vn);
        }
    }

    void addEdge(int x, int y, weight w) {
        matrix[x][y] = w;
        matrix[y][x] = w;
    }

    ~MGraph() {
        for (int i = 0; i < vn; i++) {
            delete[](matrix[i]);
        }
    }
};


#endif //GRAPH_UNDIGRAPH_H
