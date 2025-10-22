class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> points_cover;
        unordered_map<int, int> cnt_points;
        set<int> points;

        for (int num : nums) {
            cnt_points[num]++;
            points_cover[num - k]++;
            points_cover[num + k + 1]--;
            points.insert(num);
            points.insert(num - k);
            points.insert(num + k + 1);
        }

        int res = 0;
        int points_cover_this_point = 0;

        for (int point : points) {
            points_cover_this_point += points_cover[point];
            res = max(res, cnt_points[point] + 
                        min(points_cover_this_point - cnt_points[point], numOperations));
        }

        return res;
    }
};