#include "pch.h"
#include "Common.h"
#include "../source/310/310.h"

using namespace std;

TEST(P310, TC1)
{
    vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> result = findMinHeightTrees(6, edges);
    const vector<int> expected = {3, 4};

	EXPECT_TRUE(IsSameVector(result, expected, false));
}

TEST(P310, TC2)
{
    vector<vector<int>> edges = {};
    vector<int> result = findMinHeightTrees(1, edges);
    const vector<int> expected = {0};

	EXPECT_TRUE(IsSameVector(result, expected, false));
}

TEST(P310, TC3)
{
    vector<vector<int>> edges = {{0, 1}};
    vector<int> result = findMinHeightTrees(2, edges);
    const vector<int> expected = {0, 1};

	EXPECT_TRUE(IsSameVector(result, expected, false));
}

TEST(P310, TC4)
{
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> result = findMinHeightTrees(4, edges);
    const vector<int> expected = {1};

	EXPECT_TRUE(IsSameVector(result, expected, false));
}