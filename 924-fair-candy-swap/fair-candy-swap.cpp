class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int suma =0, sumb =0;

        for(auto i: a) suma += i;
        for(auto i: b) sumb += i;

        int target = (suma+sumb)/2;
        int da = target-suma;

        set<int> bob;
        vector<int> ans(2,0);

        for(int i =0; i<b.size(); i++)bob.insert(b[i]);

        for(int i =0; i<a.size(); i++) {
            int c = a[i] +da;

            if(bob.count(c)) {
                ans[0] = a[i];
                ans[1] = c;
                return ans;
            }
        }
        return ans;
        
    }
};