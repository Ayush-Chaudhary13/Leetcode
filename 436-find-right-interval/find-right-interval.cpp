class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        vector<pair<int,int>> map;

        for(int i=0;i<intervals.size(); i++)
        {
            map.push_back({intervals[i][0], i});
        }

        sort(map.begin(),map.end());
        vector<int> ans;

        for(auto v: intervals)
        {
            auto it = lower_bound(map.begin(), map.end(), v[1], [](auto a, int b) {return a.first<b;});
            ans.push_back(it==map.end() ? -1 : it->second);
        }
        return ans;
    }
};