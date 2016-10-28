/**********************************************************************************
 * https://leetcode.com/problems/...
 *
 * Auther:
 *
 * Tip:
 *
 * Time: O(?)
 * Space: O(?)
 * Beat: ?%
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0 || ratings.size() == 1) {
            return ratings.size();
        }

        int total = 1, cur = 1;
        // start from 2nd child
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] == ratings[i - 1]) {
                total += cur;
            }
            else if (ratings[i] > ratings[i - 1]) {
                ++cur;
                total += cur;
            }
            else {
                // May need fix
                int dEnd = getDecreaseEnd(ratings, i - 1);
                // Adjust candies for child i-1
                total += max(cur, dEnd - i + 2) - cur;
                // Assign candies for children [i, dEnd]
                total += (dEnd - i + 2) * (dEnd - i + 1) / 2;
                cur = 1;
                i = dEnd;
            }
        }
        return total;
    }
private:
   // k is the root of a "subtree".
   // Return the end of continuous decreasing sequence on k's right.
   int getDecreaseEnd(vector<int>& ratings, int k)
   {
       while (k + 1 < ratings.size() && ratings[k + 1] < ratings[k]) {
           ++k;
       }
       return k;
   }
};



int main() {
    Solution so;
    vector<int> ratings = {0};
    cout << so.candy(ratings) << endl;

    return 0;
}

