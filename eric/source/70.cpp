/**********************************************************************************
 * https://leetcode.com/problems/climbing-stairs/
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


class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        vector<int> memo(n+1);
        memo[1] = 1;
        memo[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            memo[i] = memo[i-1] + memo[i-2];
        }
        
        return memo[n];        
    }
};

