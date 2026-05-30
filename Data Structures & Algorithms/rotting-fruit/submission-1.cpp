class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int vis[rows][cols];
        int cntFresh = 0;
        int tm = 0;
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0}); //considering initially my time is 0
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j]=0;
                }

                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        int cnt = 0; //this is for the rotten ones
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int rw = q.front().first.first;
            int cl = q.front().first.second;

            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i=0; i < 4; i++){ //because there are 4 possibilites
                int drw = rw + drow[i];
                int dcl = cl + dcol[i];

                if(drw>=0 && drw < rows && dcl >=0 && dcl < cols && vis[drw][dcl]!=2 && grid[drw][dcl]==1){ //anything but 2
                    q.push({{drw, dcl}, t+1});
                    vis[drw][dcl]=2; //marking the neighbors as rotten
                    cnt++;
                }
            }
        }
        if(cntFresh != cnt) return -1;
        return tm;
    }
};
