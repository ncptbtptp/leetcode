/**********************************************************************************
 * https://leetcode.com/problems/jump-game-ii
 *
 * Auther: ncptbtptp
 *
 * Tip:
 * By always jump the next stone which can jump "furtherest", you're guaranteed
 * to have a move, unless all reachable stones are zero, which is a dead end.
 *
 * Time: O(n)
 * Space: O(1)
 * Beat: 57.62%
 **********************************************************************************/

#include <iostream>
#include <vector>
//#include <cassert>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int jumps = 0;
        // yet-to-be-defined for empty case, but it's trivial.
        if (nums.size() < 2) {
            return 0;
        }

        int cur = 0;
        while (true) {
           int max_step = nums[cur];

           // can't be dead end
           // assert (max_step > 0);

           if (cur + max_step >= nums.size() - 1) {
               return jumps + 1;
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
           ++jumps;
        }
    }
};

//int main()
//{
//    Solution so;
//    vector<int> v{2, 3, 1, 1, 4};
//    cout << so.jump(v) << endl;
//
//    return 0;
//}
