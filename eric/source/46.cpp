/**********************************************************************************
 * https://leetcode.com/problems/permutations/
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ansList;
        vector<int> ans(nums.size(), -1);    // store index of the nums since values can be non-contiguous
        unordered_set<int> used;             // indices used so far, to avoid duplicates
        int step = 0, length = nums.size();
        
        while(step >= 0) {
            int idx = ans[step];            // copy ans[step] to remove from "used" when backtrack
            do {
                ++idx;
            }while (idx < length && used.find(idx) != used.end());
            
            used.erase(ans[step]);          // need to remove first, before following add

            if (idx == length) {             // no partial answer possible, backtrack
                ans[step] = -1;
                --step;
            }
            else if (step == length - 1) {  // an answer
                used.insert(idx);
                ans[step] = idx;
                vector<int> ansOfNums;
                // transform index to the according distinct number
                std::transform(ans.begin(), ans.end(), std::back_inserter(ansOfNums), [nums](int i) { return nums[i]; });
                ansList.push_back(ansOfNums);
            }
            else {                          // partial answer, advance
                used.insert(idx);
                ans[step] = idx;
                ++step;
            }
        }
        return ansList;
    }
};

