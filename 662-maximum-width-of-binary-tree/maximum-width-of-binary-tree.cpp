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
    int widthOfBinaryTree(TreeNode* root) {

        long long  ans =0;
        if(!root) return ans;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        while(!q.empty()) {
            long long cnt = q.size();

            long long start = q.front().second;
            long long end = q.back().second;

            ans = max(ans,(end-start+1));

            for(int i =0; i<cnt; i++) {
                auto [node,pos] = q.front();
                long long idx = pos-start;
                q.pop();

                if(node->left) {
                    q.push({node->left, 2*idx+1});
                }

                if(node->right) {
                    q.push({node->right, 2*idx+2});
                }
            }
        }
        return ans;
        
    }
};