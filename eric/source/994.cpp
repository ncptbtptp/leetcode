/**********************************************************************************
 * https://leetcode.com/problems/rotting-oranges/
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
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int nRows = grid.size(), nCols = grid[0].size();
        
        int time(-1);
        int nFresh = 0;
        // first pass: find out all rotten oranges and push to queue -- time 0
        for (int i = 0; i < nRows; ++i)
            for (int j = 0; j < nCols; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if ((grid[i][j] == 1))
                    ++nFresh;
            }
        
        // need to return early because zero fresh at the beginning (return 0)
        // is different than zero fresh left at the end (all fresh turned to rotten, return min height/time)
        if (nFresh == 0) return 0;
        
        pair<int, int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // rest passes: BFS, one level per time..
        // pre-cond:
        // 1- oranges in the queue are rotten
        // 2- time marks the time of oranges in queue that became rotten
        while (!q.empty()) {
            int size = q.size();
            
            // increment the time to respond to the time oranges in queue got rotten..
            ++time;
            for (int i = 0; i < size; ++i) {
                pair<int, int> curr = q.front();
                q.pop();
                
                int row(curr.first), col(curr.second);
                for(auto dir: dirs) {
                    int row_n(row + dir.first), col_n(col + dir.second);
                    // turned
                    if (row_n >= 0 && col_n >= 0 && row_n < nRows && col_n < nCols &&
                       grid[row_n][col_n] == 1) {
                        grid[row_n][col_n] = 2;
                        q.push({row_n, col_n});
                        --nFresh;
                    }
                }
            }
        }
        
        return nFresh ? -1 : time;        
    }
};

