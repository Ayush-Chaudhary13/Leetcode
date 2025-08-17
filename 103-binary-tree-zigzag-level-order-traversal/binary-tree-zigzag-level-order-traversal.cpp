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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;

            while(sz> 0) {
              TreeNode* n = q.front();
              q.pop();
              temp.push_back(n->val);

              if(n->left) q.push(n->left);
              if(n->right) q.push(n->right);
              sz--;
            }
            if(!flag) {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                flag = true;
            }
            else {
                ans.push_back(temp);
                flag = false;
            }
        }
        return ans;
    }
};