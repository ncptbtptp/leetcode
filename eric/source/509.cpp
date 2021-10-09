/**********************************************************************************
 * https://leetcode.com/problems/fibonacci-number/
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time:
 * Space:
 * Beat:
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> memo(n+2, 0);
        memo[0] = 0;
        memo[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            memo[i] = memo[i-1] + memo[i-2];
        }
        
        return memo[n];        
    }
};

