/**********************************************************************************
 * https://leetcode.com/problems/jump-game
 *
 * Auther: ncptbtptp
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

/*
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
*/

// recursive
/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        m_memo.resize(nums.size(), -1);
        return canJump(nums, 0);
    }
    
    bool canJump(vector<int>& nums, int index) {
        if (index >= nums.size()) return false;
        if (index == nums.size() - 1) return true;
        if (m_memo[index] != -1) return m_memo[index];
        
        bool jump(false);
        if (index + nums[index] >= nums.size() - 1)
            jump = true;
        
        for (int i = 1; !jump && i <= nums[index]; ++i) {
            jump = canJump(nums, index + i);
        }
        
        m_memo[index] = jump;
        return jump;
    }
    
private:
    // -1: not set; 0: impossible; 1: possible
    vector<int> m_memo;    
};
*/

// iterative, O(n) space, O(n^2) time
/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        if (nums[0] >= nums.size() - 1) return true;
        
        // -1: not set; 0: impossible; 1: possible
        vector<int> memo(nums.size(), -1);
        memo[nums.size() - 1] = 1;

        for (int i = nums.size() - 2; i >= 0; --i) {            

            int steps = nums[i];
            if (i + steps >= nums.size() - 1) {
                memo[i] = 1;
            }
            else {
                int j = 1;
                while (j <= steps && memo[i + j] == 0) ++j;
                memo[i] = (j <= steps) ? 1 : 0;                   
            }
        }
        
        return (memo[0] == 1);
    } 
};
*/

// iterative, O(1) space, O(1) time
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // next index that can jump to the last index somehow
        int nextIndex(nums.size() - 1);
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= nextIndex) nextIndex = i;
        }
        
        return (nextIndex == 0);
    }
};