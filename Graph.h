#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <unordered_map>


using namespace std;
// nodes are essentially just their key value
// These are special commands which define 
//						"nodekey_t" to mean "unsigned long long int"
// 						"INVALID_NODE_KEY" to mean "UULONG_MAX" (where ULONG_MAX = 18446744073709551615) 

#define nodekey_t unsigned long long int
#define INVALID_NODE_KEY ULLONG_MAX

// when coding, be careful to ensure that every instance of
// a GraphEdge is created on the heap

struct GraphEdge { 
	nodekey_t from;
	nodekey_t to;
	unsigned int weight;
};


class Graph{
	
	public: 
		//Graph (); // you may add this, it is ungraded 
		//Graph (const Graph&); // you may add this, it is ungraded
		~Graph () ;
	
		// both of these should throw an invalid argument exception if invalid inputs are given
		// such as a duplicate node key or a node key that doesn't exist in the graph
		void AddNode (nodekey_t key = 0);
		const GraphEdge* AddEdge(nodekey_t fromNodekey, nodekey_t toNodekey, unsigned int weight = 0);
	
		// this method returns true if the given key is in use in the graph
		bool IsPresent (nodekey_t key) const;
	
		// These are not actually used except for testing / debugging 
		string NodesToString() const; // all nodes
		string EdgesToString() const; // all edges
	
		// These next two functions both return a set since the order shouldn't matter
		// (theoretically, a graph has no order)
		// get pointers to the edges that go out from the given node 
		set<const GraphEdge*> GetOutwardEdgesFrom(nodekey_t nodeKey) const;
		set<nodekey_t> GetNodes () const; // gets all the nodes in the graph
	
		// set<const GraphEdge*> GetEdges () const; // gets all edges in the graph (), you may add this it is ungraded 
		size_t Size() const; // num edges
		size_t Order() const; // num nodes
		
	private:
		
		
		set<nodekey_t> nodes;
		
		//I need the adjacency list so I can know and store all the edges pointing away from it, basically what it connect to 
		unordered_map<nodekey_t, set<const GraphEdge*>> adjacencyList;
		
		vector<const GraphEdge*> allEdges;
		
		vector<nodekey_t> nodeOrder; //without that the assertion was not working so we need to keep track fo the order in which the nodes were added 
		
		
		
};


#endif
