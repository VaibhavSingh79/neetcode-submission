class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cntFresh=0;
        int tm = 0; //current time variable
        queue<pair<pair<int, int>, int>> q;
        int vis[rows][cols];
        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0,1,0,-1};
        int cnt = 0;
        while(!q.empty()){
            int rw = q.front().first.first;
            int cl = q.front().first.second;

            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i=0; i < 4; i++){
                int row = rw + drow[i];
                int col = cl + dcol[i];

                if(row >=0 && row < rows && col >=0 && col < cols && vis[row][col]!=2 && grid[row][col]==1){
                    q.push({{row, col}, t+1});
                    vis[row][col] = 2;
                    cnt ++;
                }
            }
        }
        if(cnt != cntFresh) return -1;
        return tm;
    }
};
