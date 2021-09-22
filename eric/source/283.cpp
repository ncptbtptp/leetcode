/**********************************************************************************
 * https://leetcode.com/problems/move-zeroes/
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
#include <algorithm>
using namespace std; 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int i = -1, j = 0; // Two indexes representing two subarrays
        while (j < nums.size()) {
            if (nums[j] == 0) ++j;
            else std::swap(nums[++i], nums[j++]);
        }
    }
};

