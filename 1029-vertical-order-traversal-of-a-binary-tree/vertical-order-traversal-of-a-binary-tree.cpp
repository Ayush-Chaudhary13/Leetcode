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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,map<int, multiset<int>>> nodes;

        queue<tuple<TreeNode* , int , int>>q;
        q.push({root,0,0});

        while(!q.empty()) {
            auto [n, col, row] = q.front();
            q.pop();

            nodes[col][row].insert(n->val);

            if(n->left)q.push({n->left, col-1, row+1});
            if(n->right)q.push({n->right,col+1,row+1});
        }
        vector<vector<int>> ans;

        for(auto& [col,rowmap] : nodes) {
            vector<int> colvals;
            for(auto& [row,vals] : rowmap) {
                colvals.insert(colvals.end(), vals.begin(), vals.end());
            }
            ans.push_back(colvals);
        }

        return ans;
    }
};