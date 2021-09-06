/**********************************************************************************
 * https://leetcode.com/problems/wiggle-sort-ii
 *
 * Tip:
 * Have to reverse copy, otherwise there can be overlap of the same number,e.g., {4, 5, 5, 6}
 *
 * Time: O(NlogN)
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

        std::sort(nums.begin(), nums.end());

        // 1st half(small nums) is equal to or one more than 2nd half in size:
        // if n is even, |1st| = |2nd| = n/2;
        // if n is odd,  |1st| = |2nd| + 1 = n/2 + 1.

        int n = nums.size();
        int size1 = (n % 2) ? (n / 2 + 1) : (n / 2);

        vector<int> temp(n);
        // Fill in even slots w/ 1st half in reverse order
        for (int i = size1 - 1; i >= 0; --i) {
            int ith = size1 - 1 - i;
            temp[2 * ith] = nums[i];

        }

        // Fill in odd slots w/ 2nd half in reverse order
        for (int i = n - 1; i >= size1; --i) {
            int ith = n - 1 - i;
            temp[2 * ith + 1] = nums[i];
        }

        std::swap(nums, temp);
    }
};

//int main()
//{
//    vector<int> nums = {4, 5, 5, 6};
//    Solution so;
//    so.wiggleSort(nums);
//    for_each(nums.begin(), nums.end(), [](int i){ cout << i << " "; } );
//    cout << endl;
//
//    return 0;
//}
