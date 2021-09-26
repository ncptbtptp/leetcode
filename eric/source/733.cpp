/**********************************************************************************
 * https://leetcode.com/problems/flood-fill/
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

// An alternative is to not use the visited array if the oldColor != newColor.
// If oldColor == newColor, make sure we don't enter DFS otherwise it will revisit same nodes again and again,
// leading to stack overflow..
class Solution {
public:
    using tImage = vector<vector<int>>;
    //using tFlag = vector<vector<bool>>;
    
    tImage floodFill(tImage& image, int sr, int sc, int newColor) {
        tImage ans(image);        
        //tFlag visited(image.size(), vector<bool>(image[0].size(), false));
        
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
            fill(/*visited,*/ ans, sr, sc, oldColor, newColor);
        return ans;       
    }
    
    void fill(/*tFlag& visited,*/ tImage& image, int row, int col, int oldColor, int newColor) {
        
        //visited[row][col] = true;
        image[row][col] = newColor;
        
        if (row > 0 && /*!visited[row - 1][col] &&*/ image[row - 1][col] == oldColor)
            fill(/*visited,*/ image, row - 1, col, oldColor, newColor);
        
        if (row < image.size() - 1 && /*!visited[row + 1][col] &&*/ image[row + 1][col] == oldColor)
            fill(/*visited,*/ image, row + 1, col, oldColor, newColor);
        
        if (col > 0 && /*!visited[row][col - 1] &&*/ image[row][col - 1] == oldColor)
            fill(/*visited,*/ image, row, col - 1, oldColor, newColor);
        
        if (col < image[0].size() - 1 && /*!visited[row][col + 1] &&*/ image[row][col + 1] == oldColor)
            fill(/*visited,*/ image, row, col + 1, oldColor, newColor);
    }
};


