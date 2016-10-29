/**********************************************************************************
 * https://leetcode.com/problems/wiggle-sort-ii
 *
 * Tip:
 * A cleaner solution (also O(N)) is to use 3-way partition ([ < ][ = ][ > ]). See:
 * https://discuss.leetcode.com/topic/32904/clean-average-o-n-time-in-c 
 *
 * Time: O(N), though std::nth_element() is not guaranteed to run in O(N) in worst case.
 * Space: O(N)
 **********************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        if (nums.size() <= 1) {
            return;
        }

        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int median = nums[n/2];

        int cnt1 = 0, cnt2 = 0;
        for (auto number : nums) {
            if (number < median) {
                ++cnt1;
            }
            else if (number > median) {
                ++cnt2;
            }
        }

        vector<int> temp(n);
        // # of items on bottom line
        int size1 = (n%2) ? (n/2 + 1) : (n/2);

        /* Fill bottom line */
        // Fill w/ median, if needed
        int j = 0;
        for (int i = 0; i < size1 - cnt1; ++i) {
            temp[j] = median;
            j += 2;
        }

        // Fill the rest of bottom line
        for (auto number : nums) {
            if (number < median) {
                temp[j] = number;
                j += 2;
            }
        }

        /* Fill top line */
        // Fill with big number
        j = 1;
        for (auto number : nums) {
            if (number > median) {
                temp[j] = number;
                j += 2;
            }
        }

        // Fill w/ median if needed
        for (int i = 0; i < n - size1 - cnt2; ++i) {
            temp[j] = median;
            j += 2;
        }

        nums = temp;
    }
};

int main()
{
    vector<int> nums = {4,5,5,6};
    Solution so;
    so.wiggleSort(nums);
    for_each(nums.begin(), nums.end(), [](int i){ cout << i << " "; } );
    cout << endl;

    return 0;
}
