/**********************************************************************************
 * https://leetcode.com/problems/pacific-atlantic-water-flow
 *
 * Auther: Eric Z
 *
 * Tip:
 * There is no need to use m_visited array, since it's already covered by m_access.
 * If propagating back to the same node, it'll find this same change should have already
 * be handled and thus won't reenter the same node.
 *
 * Time: O(n*m)
 * Space: O(n*m)
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        vector<pair<int, int>> res;
        if (matrix.empty()) {
            return res;
        }

        m_row = matrix.size();
        m_col = matrix[0].size();
        m_matrix = matrix;
        m_access.resize(m_row, vector<tAccess>(m_col, kNone));

        // Trigger top/bottom changes
        for (size_t j = 0; j < m_col; ++j) {
            propogateChange(0, j, kPacific);
            propogateChange(m_row - 1, j, kAtlantic);
        }

        // Trigger left/right changes
        for (size_t i = 0; i < m_row; ++i) {
            propogateChange(i, 0, kPacific);
            propogateChange(i, m_col - 1, kAtlantic);
        }

        // Find all cells that can flow to both oceans.
        for (size_t i = 0; i < m_row; ++i) {
            for (size_t j = 0; j < m_col; ++j) {
                if (m_access[i][j] == kBoth) {
                    res.push_back(make_pair(i, j));
                }
            }
        }

        return res;
    }

private:
    using tAccess = enum {
                             kNone,
                             kPacific,
                             kAtlantic,
                             kBoth
                         };

    size_t m_row;
    size_t m_col;
    vector<vector<int>> m_matrix;
    vector<vector<tAccess>> m_access;

    inline bool inRange(int i, int j)
    {
        return ((i >= 0) && (i < m_row) && (j >= 0) && (j < m_col));
    }

    inline bool canFlow(int i1, int j1, int i2, int j2)
    {
        return inRange(i1, j1) &&
               inRange(i2, j2) &&
               (m_matrix[i1][j1] >= m_matrix[i2][j2]);
    }

    void propogateChange(int i, int j, tAccess change)
    {
        tAccess &access = m_access[i][j];

        // If this is a visited node, or this is not a new change,
        // do nothing.
        if ((access == change) || (access == kBoth)) {
            return;
        }

        if (access != kNone) {
            access = kBoth;
        }
        else {
            access = change;
        }

        // Propogate through the revserse direction of sea flow
        int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        for (size_t d = 0; d < 4; ++d) {
            if (canFlow(i + dir[d][0], j + dir[d][1], i, j)) {
                propogateChange(i + dir[d][0], j + dir[d][1], change);
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = { {1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4} };
    Solution so;
    auto res = so.pacificAtlantic(matrix);
    for (auto p : res) {
        cout << "(" << p.first << ", " << p.second << ")" << "  ";
    }
    cout << endl;

    return 0;
}

