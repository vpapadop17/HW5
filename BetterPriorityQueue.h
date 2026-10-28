#ifndef BETTER_PRIORITY_QUEUE_H
#define BETTER_PRIORITY_QUEUE_H
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include "Graph.h"

using namespace std;

// Struct to store a node and its priority/distance
struct BPQNode {
    nodekey_t gnode = INVALID_NODE_KEY;
    
    //holds the priority distance value which represents the distance from the start node
    size_t pri = 0;
};

// Comparator for min-heap behavior (lowest priority value comes out first)
struct CompareBPQNode {
    bool operator()(const BPQNode& a, const BPQNode& b) const {
		//because the heap automatically has the highet priority we want to keep the lowest priority node first in line and thats how we do it 
        return a.pri > b.pri; // Min-heap: smaller pri = higher priority
    }
};

class BetterPriorityQueue : public priority_queue<BPQNode, vector<BPQNode>, CompareBPQNode> {
public:
    // Checks if a given node exists in the priority queue
    bool Contains(const BPQNode& node) const;

    // Updates a node's priority if the new priority is SMALLER
    // Returns true if updated, false if node not found or new priority >= current priority
    bool Update(const BPQNode& node);

    // Formats the heap contents into string format: [(6, pri: 0), (1, pri: 0), ...]
    string ToString() const;
};

#endif
