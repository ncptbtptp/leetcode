/**********************************************************************************
 * https://leetcode.com/problems/beautiful-arrangement/
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


class Solution {
public:  
    int countArrangement(int n) {
        int count(0);
        vector<int> ans(n+1, 0);  // one-based, initialized w/ zeros
        int step(1);
        // it's an art of picking data structure for the choice array
        // (1) need to be in increasing order (or any determined order across advance/backtracks)
        // (2) O(1) to check if any other number are used by other steps
        // which lead to a plain vector of bools..
        vector<bool> choices(n+1, false);   // one-based
        
        while (step >= 1) {
            int num(ans[step] + 1);
            // find next "beautiful" number that is not used
            while(num <= n && ((num % step != 0) && (step % num != 0) || choices[num]))
                ++num;
            
            // don't forget this for "an answer" and "partial answer" case!!
            choices[ans[step]] = false;
            
            // backtrack
            if (num > n) {
                ans[step] = 0;
                --step;
                continue;
            }
                       
            ans[step] = num;
            choices[num] = true;
            
            // an answer
            if (step == n) {
                ++count;
            }
            // partial answer
            else {
                ++step;
            }  
        }
        return count;
    }
};

// recursive
/*
class Solution {
public:  
    int countArrangement(int n) {
        int count(0);
        vector<int> ans;  // one-based, initialized w/ zeros
        for (int i = 0; i <= n; ++i) ans.push_back(i);
        advance(ans, 1, n);
        return m_count;
    }
    
    void advance(vector<int>& ans, int index, int n) {
        if (index == n + 1) {
            ++ m_count;
            return;
        }
        
        // try ans[index, n]
        for (int i = index; i <= n; ++i) {
            std::swap(ans[index], ans[i]);
            // beautiful number of ans[i]
            if (ans[index] % index == 0 || index % ans[index] == 0) {
                advance(ans, index + 1, n);                
            }
            std::swap(ans[index], ans[i]);
        }
    }

private:
   int m_count = 0;   
};
*/

