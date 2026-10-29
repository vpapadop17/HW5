#include "BetterPriorityQueue.h"
#include <algorithm>

using namespace std;

bool BetterPriorityQueue::Contains(const BPQNode& node) const {
    // this->c is the internal vector storing the heap items
    for (const BPQNode& item : this->c) {
        if (item.gnode == node.gnode) {
            return true;
        }
    }
    return false;
}

bool BetterPriorityQueue::Update(const BPQNode& node) {
    for (BPQNode& item : this->c) {
        if (item.gnode == node.gnode) {
            if (node.pri < item.pri) {
                item.pri = node.pri;

                BetterPriorityQueue tempQueue;
                for (const BPQNode& queueItem : this->c) {
                    tempQueue.push(queueItem);
                }
                *this = tempQueue;
                return true; 
            }
            return false; // Found the node, but its new priority wasn't smaller
        }
    }

    return false; // Node wasn't found in the queue
}

string BetterPriorityQueue::ToString() const {
    string result = "[";
    bool first = true;
    for (const BPQNode& item : this->c) {
        if (!first) {
            result += ", ";
        }
        result += "(" + to_string(item.gnode) + ", pri: " + to_string(item.pri) + ")";
        first = false;
    }
    result += "]";
    return result;
}
