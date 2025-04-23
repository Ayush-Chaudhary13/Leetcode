// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1,end = n-1, firstBad = n;
        while( st <= end){
            int mid = st + (end - st)/2;
            if(isBadVersion (mid)){
                firstBad = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
           
        }
         return firstBad;
        
    }
};