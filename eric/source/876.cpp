/**********************************************************************************
 * https://leetcode.com/problems/middle-of-the-linked-list/
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


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode sentinel(0, head);

        ListNode* slow(&sentinel), *fast(&sentinel);
        while (fast) {
            fast = fast->next;
            if (fast) fast = fast->next;

            slow = slow->next;
        }

        return slow;
    }
};

