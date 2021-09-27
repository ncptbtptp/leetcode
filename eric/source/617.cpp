/**********************************************************************************
 * https://leetcode.com/problems/merge-two-binary-trees/
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
 
 // TODO: iterative dfs using an explicit stack
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
    
    TreeNode* merge(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return nullptr;
        if (!r1) return new TreeNode(r2->val, r2->left, r2->right);
        if (!r2) return new TreeNode(r1->val, r1->left, r1->right);
        
        TreeNode* l = merge(r1->left, r2->left);
        TreeNode* r = merge(r1->right, r2->right);
        
        return new TreeNode(r1->val + r2->val, l, r);        
    }
};


