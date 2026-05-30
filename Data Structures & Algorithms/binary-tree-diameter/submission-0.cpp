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
    int diameterOfBinaryTree(TreeNode* root) {
        calci(root);
        return diam;

    }
    int diam = 0;
    int calci(TreeNode* root){
        if(root == NULL) return 0;
        int invRight = calci(root -> right);
        int invLeft = calci(root -> left);

        diam = max(diam, invRight+invLeft);

        return 1 + max(invRight, invLeft);
    }

};
