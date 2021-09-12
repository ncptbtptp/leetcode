/**********************************************************************************
 * https://leetcode.com/problems/partition-equal-subset-sum/
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time: O(n^2)
 * Space: O(n)
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>   // for std::accumulate
#include <bitset>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum & 0x1) {
            return false;
        }

        sum = sum >> 1;
        // For each number[0, 10000], can we reach it?
        bitset<10001> can{1};   // {1, 0, 0,, ..0}

        for (auto x : nums) {
            // Have to move backwards
            for (int i = sum; i >= x; --i) {
                can[i] = can[i] | can[i - x];
                if ((i == sum) && can[sum]) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
Another solution:
bool canPartition(vector<int>& nums) {
    bitset<5001> bits(1);
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);
    for (auto n: nums) {
        bits |= bits << n;
    }
    return !(sum & 1) && bits[sum >> 1];
}
*/

//int main()
//{
//    Solution so;
//    vector<int> nums{1, 2};
//    cout << so.canPartition(nums) << endl;
//
//    return 0;
//}
