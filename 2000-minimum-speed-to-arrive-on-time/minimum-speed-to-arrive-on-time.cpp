class Solution {
public:
    bool valid(vector<int>& dist, int speed, double hour)
    {
        double time = 0;
        for(int i =0; i<dist.size(); i++)
        {
            time = ceil(time);
            time += (double)dist[i]/speed;
            if(time > hour) return false;
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {

        if(hour < dist.size()-1) return -1;
        long l=1, r=1e7;
        while(l<=r)
        {
            long mid = l +(r-l)/2;
            if(valid(dist,mid,hour)) r = mid-1;
            else l = mid+1;
        }

        return l > 1e7 ? -1 : l;
        
    }
};