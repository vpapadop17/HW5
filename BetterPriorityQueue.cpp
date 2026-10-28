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
    bool foundAndUpdated = false;

    
    for (BPQNode& item : this->c) {
        if (item.gnode == node.gnode) {
            if (node.pri < item.pri) {
                item.pri = node.pri;
                foundAndUpdated = true;
            }
            break;
        }
    }

    
    if (foundAndUpdated) {
        BetterPriorityQueue tempQueue;
        for (const BPQNode& item : this->c) {
            tempQueue.push(item);
        }
        *this = tempQueue; // Overwrite current queue with the re-ordered queue
        return true;
    }

    return false;
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
