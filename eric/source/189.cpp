/**********************************************************************************
 * https://leetcode.com/problems/squares-of-a-sorted-array/
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
    int square(int input) {
        return input * input;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> left;
        vector<int> right;
        vector<int> sorted;
        int i = 0;
        for (i = 0; (i < nums.size()) && (nums[i] <= 0); ++i) {
            left.push(square(nums[i]));
        }

        while (i < nums.size()) {
            right.push_back(square(nums[i++]));
        }

        // Merge two partially sorted list
        i = 0;
        while (!left.empty() && (i < right.size())) {
            int leftTop = left.top();
            if (leftTop <= right[i]) {
                sorted.push_back(leftTop);
                left.pop();
            }
            else {
                sorted.push_back(right[i++]);
            }
        }

        while(!left.empty()) {
            sorted.push_back(left.top());
            left.pop();
        }

        while (i < right.size()) {
            sorted.push_back(right[i++]);
        }

        return sorted;
    }
};
