/**********************************************************************************
 * https://leetcode.com/problems/house-robber/
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
#include <set>
#include <map>
#include <cmath>
using namespace std;


// TODO: well, one end varying problem space please..
// this is way too expensive in both time & space...
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            memo[i][i] = nums[i];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                // calculate memo[i][j], i.e., houses[i, j]
                // for optimal value for houses[i, j], select house k,
                // and solve [i, k-2] and [k+2, j] optimally
                
                for (int k = i; k <= j; ++k) {
                    int val(memo[k][k]);
                    if (k-2 >= i) val += memo[i][k-2];
                    if (k+2 <= j) val += memo[k+2][j];
                    
                    if (val > memo[i][j]) {
                        memo[i][j] = val;
                    }                    
                }
            }
        }
        
        return memo[0][n-1];        
    }
};

