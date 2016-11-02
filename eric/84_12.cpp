#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   int largestRectangleArea(vector<int>& heights)
   {
      if (heights.empty()) {
         return 0;
      }

      return maxArea(heights, 0, heights.size() - 1);
   }

   int maxArea(vector<int>& heights, int left, int right)
   {
      if (left == right) {
         return heights[left];
      }

      int res = 0;
      int m = (left + right) / 2;
      res = std::max(maxArea(heights, left, m), res);
      res = std::max(maxArea(heights, m + 1, right), res);

      // Calculate max area crossing bar heights[m] and heights[m+1]
      int y = min(heights[m], heights[m + 1]);
      int l = m, r = m + 1, width = 0;
      while (l >= left || r <= right) {
         while (r <= right && heights[r] >= y) {
            ++width;
            ++r;
         }
         while (l >= left && heights[l] >= y) {
            ++width;
            --l;
         }
         res = std::max(res, y * width);

         if (r <= right && l >= left) {
            y = std::max(heights[r], heights[l]);
         }
         else if (r <= right) {
            y = heights[r];
         }
         // Don't use "else" since it's possible both @l and @r reach end
         else if (l >= left) {
            y = heights[l];
         }
      }

      return res;
   }
};

int main()
{
   vector<int> heights = { 2,1,5,6,2,3 };
   Solution so;
   cout << so.largestRectangleArea(heights) << endl;
   getchar();
   return 0;
}