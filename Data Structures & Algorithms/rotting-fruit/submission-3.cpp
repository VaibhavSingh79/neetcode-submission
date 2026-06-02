class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int freshcnt = 0;

        int minutes = 0;

        //first find what all are rotten
        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if(grid[i][j] == 2){
                    //push the indexes that are like this
                    q.push({i, j});
                }if(grid[i][j]==1){
                    freshcnt++;
                }
            }
        }

        //now we have all the addresses of rotten
        while(!q.empty()){
            int size = q.size(); //I traverse till the size lasts only and not the entire sequence
            bool rotten_rn = false;

            for(int i=0; i < size; i++){
                int rw = q.front().first;
                int cl = q.front().second;
                q.pop();

                int drow[] = {-1,1, 0, 0};
                int dcol[] = {0, 0, 1, -1};
                //check all 4 directions
                for(int d = 0; d < 4; d++){
                    int nrow = rw + drow[d];
                    int ncol = cl + dcol[d];
                    
                    //now if it's valid then I mark it
                    if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        freshcnt --;
                        rotten_rn = true; //this one just rotted 
                    }
                }
            }

            if(rotten_rn == true){
                minutes++;
            }

        }
        return freshcnt == 0 ? minutes : -1;


    }
};
