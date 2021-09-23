/**********************************************************************************
 * https://leetcode.com/problems/reverse-string/
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
#include <queue>
#include <algorithm>
using namespace std; 

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() <= 1)
            return;
        
        for (int i = 0; i <= s.size()/2 - 1; ++i) {
            std::swap(s[i], s[s.size() - 1 - i]);
        }        
    }
};

