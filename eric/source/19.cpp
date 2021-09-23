/**********************************************************************************
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;

        // Right shall be (n+1) steps ahead of left. Already one step forward now
        ListNode *left(nullptr), *right(head);

        // Let's walk n steps forward for the right
        while (right && (n > 0)) {
            right = right->next;
            --n;
        }

        // If the end is reached, remove the first node
        if (!right) {
            ListNode* tmp(head);
            head = head->next;
            delete tmp;
        }
        // Remove somewhere in the middle/tail
        else {
            while (right) {
                right = right->next;
                if (!left) left = head;
                else left = left->next;
            }

            // Now right --> list end
            // left --> parent of to-delete

            // Two cases included, to-delete is:
            // - "internal" nodes
            // - "tail" node
            ListNode* tmp(left->next);
            left->next = tmp->next;
            delete tmp;
        }

        return head;
    }
};
