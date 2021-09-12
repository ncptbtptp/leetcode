/**********************************************************************************
 * https://leetcode.com/problems/redundant-connection/
 *
 * Auther: ncptbtptp
 *
 * Tip: Requires to return the "last edge" in input. Adj list built w/ the input order does not help
 *      because the last edge that "closes" the loop/cycle is not necessarily the same edge that
 *      appears in the last in input: e.g., (1,2), (1,3), (2,3) traversing in 1->2->3 order.
 *      The closing edge is (1,3) but the last edge of this loop in input is (2,3)
 *
 * Time:
 * Space:
 * Beat:
  **********************************************************************************/
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    string getKey(int first, int second)
    {
        return to_string(min(first, second)) + to_string(max(first, second));
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adjList(edges.size() + 1);
        // For each vertex, which edge is traversed next
        vector<int> next(edges.size() + 1, 0);
        //unordered_map<pair<int, int>, int> edgeOrder;
        unordered_map<string, int> edgeOrder;

        int order = 1;
        for (auto edge : edges)
        {
            // Undirected graph
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            edgeOrder[getKey(edge[0], edge[1])] = order;
            ++order;
        }        

        stack<int> s;
        vector<bool> visited(edges.size() + 1, false);
        s.push(edges[0][0]);
        visited[edges[0][0]] = true;

        int loopBegin = -1;
        while (!s.empty())
        {
            int current = s.top();

            // If all edges are visited, pop from the stack -- BLACK
            if (next[current] >= adjList[current].size())
            {
                s.pop();
                continue;
            }
            else
            {
                // Find the next edge of this vertex
                int nextVertex = adjList[current][next[current]];
                ++next[current];

                // Skip the "back edge" to parent to avoid looping
                if (s.size() > 1)
                {
                    s.pop();
                    int parent = s.top();
                    s.push(current);
                    // Next iteration shall find the next edge of the current vertex, if any
                    if (nextVertex == parent)
                        continue;
                }

                s.push(nextVertex);

                // Find a cycle
                if (visited[nextVertex])
                {
                    // Now stack has (STACK BOTTOM)...nextVertex...nextVertex(STACK TOP)
                    int maxOrder = 0;
                    int maxFirst = 0, maxSecond = 0;
                    int loopBegin = s.top();
                    int first(0), second(0);
                    while (!s.empty() && (first != loopBegin))
                    {
                        second = s.top();
                        s.pop();
                        first = s.top();
                        // Edge: first <--> second
                        int order = edgeOrder[getKey(first, second)];
                        if (order > maxOrder)
                        {
                            maxOrder = order;
                            maxFirst = first;
                            maxSecond = second;
                        }
                    }

                    return { min(maxFirst, maxSecond), max(maxFirst, maxSecond) };
                }
                else
                {
                    visited[nextVertex] = true;
                }
            }
        }

        // Not found which is not possible per problem description
        // Just for completeness
        return {};
    }
};

int main()
{
    Solution so;
    vector<vector<int>> edges = { {1,2}, {2,3}, {3,4}, {1,4}, {1,5} };
    vector<int> result = so.findRedundantConnection(edges);
    for (int i : result) cout << i << " ";
    cout << endl;
    return 0;
}