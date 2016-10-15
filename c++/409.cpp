/**********************************************************************************
 * https://leetcode.com/problems/longest-palindrome/
 *
 * Auther: Eric Z
 *
 * Tip: 
 * 1. space: In ASCII code, capital letter(A~Z) + 6 letters in the middle + letters(a~z) < 64,
 *           formats a bitmap, which can fit in a u64
 * 2. time: on-the-fly counting, instead of a separate scan of table after filling.
 *
 * Time: O(n) 
 * Space: O(1)
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
#include <cstdint>      // uint64_t
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        uint64_t bitMap = 0;
        int maxLen = 0;

        for (size_t i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (getBit(bitMap, ch)) {
                clearBit(bitMap, ch);
                maxLen += 2;
            }
            else {
                setBit(bitMap, ch);
            }
        }

        return bitMap ? maxLen + 1 : maxLen;
    }

    inline bool getBit(uint64_t bits, char ch) {
        return bits & ((uint64_t)0x1 << (ch - 'A'));
    }

    inline void setBit(uint64_t &bits, char ch) {
        bits |= ((uint64_t)0x1 << (ch - 'A'));
    }

    inline void clearBit(uint64_t &bits, char ch) {
        bits &= ~((uint64_t)0x1 << (ch - 'A'));
    }
};

int main()
{
    Solution so;
    string s{"aabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabcabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddcccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddabccccddbccccdd"};
    cout << so.longestPalindrome(s) << endl;
    return 0;
}



