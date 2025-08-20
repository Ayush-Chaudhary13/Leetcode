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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        vector<int> ans;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int dist = 0;
        while(!q.empty()) {
            if(dist == k) {
                while(!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                return ans;
            }

            int size = q.size();
            for(int i =0; i<size; i++) {
                auto node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

               if(parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end()){
                   q.push(parent[node]);
                   visited.insert(parent[node]);
               }
                
            }
            dist++;

        }
        return ans;
    }
};