class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool isEnd = false;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode* root = new TrieNode();
        // Insert folders into Trie
        for (auto& path : folder) {
            TrieNode* node = root;
            stringstream ss(path);
            string part;
            getline(ss, part, '/'); // Skip leading empty part
            bool stop = false;
            while (getline(ss, part, '/')) {
                if (node->isEnd) { stop = true; break; }
                if (!node->children.count(part))
                    node->children[part] = new TrieNode();
                node = node->children[part];
            }
            if (!stop) node->isEnd = true;
        }
        vector<string> res;
        // DFS to collect results
        function<void(TrieNode*, string)> dfs = [&](TrieNode* node, string path) {
            if (node->isEnd) {
                res.push_back(path);
                return;
            }
            for (auto& [k, child] : node->children) {
                dfs(child, path + "/" + k);
            }
        };
        dfs(root, "");
        return res;
    }
};