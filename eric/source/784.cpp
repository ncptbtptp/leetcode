/**********************************************************************************
 * https://leetcode.com/problems/letter-case-permutation/
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
    vector<string> letterCasePermutation(string s) {
        vector<string> ansList;
        string ans(s.length(), '#');
        // Fixed and limited state transition so no need for an choices array
        // For letters: # -> lower case -> upper case
        // For digits: # -> digit
        int step = 0;
        while (step >= 0) {
            // no more choice for this step -- backtrack
            if (isdigit(ans[step]) || isupper(ans[step])) {
                ans[step] = '#';
                --step;
                continue;
            }
            
            // take next choice
            if (ans[step] == '#') {
                if (isdigit(s[step])) ans[step] = s[step];
                else ans[step] = tolower(s[step]);
            }
            else  {  // lower case
                ans[step] = toupper(ans[step]);
            }
            
            // one answer
            if (step == s.length() - 1) {
                ansList.push_back(ans);
            }
            // partial answer
            else {
                ++step;
            }
        }
        
        return ansList;
    }
};

