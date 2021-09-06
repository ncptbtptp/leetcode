/**********************************************************************************
 * https://leetcode.com/problems/number-of-provinces/
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time: 
 * Space: 
 * Beat: 
 * Think: how about directed graph?? (a->c, b->c)
 **********************************************************************************/
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    // Returns true if traversed at least one vertex
    bool DFS(vector<vector<int>>& isConnected, vector<bool>& visited, int start)
    {
        if (visited[start]) return false;

        stack<int> s;
        s.push(start);

        while (!s.empty())
        {
            int city = s.top();
            s.pop();

            if (!visited[city])
            {
                visited[city] = true;

                // Move to outter??
                for (int i = 0; i < isConnected[city].size(); ++i)
                    if ((isConnected[city][i] == 1) /*&& (!visited[i])*//* && (i != city)*/)
                        s.push(i);
            }
        }
        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int nProvinces = 0;
        vector<bool> visited(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); ++i)
            if (DFS(isConnected, visited, i))
                ++nProvinces;

        return nProvinces;
    }
};

int main()
{
    vector<vector<int>> isConnected = { {1,0,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,1,1} };
    Solution so;
    cout << so.findCircleNum(isConnected) << endl;
    return 0;
}