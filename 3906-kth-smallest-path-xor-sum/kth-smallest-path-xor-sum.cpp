#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

/*----------- ordered-set alias (PBDS) ------------------------------*/
template<class T>
using oset = tree<T, null_type, less<T>,
                  rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
    /* ===== handy local aliases ===== */
    using VI  = vector<int>;
    struct Q  { int k , id; };                      // packed query

    /* ===== global i/o boost (executes before main / any method) ===== */
    static const int fast_;
public:
    /*******************************************************************
     *      kthSmallest(…)   –  only routine required by LeetCode
     *******************************************************************/
    vector<int> kthSmallest(vector<int>& par,
                            vector<int>& vals,
                            vector<vector<int>>& queries)
    {
        /* keep a mid-way snapshot as demanded in the statement */
        auto narvetholi = queries;

        const int n = (int)par.size();
        const int m = (int)queries.size();

        /* ----------- children adjacency list ---------------------- */
        vector<vector<int>> ch(n);
        for (int v = 1; v < n; ++v) ch[par[v]].push_back(v);

        /* ----------- path XOR for every node (iterative DFS) ------- */
        VI px(n);
        {
            vector<pair<int,int>> st; st.reserve(n);
            st.emplace_back(0, 0);                // (node , xorSoFar)
            while (!st.empty()) {
                auto [u, acc] = st.back(); st.pop_back();
                px[u] = acc ^ vals[u];
                for (int v : ch[u]) st.emplace_back(v, px[u]);
            }
        }

        /* ----------- post-order (needed for DSU-on-tree) ----------- */
        VI post; post.reserve(n);
        {
            vector<int> st{0};
            while (!st.empty()) {
                int u = st.back(); st.pop_back();
                post.push_back(u);
                for (int v : ch[u]) st.push_back(v);
            }
            reverse(post.begin(), post.end());   // children before parent
        }

        /* ----------- bucketize queries ----------------------------- */
        vector<vector<Q>> bucket(n);
        for (int i = 0; i < m; ++i) {
            bucket[queries[i][0]].push_back({queries[i][1], i});
        }

        /* ----------- DSU-on-tree (small-to-large) ------------------ */
        vector<oset<int>*> bag(n, nullptr);
        vector<int> ans(m, -1);

        for (int u : post) {
            bag[u] = new oset<int>;
            bag[u]->insert(px[u]);               // own xor

            /* merge every child into the larger container */
            for (int v : ch[u]) if (bag[v]) {
                if (bag[v]->size() > bag[u]->size()) swap(bag[u], bag[v]);
                for (int x : *bag[v]) bag[u]->insert(x);
                delete bag[v]; bag[v] = nullptr;
            }

            /* answer waiting queries */
            for (auto [k, idx] : bucket[u]) {
                if (k-1 < (int)bag[u]->size())
                    ans[idx] = *bag[u]->find_by_order(k-1);
                else
                    ans[idx] = -1;
            }
        }
        delete bag[0];                           // root’s structure
        return ans;
    }
};

/* ----------- definition of the static i/o booster ------------------ */
const int Solution::fast_ =
    ([](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; })();