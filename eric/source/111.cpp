/**********************************************************************************
 * https://leetcode.com/problems/minimum-depth-of-binary-tree
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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            ++level;
            int nodesOfLevel = q.size();
            for(int i = 0; i < nodesOfLevel; ++i) {
                TreeNode* r = q.front();
                q.pop();
                
                // Find a leaf
                if (!r->left && !r->right)
                    return level;
                
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }            
        }
        
        return level;
    }
};

