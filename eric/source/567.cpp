/**********************************************************************************
 * https://leetcode.com/problems/permutation-in-string/
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
    int indexOf(char ch) {
        return (ch - 'a');
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0), window(26, 0);

        for (auto ch : s1)
            ++count[indexOf(ch)];

        int left = 0, right = 0;
        while (right < s2.length()) {
            char ch = s2[right];

            if (count[indexOf(ch)] == 0) {
                left = right = right + 1;
                for_each(window.begin(), window.end(), [](int &c) { c = 0; });
            }
            else if (window[indexOf(ch)] == count[indexOf(ch)]) {
                --window[indexOf(s2[left])];
                ++left;
            }
            else {
                if (right - left + 1 == s1.length())
                    return true;

                ++window[indexOf(ch)];
                ++right;
            }
        }

        return false;
    }
};

