/**********************************************************************************
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
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
#include <stack>
using namespace std; 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, i = -1;
        while (j < nums.size()) {
            while (j+1 < nums.size() && nums[j] == nums[j+1])
                ++j;

            if (i + 1 != j)
                nums[i + 1] = nums[j];

            ++i;
            ++j;
        }
        return i+1;        
    }
};

