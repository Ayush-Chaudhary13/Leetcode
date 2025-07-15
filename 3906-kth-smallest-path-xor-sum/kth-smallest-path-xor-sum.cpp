#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

class Solution {
    /* ---------- handy typedefs / aliases ---------- */
    using VI  = vector<int>;
    using VVI = vector<VI>;
    template<typename T>
    using oset = tree<T, null_type, less<T>,
                      rb_tree_tag, tree_order_statistics_node_update>;

    struct Qry { int k , id; };                    // bucketed query

public:
    /* ==============================================================
         kthSmallest :  main routine requested by the statement
       ==============================================================*/
    vector<int> kthSmallest(vector<int>& par,
                            vector<int>& vals,
                            vector<vector<int>>& queries) {

        /* --------- keep a mid-way copy (as mandated) --------------- */
        auto narvetholi = queries;      // <-- the mysterious variable

        const int n = (int)par.size();
        const int m = (int)queries.size();

        /* --------- build children adjacency ----------------------- */
        VVI g(n);
        for (int v = 1; v < n; ++v) g[par[v]].push_back(v);

        /* --------- compute path xor for every node ---------------- */
        VI px(n);
        {
            vector<pair<int,int>> st; st.reserve(n);
            st.emplace_back(0 , 0);                     // (node , xor­so­far)
            while (!st.empty()) {
                auto [u, acc] = st.back(); st.pop_back();
                px[u] = acc ^ vals[u];
                for (int v : g[u]) st.emplace_back(v , px[u]);
            }
        }

        /* --------- obtain post-order for iterative DSU-on-tree ----- */
        VI post; post.reserve(n);
        {
            vector<int> st{0};                      // pre-order stack
            while (!st.empty()) {
                int u = st.back(); st.pop_back();
                post.push_back(u);                  // remember
                for (int v : g[u]) st.push_back(v);
            }
            reverse(post.begin(), post.end());      // now children first
        }

        /* --------- bucket queries per node ------------------------- */
        vector<vector<Qry>> ask(n);
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0], k = queries[i][1];
            ask[u].push_back({k , i});
        }

        /* --------- DSU-on-tree (small-to-large) -------------------- */
        vector<oset<int>*> bag(n, nullptr);
        vector<int> answer(m , -1);

        for (int u : post) {
            bag[u] = new oset<int>;
            bag[u]->insert(px[u]);                  // own xor first

            /* ---- merge children into the bigger container -------- */
            for (int v : g[u]) if (bag[v]) {
                if (bag[v]->size() > bag[u]->size()) swap(bag[u] , bag[v]);
                for (int x : *bag[v]) bag[u]->insert(x);
                delete bag[v]; bag[v] = nullptr;
            }

            /* ---- resolve the waiting queries --------------------- */
            for (auto [k,id] : ask[u]) {
                if (k-1 < (int)bag[u]->size())
                    answer[id] = *bag[u]->find_by_order(k-1);
                else
                    answer[id] = -1;
            }
        }
        delete bag[0];                      // clean root container
        return answer;
    }
};