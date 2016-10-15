/**********************************************************************************
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
 *
 * Tip: DON'T define a global variable. It may fail because a global variable
 * may carry states through different test cases on leetcode!
 * And it's often a bad design in practice.
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) {
            return 0;
        }

        if (k == 1) {
            return s.length();
        }

        size_t maxLen = 0;
        size_t n = s.length();

        for (size_t i = 0; i < n; ++i) {
            // Last element is a counter
            int arr[27]{};

            for (size_t j = i; j < n; ++j) {
                size_t curMaxLen = n - i;
                if (curMaxLen < k) {
                    goto DONE;
                }

                size_t cnt = ++arr[s[j] - 'a'];

                // A new char that fails to meet the "K" requirement
                if (cnt == 1) {
                    ++arr[26];
                }
                // A char that meets the requirement
                else if (cnt >= k) {
                    if (cnt == k) {
                        --arr[26];
                    }

                    // All chars in s[i, j] meets the requirement
                    if (arr[26] == 0) {
                        maxLen = max(maxLen, j - i + 1);
                        if (maxLen > n - i - 1) {
                            goto DONE;
                        }
                    }
                }
            }//for
        }//for

DONE:
        // If no substring meets the requirement, 0 is returned.
        return maxLen;
    }
};

int main()
{
    Solution so;
    string str{"ababbc"};
    int k = 2;
    cout << so.longestSubstring(str, k) << endl;

    return 0;
}

