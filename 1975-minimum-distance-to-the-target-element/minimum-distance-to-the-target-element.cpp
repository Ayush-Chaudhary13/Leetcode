class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left =INT_MAX, right= INT_MAX;

        int i = start;
        while(i>=0) {
            if(nums[i] == target) {
                left = abs(start-i);
                cout<<"left =="<<left<<endl;
                break;
            }
            i--;
        }

        int j = start;

        while(j< nums.size()) {
            if(nums[j] == target) {
                right = abs(start-j);
                cout<<"right =="<< right<<endl;
                break;
            }
            j++;
        }

      return min(left,right);  
    }
};