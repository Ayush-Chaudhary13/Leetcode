class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int no= arr[0], yes = INT_MIN, ans = arr[0];

        for(int i =1; i<arr.size(); i++)
        {
            int prev_no = no;
            int prev_yes = yes;

            no = max(prev_no + arr[i], arr[i]);
            int v2;
            if(prev_yes == INT_MIN) v2 = arr[i];
            else v2 = prev_yes + arr[i];

            yes = max(v2, prev_no);

            ans = max({ans, no, yes});
        }
        return ans;
    }
};