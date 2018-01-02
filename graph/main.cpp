#include <iostream>


/*
void testSearch(){
    auto graph = new LGraph(5);
    graph->addEdge(0,1,1);
    graph->addEdge(0,2,1);
    graph->addEdge(1,3,1);
    cout << "BFS" << endl;
    BFS(graph);

    cout << "DFS" << endl;
    DFS(graph);
}

#include "Cut.h"
void testCut(){
    auto graph = new MGraph(6);
    graph->addEdge(0,3,1);
    graph->addEdge(0,2,1);
    graph->addEdge(3,1,1);
    graph->addEdge(2,1,1);
    graph->addEdge(1,4,1);
    graph->addEdge(1,5,1);
    graph->addEdge(4,5,1);
    cutNode(graph);
    cutEdge(graph);
}
 */

#include "ConnectedComponent.h"

void testStrongComponent(){
    LGraph *graph = new LGraph(10);
    graph->addEdge(0,2,1);
    graph->addEdge(2,3,1);
    graph->addEdge(2,1,1);
    graph->addEdge(2,4,1);
    graph->addEdge(1,0,1);
    graph->addEdge(1,3,1);
    graph->addEdge(3,5,1);
    graph->addEdge(4,5,1);
    graph->addEdge(4,6,1);
    graph->addEdge(5,7,1);
    graph->addEdge(5,3,1);
    graph->addEdge(6,4,1);
    graph->addEdge(6,7,1);
    graph->addEdge(7,7,1);
    graph->addEdge(8,9,1);
    graph->addEdge(9,8,1);

    /*
    Korasaju(graph);
    LGraph *graph = new LGraph(4);
    graph->addEdge(0,1,1);
    graph->addEdge(1,2,1);
    graph->addEdge(2,0,1);
     */
    Tarjan(graph);
}

int main() {
    testStrongComponent();
    return 0;
}