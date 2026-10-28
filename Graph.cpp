#include "Graph.h"
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std; 

bool Graph::IsPresent(nodekey_t key) const {
	
	//this fucntion returns 1 if the node is found and 0 if its not
    return nodes.count(key) == 1;

}

void Graph::AddNode(nodekey_t key) {
    if (IsPresent(key)) {
        throw invalid_argument("Node key already exists in graph.");
    }
    nodes.insert(key);
    nodeOrder.push_back(key);
}

set<nodekey_t> Graph::GetNodes() const {
    return nodes;
}

size_t Graph::Order() const {
    return nodes.size();
}

size_t Graph::Size() const {
    return allEdges.size();
}

const GraphEdge* Graph::AddEdge(nodekey_t fromNodekey, nodekey_t toNodekey, unsigned int weight) {
    if (!IsPresent(fromNodekey) || !IsPresent(toNodekey)) {
        throw invalid_argument("One or both nodes do not exist in the graph.");
    }
    
    // Check if the edge already exists
    if (adjacencyList.count(fromNodekey) > 0) {
        for (const GraphEdge* edge : adjacencyList.at(fromNodekey)) {
            if (edge->to == toNodekey) {
                throw invalid_argument("Edge already exists between these nodes.");
            }
        }
    }

    GraphEdge* newEdge = new GraphEdge{fromNodekey, toNodekey, weight};

    allEdges.push_back(newEdge);
    adjacencyList[fromNodekey].insert(newEdge);

    return newEdge;
}

set<const GraphEdge*> Graph::GetOutwardEdgesFrom(nodekey_t nodeKey) const {
    //make sure the node actually exists
    if (!IsPresent(nodeKey)) {
        throw invalid_argument("Node does not exist in graph.");
    }

    //check if this node has any edges stored in map
    if (adjacencyList.count(nodeKey) > 0) {
        return adjacencyList.at(nodeKey);
    }

    //if it exists but has no edges leaving it, return an empty set
    return set<const GraphEdge*>();
    
}

string Graph::NodesToString() const {
    string result = "[";
    bool first = true;
    for (nodekey_t node : nodeOrder) {
        if (!first) {
            result += ", ";
        }
        result += "(" + to_string(node) + ")";
        first = false;
    }
    result += "]";
    return result;
}

string Graph::EdgesToString() const {
    string result = "[";
    bool first = true;
    for (const GraphEdge* edge : allEdges) {
        if (!first) {
            result += ", ";
        }
        result += "((" + to_string(edge->from) + ")->(" + to_string(edge->to) + ") w:" + to_string(edge->weight) + ")";
        first = false;
    }
    result += "]";
    return result;
}

Graph::~Graph() {
	
    for (const GraphEdge* edge : allEdges) {
        delete edge;
    }
    allEdges.clear();
}




