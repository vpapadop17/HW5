#include "Dijkstra.h"
#include "BetterPriorityQueue.h"
#include <unordered_map>
#include <climits> // Gives us INT_MAX

using namespace std;

/*
 * Time Complexity: O(E * V log V)
 * - V is the number of nodes, E is the number of edges.
 * - Initializing distances takes O(V) time.
 * - Each node is popped from the queue at most once.
 * - For each popped node, we inspect its outward edges.
 * - Updating BPQ takes O(V log V) time because we rebuild/re-sort 
 *   the vector using push operations.
 * - Overall worst-case time complexity: O(E * V log V).
 */

int dijkstra(nodekey_t start, nodekey_t end, const Graph *g) {
    // Check 1: Ensure graph exists and both nodes are in the graph
    if (g == nullptr || !g->IsPresent(start) || !g->IsPresent(end)) {
        return -1; // Invalid request or missing node
    }

    // Check 2: Distance from a node to itself is 0
    if (start == end) {
        return 0;
    }
    
    unordered_map<nodekey_t, size_t> dist;
    BetterPriorityQueue q;

    // Get all nodes from the graph
    set<nodekey_t> nodes = g->GetNodes();
    
    for (nodekey_t n : nodes) {
		//if the node is the first one then to do to itself 0
        if (n == start) {
            dist[n] = 0;
            BPQNode startNode;
            startNode.gnode = n;
            startNode.pri = 0;
            q.push(startNode);
        } else {
			//we havent explored any paths so we dont know how to get to the node yet so INTMAX is a solution however not good for complexity 
            dist[n] = INT_MAX;
            BPQNode otherNode;
            otherNode.gnode = n;
            otherNode.pri = INT_MAX;
            q.push(otherNode);
        }
    }
    
    while (!q.empty()) {
        BPQNode current = q.top();
        q.pop();

        //nodes are disconnected so break 
        if (current.pri == INT_MAX) {
            break;
        }

        //this will return the shortest path as I have made it for the last/first in line node to be the one with the lowest priority
        if (current.gnode == end) {
            return dist[end];
        }

        set<const GraphEdge*> edges = g->GetOutwardEdgesFrom(current.gnode);
        
        for (const GraphEdge* edge : edges) {
            nodekey_t neighbor = edge->to;
            size_t weight = edge->weight;

            if (dist[current.gnode] + weight < dist[neighbor]) {
                dist[neighbor] = dist[current.gnode] + weight;

                BPQNode updateNode;
                updateNode.gnode = neighbor;
                updateNode.pri = dist[neighbor];

                q.Update(updateNode);
            }
        }
    }

    // If queue empties without reaching end node
    return -1;
}
