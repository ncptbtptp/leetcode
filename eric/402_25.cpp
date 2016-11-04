/**********************************************************************************
 * https://leetcode.com/problems/remove-k-digits
 *
 * Auther: Eric-Z
 *
 * Tip:
 *
 * Time: O(?)
 * Space: O(?)
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();
        if (k == n) {
            return "0";
        }
        if (k == 0) {
            return num;
        }

        string res;
        int left = 0;
        int right = k;
        int count = n - k;
        bool leading = true;

        while ((count > 0) && (n - left > count)) {
           auto m = distance(&num[0], min_element(&num[0] + left, &num[0] + right + 1));

           if (!leading || num[m] != '0') { // don't output leading zero
               res += num[m];
               leading = false;
           }
           left = m + 1;
           ++right;
           --count;
        }

        while (count > 0) {
            res += num[left++];
            --count;
        }

        return res.empty() ? "0" : res;
    }
};

int main()
{
    Solution so;
    string num("10");
    int k = 2;
    cout << so.removeKdigits(num, k) << endl;

    return 0;
}
