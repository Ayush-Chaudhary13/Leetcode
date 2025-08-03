/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* clone, TreeNode* orig, TreeNode* target) {
        if(!orig) return nullptr;
        if(orig == target) return clone;

        TreeNode* left = dfs(clone->left, orig->left, target);
        if(left) return left;
        
        TreeNode* right = dfs(clone->right, orig->right, target);
        return right;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, original, target);
    }
};