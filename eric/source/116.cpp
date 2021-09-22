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
#include <queue>
#include <algorithm>
using namespace std; 

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//Method 1: use queue
//class Solution {
//public:
//    Node* connect(Node* root) {
//        if (!root) return nullptr;
//        
//        queue<Node*> q;
//        q.push(root);
//        int index(-1);
//        int leftIdx(0), rightIdx(0);
//        Node* pre(nullptr);
//
//        while (!q.empty()) {
//            // Queue framework
//            Node* cur = q.front();
//            q.pop();
//            ++index;
//
//            // Visit logic
//            if (index > leftIdx && index <= rightIdx) {
//                // fixup/link
//                pre->next = cur;
//            }
//
//            // Prepare for the next step
//            if (index == rightIdx) {
//                // Will move on the next level
//                leftIdx = leftIdx * 2 + 1;
//                rightIdx = rightIdx * 2 + 2;
//                pre = nullptr;
//            }
//            else
//            {
//                // Will move on the same level
//                pre = cur;
//            }
//
//            // Queue framework
//            if (cur->left)
//                q.push(cur->left);
//
//            if (cur->right)
//                q.push(cur->right);
//        }
//
//        return root;
//    }
//};

// Method 2: O(1) time by using established links
class Solution {
public:
    bool IsLeaf(Node* level) {
        return (!level->left);
    }

    Node* connect(Node* root) {
        if (!root) return nullptr;

        // The lever ptr
        Node *level = root;

        // Traverse level by level
        while (!IsLeaf(level)) {
            // The advance ptr and its previous
            Node *adv = level;
            Node *pre = nullptr;

            // Link left to right
            while (adv) {
                // Link fixups
                if (pre)
                    pre->right->next = adv->left;
                adv->left->next = adv->right;

                // Move to next node on the same level
                pre = adv;
                adv = adv->next;
            }

            // Move to next level
            level = level->left;
        }

        return root;
    }
};

