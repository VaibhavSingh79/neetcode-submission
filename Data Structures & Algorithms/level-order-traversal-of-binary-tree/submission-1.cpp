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
        vector<vector<int>> ans;
        //first I will need two variables to traverse right????
        //or maybe I can use up a queue bcz it work on O(1), plus FIFO

        queue<TreeNode*> q;
        //I'll push the root first because ????
        q.push(root);
        if(root == NULL) return ans;
        while(!q.empty()){
            vector<int> temp; //this is where I store values
            //inside loop because everytime I'll need a new array inside ans 
            int n = q.size(); //I am creating this outside for loop otherwise if I did inside for loop
            //the loop will tend to infinity
            for(int i=0; i < n; i++){
                TreeNode* current = q.front(); //right??? my current is what's sitting in front of me
                temp.push_back(current -> val);
                q.pop();

                if(current -> left != NULL){
                    q.push(current->left);
                }
                if(current -> right != NULL){
                    q.push(current->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;

    }
};
