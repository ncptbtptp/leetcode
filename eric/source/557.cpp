/**********************************************************************************
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
using namespace std; 

class Solution {
public:
    void reverse(string &word, int begin, int end) {
        int size = end - begin + 1;
        for (int i = 0; i < size/2; ++i) {
            std::swap(word[begin + i], word[begin + size - 1 - i]);
        }
    }
    
    int nextWordStart(string &s, int wordStart){
        for (int i = wordStart + 1; i < s.size(); ++i) {
            if (s[i] == ' ')
                return (i + 1);
        }
        return -1;
    }
    
    string reverseWords(string s) {
        int wordStart = 0;
        int wordEnd = 0;
              
        while (wordEnd != s.size() - 1){
            int nextStart = nextWordStart(s, wordStart);
            wordEnd = (nextStart == -1) ? s.size() - 1 : nextStart - 2;
            reverse(s, wordStart, wordEnd);
            wordStart = nextStart;
        }
        
        return s;
    }
};
