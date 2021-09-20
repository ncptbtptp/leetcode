/**********************************************************************************
 * https://leetcode.com/problems/binary-search/
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
using namespace std; 

// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        return findInRange(1, n);
    }

    int findInRange(int l, int r)
    {
        if (l > r)
            return -1;

        if (l == r)
            return isBadVersion(l) ? l : -1;

        int k = (l + r) / 2;
        if (!isBadVersion(k))
            return findInRange(k+1, r);

        int res = findInRange(l, k-1);
        if (res == -1)
            return k;
        else
            return res;
    }
};

