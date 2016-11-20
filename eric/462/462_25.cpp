/**********************************************************************************
 * leetcode #462: Minimum Moves to Equal Array Element II
 *
 * Auther: Eric-Z
 *
 * Tip:
 *
 * Time: O(n)
 * Space: O(1)
 **********************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <stack>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        if (nums.size() < 2) {
            return 0;
        }

        // Partial sorting algorithm from std
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());

        int cnt = 0;
        for (auto i : nums) {
            cnt += std::abs(i - *(nums.begin() + nums.size()/2));
        }
        return cnt;
    }
};

TEST(ZeroMove, NoElement)
{
    Solution so;
    vector<int> nums{};
    ASSERT_EQ(Solution().minMoves2(nums), 0);
}

TEST(ZeroMove, SingleElement)
{
    Solution so;
    vector<int> nums{1};
    ASSERT_EQ(Solution().minMoves2(nums), 0);
}

TEST(OneMove, TwoElements)
{
    Solution so;
    vector<int> nums{1,2};
    ASSERT_EQ(Solution().minMoves2(nums), 1);
}

TEST(TwoMove, ThreeElements)
{
    Solution so;
    vector<int> nums{1,2,3};
    ASSERT_EQ(Solution().minMoves2(nums), 2);
}

TEST(FiveMove, SevenElements)
{
    Solution so;
    vector<int> nums{1,1,1,2,2,3,3};
    ASSERT_EQ(Solution().minMoves2(nums), 5);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
