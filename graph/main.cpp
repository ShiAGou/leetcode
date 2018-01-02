#include <iostream>

#include "Cut.h"

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
 */

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

int main() {
    testCut();
    return 0;
}