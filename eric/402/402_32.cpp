/**********************************************************************************
 * https://leetcode.com/problems/remove-k-digits
 *
 * Auther: Eric-Z
 *
 * Tip:
 *
 * Time: O(n)
 * Space: O(n)
 **********************************************************************************/
//#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <stack>
using namespace std;

class Solution {
public:
    // Greedy + stack
    // Maintain a current non-decreasing sequence. If we find the decreasing number,
    // pop elements off stack until we find a non-decreasing sequence again.
    // Two details:
    // 1. What if string ends when k > 0 ?
    // 2. What if K is 0 when string doesn't end ?
    string removeKdigits(string num, int k)
    {
        if (num.length() == 0) {
            return num;
        }

        stack<char> s;
        s.push(num.front());

        auto it = num.begin() + 1;
        while (it != num.end() && (k > 0)) {
            while (!s.empty() && (*it < s.top()) && (k-- > 0)) {
                s.pop();
            }
            // Avoid pushing a leading zero
            if (!s.empty() || (*it != '0')) {
                s.push(*it);
            }
            ++it;
        }

        while (it != num.end()) {
            if (s.empty() && (*it == '0')) {
                ++it;
                continue;
            }
            s.push(*(it++));
        }

        // s can be empty. Consider str="10" and k=2
        while (!s.empty() && (k-- > 0)) {
            s.pop();
        }

        // Transfer stack<char> to string
        if (s.empty()) {
            return "0";
        }

        string res(s.size(), '0');
        auto rIt = res.rbegin();
        while (!s.empty()) {
            *(rIt++) = s.top();
            s.pop();
        }

        return res;
    }
};

//TEST(Normal, Increase)
//{
//    Solution so;
//    ASSERT_EQ(Solution().removeKdigits("1432219", 3), "1219");
//}
//
//TEST(Normal, LeadingZero)
//{
//    Solution so;
//    ASSERT_EQ(Solution().removeKdigits("10200", 1), "200");
//}
//
//TEST(Normal, RemoveAll)
//{
//    Solution so;
//    ASSERT_EQ(Solution().removeKdigits("10", 2), "0");
//}
//
//int main(int argc, char *argv[])
//{
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
