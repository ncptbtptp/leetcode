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
 **********************************************************************************/

#include <iostream>
#include <vector>
//#include <cassert>
using namespace std;

/*
* bottom-up DP. Time: O(n^2), Space: O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return 1;
        
        // INT_MAX: cannot reach the last index; 0: last index; otherwise: steps to reach the last index
        vector<int> jumps(nums.size(), INT_MAX);
        jumps.back() = 0;
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            int min_jump = INT_MAX;
            for (int j = 1; j <= nums[i] && (i + j < nums.size()); ++j) {
                // check if nums[i+j] can reach the last index and if yes, how many jumps it needs
                min_jump = std::min(min_jump, jumps[i + j]);
            }
            jumps[i] = (min_jump == INT_MAX) ? INT_MAX : min_jump + 1;
        }
        
        return jumps[0];
    }
};
*/

/* one-loop greedy, still O(n), thus simpler but harder to understand */
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentJumpEnd = 0, farthest = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == currentJumpEnd) {
                ++jumps;
                currentJumpEnd = farthest;
            }
        }
        return jumps;
    }
};
*/

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

