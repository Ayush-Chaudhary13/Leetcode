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
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            while(sz>0) {
                TreeNode* f = q.front(); 
                q.pop();
                temp.push_back(f->val);
               if(f->left)  q.push(f->left);
               if(f->right) q.push(f->right);
                sz--;    
            }
            ans.push_back(temp);
        } 
        return ans;   
    }
};