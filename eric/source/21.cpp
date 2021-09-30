/**********************************************************************************
 * https://leetcode.com/problems/merge-two-sorted-lists/
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
#include <queue>
#include <unordered_set>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode sentinel(0, nullptr), *p = &sentinel;
        
        // loop invariant:
        // p - tail of the merged sorted list
        // l1 - unprocessed head of list 1
        // l2 - unprocessed head of list 2
        while (l1 && l2) {
            if (l1->val <= l2->val) { p->next = l1; l1 = l1->next; }
            else { p->next = l2; l2 = l2->next; }
            p = p->next;
        }
        
        // both-null case also fits here
        if (l1) p->next = l1;
        else p->next = l2;
        
        return sentinel.next;
    }
};

