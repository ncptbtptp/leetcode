/**********************************************************************************
 * https://leetcode.com/problems/n-th-tribonacci-number/
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
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        
        vector<int> memo(n+1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        
        for (int i = 3; i <= n; ++i) {
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
        }
        
        return memo[n];        
    }
};
