/**********************************************************************************
 * https://leetcode.com/problems/split-array-largest-sum
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time: O(n*log(max-min))
 * Space: O(1)
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        if (nums.empty()) {
            return -1;
        }

        // The answer must be inside [low, high]
        long low = 0, high = 0;
        for (auto i : nums) {
            high += i;
            low = max(low, long(i));
        }
        return binary(nums, m, low, high);
    }

    int binary(vector<int>& nums, int m, long low, long high)
    {
        long mid = 0;
        while (low < high) {
            mid = (low + high) / 2;
            // We can assign "m" groups with "mid" as max sum
            if (valid(nums, m, mid)) {
                // Can't "mid-1" as "mid" can be our final answer.
                // And non-trivial partition!
                high = mid;
            }
            else {
                // non-trivial partition
                low = mid + 1;
            }
        }
        return high;
    }

    bool valid(vector<int>& nums, int m, long sum)
    {
        long cur = 0;
        for (auto i : nums) {
            // There is no way for i to be contained in any m groups
            if (i > sum) {
                return false;
            }
            cur += i;
            if (cur > sum) {
                --m;
                if (m == 0) {
                    return false;
                }
                else {
                    cur = i;
                }
            }
        }

        return true;
    }
};

//int main()
//{
//    vector<int> nums{1, 2147483647};
//    int m = 2;
//    Solution so;
//    cout << so.splitArray(nums, m) << endl;
//
//    return 0;
//}
