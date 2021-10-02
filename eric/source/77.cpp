/**********************************************************************************
 * https://leetcode.com/problems/combinations
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time:
 * Space:
 * Beat:
  **********************************************************************************/
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;


// recursive
/*class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> s;
        for (int i = 1; i <= n; ++i) s.push_back(i);
        vector<int> ans;//(k, 0);
        combine(&s[0], &s[s.size()-1], k, ans);
        return m_ans;
    }
    
    // pick k numbers from [nums_begin, nums_end] and append to each combination in ans
    void combine(int* nums_begin, int* nums_end, int k, vector<int>& ans) {
        if (k == 0) {
            m_ans.push_back(ans);
            return;
        }
               
        for (int* p = nums_begin; p <= nums_end; ++p) {
            ans.push_back(*p);
            combine(p + 1, nums_end, k-1, ans);
            ans.pop_back();
        }
    }
    
private:
    vector<vector<int>> m_ans;
};
*/

// iterative
class Solution {
public:
vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};

