/**********************************************************************************
 * https://leetcode.com/problems/add-strings
 *
 * Auther: Eric Z
 *
 * Tip:
 *
 * Time: O(max(n, m))
 * Space: O(max(n, m))
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
using namespace std;

inline int to_int(char ch)
{
    return ch - '0';
}

inline char to_char(int i)
{
    return '0' + i;
}

string operator+ (const string &lhs, const string &rhs)
{
    size_t llen = lhs.length(), rlen = rhs.length();
    string sum(max(llen, rlen) + 1, 0);

    int carry = 0;
    int k = sum.length() - 1;
    auto i = lhs.rbegin(), j = rhs.rbegin();

    while (i != lhs.rend() && j != rhs.rend()) {
        int cur = to_int(*i) + to_int(*j) + carry;
        sum[k] = to_char(cur % 10);
        carry = cur / 10;
        ++i;
        ++j;
        --k;
    }

    while (i != lhs.rend()) {
        int cur = to_int(*i) + carry;
        sum[k] = to_char(cur % 10);
        carry = cur / 10;
        ++i;
        --k;
    }

    while (j != rhs.rend()) {
        int cur = to_int(*j) + carry;
        sum[k] = to_char(cur % 10);
        carry = cur / 10;
        ++j;
        --k;
    }

    if (carry) {
        sum[0] = to_char(carry);
        return sum;
    }
    else {
        return sum.substr(1);
    }
}

class Solution {
public:
    string addStrings(string num1, string num2) {
        return num1 + num2;
    }
};

int main()
{
    Solution so;
    string num1{"123"}, num2{"0"};
    cout << so.addStrings(num1, num2) << endl;

    return 0;
}
