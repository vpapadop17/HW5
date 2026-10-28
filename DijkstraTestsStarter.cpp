
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

#include <iostream>
#include <cassert>

using namespace std;


int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	g->AddNode(1);
	g->AddNode(2);
	g->AddNode(3);
	
	g->AddEdge(1, 2, 7);
	g->AddEdge(2, 1, 7);
	g->AddEdge(1, 3, 9);
	g->AddEdge(3, 1, 9);

	
	cout <<  "---Graph---" << endl;
	cout << "\tnodes: " << g->NodesToString() << endl;
	cout << "\tedges: " << g->EdgesToString() << endl;
	cout << "---Graph---" << endl << endl;

	nodekey_t start = 1;
	nodekey_t end = 3;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	int ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 9);
	
	assert(dijkstra(1, 1, g) == 0);

    
    assert(dijkstra(1, 99, g) == -1);
    
    g->AddNode(4);
    g->AddNode(5);
    g->AddNode(6);

    g->AddEdge(1, 6, 14); g->AddEdge(6, 1, 14);
    g->AddEdge(2, 3, 10); g->AddEdge(3, 2, 10);
    g->AddEdge(2, 4, 15); g->AddEdge(4, 2, 15);
    g->AddEdge(3, 4, 11); g->AddEdge(4, 3, 11);
    g->AddEdge(3, 6, 2);  g->AddEdge(6, 3, 2);
    g->AddEdge(6, 5, 9);  g->AddEdge(5, 6, 9);
    g->AddEdge(4, 5, 6);  g->AddEdge(5, 4, 6);
    
    nodekey_t start2 = 1;
	nodekey_t end2 = 5;

	int ans2 = dijkstra(start2, end2, g);
	cout << "Output from Dijkstra(" << to_string(start2) << ", " << to_string(end2) << ") => " << ans2 << endl;
	assert(ans2 == 20);

	delete g;
	
	cout << "DONE with basic testing of Dijkstra algorithm" << endl;
	
	return ans;
}



int main(){
	
	DijkstraTest(); // this one by itself tests the graph on the assignment
	cout << endl;
	cout << "ALL TESTS PASSED!" << endl;

	return 0;
}
