class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int sx = start[0], sy = start[1];
        int tx = target[0], ty = target[1];
        
        map<pair<int, int>, int> dist;
        dist[{tx, ty}] = INT_MAX;
        dist[{sx, sy}] = 0;
    
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,   greater<tuple<int, int, int>>> pq;
        pq.push({0, sx, sy});

        for (auto& road : specialRoads) {
            dist[{road[0], road[1]}] = INT_MAX;
            dist[{road[2], road[3]}] = INT_MAX;
        }
        
        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            
            if (cost > dist[{x, y}]) continue;
            int directCost = cost + abs(tx - x) + abs(ty - y);
            if (directCost < dist[{tx, ty}]) {
                dist[{tx, ty}] = directCost;
            }
            for (auto& road : specialRoads) {
                int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], roadCost = road[4];
                
                
                int newCost = cost + abs(x1 - x) + abs(y1 - y) + roadCost;
                if (newCost < dist[{x2, y2}]) {
                    dist[{x2, y2}] = newCost;
                    pq.push({newCost, x2, y2});
                }
            }
        } 
        return dist[{tx, ty}];
    }
};