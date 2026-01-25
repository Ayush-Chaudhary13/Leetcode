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
    void dfs(TreeNode* root, TreeNode* parent, TreeNode* grandparent, int& sum)
    {
        if(!root) return;
        if(grandparent && grandparent->val%2 ==0) sum += root->val;

        dfs(root->left, root, parent, sum);
        dfs(root->right, root, parent, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {

        int sum =0;
        dfs(root, NULL, NULL, sum);
        return sum;
        
    }
};