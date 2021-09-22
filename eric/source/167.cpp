/**********************************************************************************
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 2) {
            return {1, 2};
        }

        int i = 0, j = numbers.size() - 1;
        while (i != j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return { i + 1, j + 1 };
            else if (sum < target)
                ++i;
            else
                --j;
        }
        // Impossible
        return {0, 0};
    }
};

