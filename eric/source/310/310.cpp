#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // If single node, return itself
        if (edges.empty())
            return {0};

        // Build adj list
        m_adjList.resize(n);
        for (auto edge : edges) {
            m_adjList[edge[0]].push_back(edge[1]);
            m_adjList[edge[1]].push_back(edge[0]);
        }

        // Any start vertex will do, let's just start from 0
        int diameterBegin = BFS(n, 0, false);

        // Case 2: Else, find the longest path from this node.
        // Just find any longest path from this node. The middle node can be 1 or 2 nodes
        int diameterEnd = BFS(n, diameterBegin, true);

        // Could be multiple bottom leaves, but the middle of the longest paths MUST be shared
        return GetMHTRoots(diameterEnd);
    }

    vector<int> GetMHTRoots(int diameterEnd)
    {
        // Count # of nodes in diameter
        int height = 0;
        int vertex = diameterEnd;
        while (vertex != -1) {
            ++height;
            vertex = m_parents[vertex];
        }

        int steps = (height - 1) / 2;
        vertex = diameterEnd;
        while (steps > 0) {
            vertex = m_parents[vertex];
            --steps;
        }

        vector<int> res;
        res.push_back(vertex);

        if (height % 2 == 0) {
            res.push_back(m_parents[vertex]);
        }

        return res;
    }

    bool IsLeaf(int vertex) const
    {
        // The single node case (adj size = 0) is already ruled out
        return (m_adjList[vertex].size() == 1);
    }

    // Run BFS from node "start", return the last bottom leaf
    int BFS(int n, int start, bool buildParents)
    {
        // Tree is acyclic, but we need the "visited" to avoid going back to the parent
        vector<bool> visited(n, false);

        if (buildParents) {
            m_parents.resize(n, -1);
        }

        queue<int> q;
        q.push(start);

        int lastLeaf = -1;
        while(!q.empty()) {
             int current = q.front();
             q.pop();
             visited[current] = true;

             for (int next : m_adjList[current]) {
                if (!visited[next]) {
                    q.push(next);
                     if (buildParents)
                        m_parents[next] = current;
                }
             }

             // This is the last leaf in bottom, return it
             if (q.empty()) {
                 lastLeaf = current;
             }
        }

        return lastLeaf;
    }

    // Adjacency list of node 0 to N-1
    vector<vector<int>> m_adjList;
    vector<int> m_parents;
};

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
{
    Solution so;
    return so.findMinHeightTrees(n, edges);
}