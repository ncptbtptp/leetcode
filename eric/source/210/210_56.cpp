/**********************************************************************************
 * https://leetcode.com/problems/...
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time: O(?)
 * Space: O(?)
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>
//#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, const vector<pair<int, int>> &pre)
    {
        for (auto i : pre) {
            m_adjList[i.first].push_back(i.second);
        }
        m_colors.resize(numCourses, 0);

        vector<int> res;
        for (auto i : m_adjList) {
            if (m_colors[i.first] == 0) {
                if (!dfs(i.first, res)) {
                    return vector<int>();
                }
            }
        }
        return res;
    }
private:
    bool dfs(int node, vector<int> &res)
    {
        m_colors[node] = 1;
        for (auto i : m_adjList[node]) {
            if (m_colors[i] == 0) {
                if (!dfs(i, res)) {
                    return false;
                }
            }
            // Reach a back edge => cycle!
            else if (m_colors[i] == 1) {
                return false;
            }
            // If m_colors[i] == 2, it means we reach a finished node which is OK
        }
        res.push_back(node);
        m_colors[node] = 2;
        return true;
    }

    unordered_map<int, vector<int>> m_adjList;
    // 0: not visited
    // 1: visited, yet not finished (used to detect back edge)
    // 2: finished
    vector<int> m_colors;
};

//// Many thanks to C++11 uniform initialization form!!
//TEST(Normal, Single)
//{
//    auto res = Solution().findOrder(1, {});
//    int match[] = {1};
//    ASSERT_TRUE(std::equal(res.begin(), res.end(), match));
//}
//
//TEST(Normal, Y)
//{
//    auto res = Solution().findOrder(4, { {0, 1}, {2, 1}, {1, 3} });
//    int match1[] = {3, 1, 0, 2};
//    int match2[] = {3, 1, 2, 0};
//    ASSERT_TRUE(std::equal(res.begin(), res.end(), match1) ||
//                std::equal(res.begin(), res.end(), match2));
//}
//
//TEST(Normal, Diamond)
//{
//    auto res = Solution().findOrder(4, { {0, 1}, {0, 2}, {1, 3}, {2, 3} });
//    int match1[] = {3, 1, 2, 0};
//    int match2[] = {3, 2, 1, 0};
//    ASSERT_TRUE(std::equal(res.begin(), res.end(), match1) ||
//                std::equal(res.begin(), res.end(), match2));
//}
//
//TEST(Cycle, Self)
//{
//    auto res = Solution().findOrder(1, { {0, 0} });
//    ASSERT_TRUE(res.empty());
//}
//
//TEST(Cycle, TwoNodes)
//{
//    auto res = Solution().findOrder(2, { {0, 1}, {1, 0} });
//    ASSERT_TRUE(res.empty());
//}
//
//TEST(Cycle, MoreNodes)
//{
//    auto res = Solution().findOrder(4, { {0, 1}, {1, 2}, {2, 3}, {3, 0} });
//    ASSERT_TRUE(res.empty());
//}
//
//TEST(Forest, OneCycle)
//{
//    auto res = Solution().findOrder(4, { {0, 1}, {2, 3}, {3, 2} });
//    ASSERT_TRUE(res.empty());
//}
//
//TEST(Forest, AllGood)
//{
//    auto res = Solution().findOrder(4, { {0, 1}, {2, 3} });
//    int match1[] = {1, 0, 3, 2};
//    int match2[] = {3, 2, 1, 0};
//    ASSERT_TRUE(std::equal(res.begin(), res.end(), match1) ||
//                std::equal(res.begin(), res.end(), match2));
//}
//
//int main(int argc, char *argv[])
//{
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
