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

/*
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

    Tarjan(graph);
}

#include "Flow.h"

void testFlow(){
    LGraph* graph = new LGraph(4);
    graph->addEdge(0, 1, 999);
    graph->addEdge(0, 2, 999);
    graph->addEdge(1, 2, 1);
    graph->addEdge(1, 3, 999);
    graph->addEdge(2, 3, 999);
    weight max = Dinic(graph, 0, 3);
    cout << max << endl;
}


#include "2SAT.h"

void test2SAT(){
    // wait to test ...

}

#include "EulerCircuit.h"

void testEuler(){
    VGraph* graph = new VGraph(7);
    graph->addEdge(0,1);
    graph->addEdge(0,6);
    graph->addEdge(1,2);
    graph->addEdge(2,0);
    graph->addEdge(2,3);
    graph->addEdge(3,4);
    graph->addEdge(4,2);
    graph->addEdge(4,5);
    graph->addEdge(5,0);
    graph->addEdge(6,4);
    Hierholzer(graph);
}

#include "HamiltonianPath.h"

void testHamCycle(){
    MGraph* graph = new MGraph(4);
    graph->addEdge(0,1);
    graph->addEdge(1,0);
    graph->addEdge(0,3);
    graph->addEdge(3,0);
    graph->addEdge(0,2);
    graph->addEdge(2,0);
    graph->addEdge(1,2);
    graph->addEdge(2,1);
    graph->addEdge(3,2);
    graph->addEdge(2,3);

    hamiltonianPath(graph);
}
*/

#include "MinimumSpanningTree.h"

void testMinSpanningTree(){
    MGraph* graph = new MGraph(6);
    graph->addBiedge(0,1,6);
    graph->addBiedge(0,2,1);
    graph->addBiedge(0,3,5);
    graph->addBiedge(2,1,5);
    graph->addBiedge(2,3,5);
    graph->addBiedge(2,4,6);
    graph->addBiedge(2,5,4);
    graph->addBiedge(1,4,3);
    graph->addBiedge(3,5,2);

    Prim(graph);

    cout << "----------------------" << endl;

    VGraph* graph2 = new VGraph(7);
    graph2->addBiedge(0,1,7);
    graph2->addBiedge(0,3,5);
    graph2->addBiedge(1,3,9);
    graph2->addBiedge(1,2,8);
    graph2->addBiedge(1,4,7);
    graph2->addBiedge(2,4,5);
    graph2->addBiedge(3,4,15);
    graph2->addBiedge(3,5,6);
    graph2->addBiedge(4,5,8);
    graph2->addBiedge(5,6,11);
    graph2->addBiedge(4,6,9);
    Kruskal(graph2);

}

int main() {
    testMinSpanningTree();
    return 0;
}