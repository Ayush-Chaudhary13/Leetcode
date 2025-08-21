/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parentmap;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode = NULL;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->val == start)
                startNode = node;
            if (node->left) {
                parentmap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentmap[node->right] = node;
                q.push(node->right);
            }
        }

        int time = 0;
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parentmap.find(node) != parentmap.end() &&
                    visited.find(parentmap[node]) == visited.end()) {
                    q.push(parentmap[node]);
                    visited.insert(parentmap[node]);
                }
            }
            time++;
        }
        return time - 1;
    }
};