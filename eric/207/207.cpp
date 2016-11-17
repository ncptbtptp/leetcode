/**********************************************************************************
 * https://leetcode.com/problems/...
 *
 * Auther: Eric Z
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
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, const vector<pair<int, int>> &pre)
    {
        for (auto i : pre) {
            m_adjList[i.first].push_back(i.second);
        }
        m_colors.resize(numCourses, 0);

        for (auto i : m_adjList) {
            if (m_colors[i.first] == 0) {
                if (!dfs(i.first)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool dfs(int node)
    {
        m_colors[node] = 1;
        for (auto i : m_adjList[node]) {
            if (m_colors[i] == 0) {
                if (!dfs(i)) {
                    return false;
                }
            }
            // Reach a back edge => cycle!
            else if (m_colors[i] == 1) {
                return false;
            }
            // If m_colors[i] == 2, it means we reach a finished node which is OK
        }
        m_colors[node] = 2;
        return true;
    }

    unordered_map<int, vector<int>> m_adjList;
    // 0: not visited
    // 1: visited, yet not finished (used to detect back edge)
    // 2: finished
    vector<int> m_colors;
};

// Many thanks to C++11 uniform initialization form!!
TEST(Normal, Single)
{
    Solution so;
    ASSERT_TRUE(so.canFinish(1, {}));
}

TEST(Normal, Y)
{
    Solution so;
    ASSERT_TRUE(so.canFinish(4, { {0, 1}, {2, 1}, {1, 3} }));
}

TEST(Normal, OneToTwo)
{
    Solution so;
    ASSERT_TRUE(so.canFinish(3, { {0, 2}, {1, 2} }));
}

TEST(Normal, Diamond)
{
    Solution so;
    ASSERT_TRUE(so.canFinish(4, { {0, 1}, {0, 2}, {1, 3}, {2, 3} }));
}

TEST(Cycle, Self)
{
    Solution so;
    ASSERT_FALSE(so.canFinish(1, { {0, 0} }));
}

TEST(Cycle, TwoNodes)
{
    Solution so;
    ASSERT_FALSE(so.canFinish(2, { {0, 1}, {1, 0} }));
}

TEST(Cycle, MoreNodes)
{
    Solution so;
    ASSERT_FALSE(so.canFinish(4, { {0, 1}, {1, 2}, {2, 3}, {3, 0} }));
}

TEST(Forest, OneCycle)
{
    Solution so;
    ASSERT_FALSE(so.canFinish(4, { {0, 1}, {2, 3}, {3, 2} }));
}

TEST(Forest, AllGood)
{
    Solution so;
    ASSERT_TRUE(so.canFinish(4, { {0, 1}, {2, 3} }));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
