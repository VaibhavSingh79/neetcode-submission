/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root==p || root == q){
            return root;
        }
        TreeNode* invLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* invRight = lowestCommonAncestor(root->right, p, q);

        if(invLeft!=NULL && invRight != NULL){
            return root;
        }

        if(invLeft != NULL) return invLeft;

        return invRight;
    }
};
