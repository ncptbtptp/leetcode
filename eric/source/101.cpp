/**********************************************************************************
 * https://leetcode.com/problems/symmetric-tree/
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
#include <unordered_set>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);      
    }
    
    bool isMirror(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        return ((r1->val == r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left));
    }
};

//iterative
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        s1.push(root); s2.push(root);
        while (!s1.empty() && !s2.empty()) {
            TreeNode* r1 = s1.top(); s1.pop();
            TreeNode* r2 = s2.top(); s2.pop();
            if (!r1 && !r2) continue;
            if (!r1 || !r2) return false;
            if (r1->val != r2->val) return false;
            s1.push(r1->left); s1.push(r1->right);
            s2.push(r2->right); s2.push(r2->left);
        }
        
        return (s1.empty() && s2.empty());
    }
};
*/

