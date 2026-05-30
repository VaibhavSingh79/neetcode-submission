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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push(root);
        if(root == NULL) return ans;
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i=0; i < n; i++){
                TreeNode* current = q.front();
                temp.push_back(current->val);
                q.pop();

                if(current -> left != NULL){
                    q.push(current -> left);
                }

                if(current->right != NULL){
                    q.push(current -> right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
