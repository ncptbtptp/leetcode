/**********************************************************************************
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
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
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();

        // Direct access table
        // "int chars[128] = {-1}" only initialize the array as {-1, 0, 0...0}
        vector<int> chars(128, -1);
        int maxLen = 0;

        // [left, right) is the current longest substring w/o duplicate starting from s[left]
        for (int left = 0, right = 0; right < s.length(); ++right) {
            char next = s[right];
            // There is a duplicate of s[right] in s[left, right)
            if (chars[next] >= left) {
                left = chars[next] + 1;
            }
            chars[next] = right;
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
