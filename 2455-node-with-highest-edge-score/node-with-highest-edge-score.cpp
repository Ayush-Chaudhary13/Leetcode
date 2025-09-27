class Solution {
public:
    int edgeScore(vector<int>& edges) {

        vector<long long int> indeg(edges.size(),0);
        for(int i =0; i<edges.size(); i++){
             indeg[edges[i]] += i;
        }

        int ans =0;
        for(int i =0; i<indeg.size(); i++){
            if(indeg[i] > indeg[ans]){
                ans = i;
            }
        }
        return ans;
        
    }
};