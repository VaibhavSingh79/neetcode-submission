class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCnt = 0;

        if(grid.empty()) return 0;
        for(int i=0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    islandCnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return islandCnt;
    }

    void dfs(vector<vector<char>> &grid, int i, int j){
        //the place where I do the left right checking
        if(i < 0 || i>=grid.size() || j < 0 || j >=grid[0].size() || grid[i][j] != '1'){
            return;
        }

        //else the ans is found
        grid[i][j] = '2';

        //now we do the left right, up down sweep
        dfs(grid, i-1, j); //down
        dfs(grid, i+1, j); //up
        dfs(grid, i, j-1); //left
        dfs(grid, i, j+1);//right
    }
};
