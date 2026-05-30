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
    TreeNode* invertTree(TreeNode* root) {
        //create two call invert them return root???

        if(root == NULL) return 0;
        TreeNode* invLeft = invertTree(root -> left);
        TreeNode* invRight = invertTree(root -> right);

        root -> right = invLeft;
        root -> left = invRight;

        return root;
    }
};
