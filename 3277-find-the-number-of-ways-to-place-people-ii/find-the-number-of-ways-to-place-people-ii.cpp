class Solution {
public:
    static bool cmp(const vector<int> &p, const vector<int> &q) {
        return (p[0] == q[0]) ? p[1]<q[1] : p[0]>q[0];
    }
    int numberOfPairs(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), cmp);
        int n = p.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y = INT_MAX, yi = p[i][1];
            for(int j = i+1; j<n; j++) {
               const int yj = p[j][1];
                if(yj >= yi && y > yj) {
                   ans++;
                   y = yj;
                   if(yi == yj)break;
                }
            }
        }
        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();