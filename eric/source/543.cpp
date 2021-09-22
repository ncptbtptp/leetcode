/**********************************************************************************
 * https://leetcode.com/problems/diameter-of-binary-tree/
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
#include <stack>
#include <algorithm>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int longestPathThroRoot = 0;
        // In edges instead of nodes..
        return (diameter(root, longestPathThroRoot) - 1);
    }

     int diameter(TreeNode* root, int& longestPathThroRoot) {
        // Base case
        if (!root) {
            longestPathThroRoot = 0;
            return 0;
        }

        int leftPathMax = 0, rightPathMax = 0;
        int leftDiameter = 0, rightDiameter = 0;

        leftDiameter = diameter(root->left, leftPathMax);
        rightDiameter = diameter(root->right, rightPathMax);
        longestPathThroRoot = max(leftPathMax, rightPathMax) + 1;
        return max({leftDiameter, rightDiameter,  leftPathMax + rightPathMax + 1});
    }
};
