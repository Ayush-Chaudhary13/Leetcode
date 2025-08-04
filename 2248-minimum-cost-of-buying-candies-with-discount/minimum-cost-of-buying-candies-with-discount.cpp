class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int amt = 0;
        sort(cost.begin(), cost.end());
        for (int i = cost.size() - 1; i >= 0; i -= 3) {
            amt += cost[i];
            if (i > 0)
                amt += cost[i - 1];
        }

        return amt;
    }
};