/**********************************************************************************
 * https://leetcode.com/problems/01-matrix/
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        
        queue<pair<int, int>> q;       
        int nRows = mat.size(), nCols = mat[0].size();
        
        // Find all zeros as the 1st round
        for (int i = 0; i < nRows; ++i)
            for (int j = 0; j < nCols; ++j)
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
        

        pair<int, int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // From distance 1 and onwards, till all ans cells are filled
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            int row = curr.first, col = curr.second;
            int dist = ans[row][col];
            
            for (pair<int, int> dir : dirs) {
                int newRow = row + dir.first, newCol = col + dir.second;
                if (newRow >= 0 && newRow < nRows && newCol >= 0 && newCol < nCols &&
                   ans[newRow][newCol] > dist + 1) {
                    ans[newRow][newCol] = dist + 1;
                    q.push({newRow, newCol});
                }                   
            }
        }
        
        return ans;        
    } 
};

