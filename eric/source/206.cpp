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


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// iterative
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // loop invariant:
        // old: head of the unprocessed/original list
        // head: head of the processed/reverted list
        ListNode *old(head);
        head = nullptr;
        
        while (old) {
            ListNode *tmp(old);
            old = old->next;
            tmp->next = head;
            head = tmp;
        }
        
        return head;        
    }
};
*/

// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {      
        return reverse(nullptr, head);
    }
    
    ListNode* reverse(ListNode* first, ListNode* second) {
        if (!second) return first;
        
        ListNode* tmp(second);
        second = second->next;
        tmp->next = first;
        first = tmp;
        
        return reverse(first, second);
    }
};


