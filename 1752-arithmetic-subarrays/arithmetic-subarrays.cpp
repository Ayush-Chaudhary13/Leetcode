class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;

        for(int i= 0;i<l.size(); i++){
            vector<int> arr(nums.begin()+ l[i], nums.begin()+ r[i] + 1);
            sort(arr.begin(),arr.end());
            int diff = arr[1]-arr[0];
            bool flag = true;
            for(int j = 2; j<arr.size(); j++){
                if(arr[j] - arr[j-1] != diff)  {
                    ans.push_back(false);
                    flag = 0;
                    break;
                }
            }
            if(flag) ans.push_back(true);    

         }
         return ans;
        
    }
};