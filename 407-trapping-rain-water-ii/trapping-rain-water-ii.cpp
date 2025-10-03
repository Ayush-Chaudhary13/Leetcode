class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};
    int trapRainWater(vector<vector<int>>& arr) {
        
        const int M = arr.size();
        const int N = arr[0].size();

        vector<vector<bool>> visited(M, vector<bool>(N, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i = 0; i < N; i++) {
            pq.push({arr[0][i], 0, i}),
            pq.push({arr[M-1][i], M-1, i});
            visited[0][i] = visited[M-1][i] = true;
        }
        
       
        for(int i = 1; i < M-1; i++) {
            pq.push({arr[i][0], i, 0}),
            pq.push({arr[i][N-1], i, N-1});
            visited[i][0] =  visited[i][N-1] = true;
        }

        int water =0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int h = it[0], r = it[1], c = it[2];
            for(int i =0; i<4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];

                if(nr >= 0 && nr < M && nc >= 0 && nc < N && !visited[nr][nc]){
                    visited[nr][nc] = 1;

                    if(arr[nr][nc] < h){
                        water += h - arr[nr][nc];
                    }
                    pq.push({max(h,arr[nr][nc]),nr,nc});
                }
            }
        }
        return water;
    }
};