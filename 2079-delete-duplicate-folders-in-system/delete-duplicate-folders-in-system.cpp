#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} _fastio;

struct Node {
    string name;
    unordered_map<string,Node*> ch;
    bool del = false;
    explicit Node(const string& n = "") : name(n) {}
};

class Solution {
    unordered_map<string,Node*> seen;

    static void addPath(Node* cur, const vector<string>& path) {
        for (const string& dir : path) {
            auto& nxt = cur->ch[dir];
            if (!nxt) nxt = new Node(dir);
            cur = nxt;
        }
    }

    string dfs(Node* u) {
        vector<string> childSig;
        childSig.reserve(u->ch.size());
        for (auto& kv : u->ch) childSig.emplace_back(dfs(kv.second));
        sort(childSig.begin(), childSig.end());
        string sub;
        for (auto& s : childSig) sub += s;
        if (!sub.empty()) {
            auto it = seen.find(sub);
            if (it != seen.end()) {
                it->second->del = true;
                u->del = true;
            } else {
                seen[sub] = u;
            }
        }
        return '(' + u->name + sub + ')';
    }

    vector<vector<string>> out;
    vector<string> cur;

    void collect(Node* u) {
        if (u->del) return;
        cur.push_back(u->name);
        out.push_back(cur);
        vector<pair<string,Node*>> kids(u->ch.begin(), u->ch.end());
        sort(kids.begin(), kids.end(),
             [](const auto& a, const auto& b){ return a.first < b.first; });
        for (auto& kv : kids) collect(kv.second);
        cur.pop_back();
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node root;
        for (auto& p : paths) addPath(&root, p);
        seen.clear();
        dfs(&root);
        out.clear();
        cur.clear();
        vector<pair<string,Node*>> top(root.ch.begin(), root.ch.end());
        sort(top.begin(), top.end(),
             [](const auto& a, const auto& b){ return a.first < b.first; });
        for (auto& kv : top) collect(kv.second);
        return out;
    }
};
