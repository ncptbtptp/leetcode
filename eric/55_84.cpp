/**********************************************************************************
 * https://leetcode.com/problems/jump-game
 *
 * Auther: Eric Z
 *
 * Tip:
 * By always jump the next stone which can jump "furtherest", you're guaranteed
 * to have a move, unless all reachable stones are zero, which is a dead end.
 *
 * Time: O(n)
 * Space: O(1)
 * Beat: 83.92%
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        // yet-to-be-defined for empty case, but it's trivial.
        if (nums.size() < 2) {
            return true;
        }

        int cur = 0;
        while (true) {
           int max_step = nums[cur];

           // dead end
           if (max_step == 0) {
               break;
           }

           if (cur + max_step >= nums.size() - 1) {
               return true;
           }

           int next = cur + 1;
           int next_max = next + nums[next];
           for (int i = cur + 2; i <= cur + max_step; ++i) {
               if (i + nums[i] >= next_max) {
                   next = i;
                   next_max = i + nums[i];
               }
           }

           // jump as further as possible
           cur = next;
        }
        return false;
    }
};

int main()
{
    Solution so;
    vector<int> v{3, 2, 1, 0, 4};
    cout << so.canJump(v) << endl;

    return 0;
}
