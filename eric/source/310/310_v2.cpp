#include <iostream>
#include <vector>
#include <unordered_map>

#include "310.h"

using namespace std;

class Solution {
public:
    using tAdjMap = unordered_map<int, vector<int>>;

    bool IsLeaf(tAdjMap::const_iterator iter) const
    {
        return (iter->second.size() == 1);
    }

    void RemoveLeaf(tAdjMap& adjList, tAdjMap::iterator& leaf)
    {
        // A tree's leaf must have exactly one neighbor
        if (leaf->second.empty()) {
            return;
        }

        // Remove node from the neighbor
        auto neiIter = adjList.find(leaf->second[0]);
        if (neiIter == adjList.end()) {
            return;
        }

        auto &neiAdjList = neiIter->second;
        for (auto it = neiAdjList.begin(); it != neiAdjList.end(); ++it) {
            if (*it == leaf->first) {
                neiAdjList.erase(it);
                break;
            }
        }

        // Remove node from the adj list itself
        adjList.erase(leaf);
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n == 1) {
            return {0};
        }

        if (n == 2) {
            return {0, 1};
        }

        tAdjMap adjList;
        for (auto edge : edges) {
			adjList[edge[0]].push_back(edge[1]);
			adjList[edge[1]].push_back(edge[0]);
        }

        while (adjList.size() > 2) {
			vector<tAdjMap::iterator> leaves;

            // Find all leaves in this round
            for (auto it = adjList.begin(); it != adjList.end(); ++it) {
                if (IsLeaf(it)) {
                    leaves.push_back(it);
                }
            }

            // Truncate all leaves/boundaries
            for (auto leaf : leaves) {
                RemoveLeaf(adjList, leaf);
            }
        }

        // One or two vertices
        vector<int> res;
        for (auto pa : adjList) {
            res.push_back(pa.first);
        }

        return res;
    }
};

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
{
    Solution so;
    return so.findMinHeightTrees(n, edges);
}