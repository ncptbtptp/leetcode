/**********************************************************************************
 * https://leetcode.com/problems/max-area-of-island/
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time:
 * Space:
 * Beat:
  **********************************************************************************/
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& map) {
        vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
        int maxSize = 0;
        for (int row = 0; row < map.size(); ++row) {
            for (int col = 0; col < map[0].size(); ++col) {
                if (!visited[row][col]) {
                    maxSize = std::max(maxSize, dfs(map, visited, row, col));
                }
                    
            }
        }
        return maxSize;
    }
    
    // Return the island size from all nodes 4-directionally connected to [row, col]
    int dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int row, int col) {
        if (map[row][col] == 0)
            return 0;
        
        if (visited[row][col])
            return 0;
        
        visited[row][col] = true;
        
        int up(0), down(0), left(0), right(0);
        if (row > 0) up = dfs(map, visited, row - 1, col);
        if (row < map.size() - 1) down = dfs(map, visited, row + 1, col);
        if (col > 0) left = dfs(map, visited, row, col - 1);
        if (col < map[0].size() - 1) right = dfs(map, visited, row, col + 1);
        
        return up + down + left + right + 1;            
    }
};


