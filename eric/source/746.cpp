/**********************************************************************************
 * https://leetcode.com/problems/min-cost-climbing-stairs/
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


// recursive
/*
class Solution {
public:
    // recursive
    int minCostClimbingStairs(vector<int>& cost) {
        m_memo.resize(cost.size(), -1);
        // starts from -1
        return std::min(getMinCost(cost, 0), getMinCost(cost, 1));
    }
    
    int getMinCost(vector<int>& cost, int start) {
        // base case
        if (start == cost.size()) return 0;
        if (start == cost.size() -1) return cost.back();
        
        
        if (m_memo[start] == -1) {
            m_memo[start] = cost[start] + std::min(getMinCost(cost, start + 1), getMinCost(cost, start+2));
        }

        return m_memo[start];
    }
private:
    vector<int> m_memo;    
};
*/

// iterative with memo of space O(n)
/*
class Solution {
public:
    // recursive
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        // starts from right end
        memo[memo.size()-1] = cost.back();
        memo[memo.size()-2] = cost[cost.size() - 2];
        
        for (int i = cost.size() - 3; i >= 0; --i) {
            memo[i] = cost[i] + std::min(memo[i + 1], memo[i + 2]);
        }
        
        return std::min(memo[0], memo[1]);
    }  
};
*/

// iterative with memo of space O(1)
class Solution {
public:
    // recursive
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1) {
            return cost[0];
        }
               
        // starts from right end
        int memo_next_next = cost.back();
        int memo_next = cost[cost.size() - 2];
        int memo(0);
        
        // cost size >= 3
        for (int i = cost.size() - 3; i >= 0; --i) {
            memo = cost[i] + std::min(memo_next, memo_next_next);           
            memo_next_next = memo_next;
            memo_next = memo;            
        }
        
        return std::min(memo_next, memo_next_next);
    }  
};

