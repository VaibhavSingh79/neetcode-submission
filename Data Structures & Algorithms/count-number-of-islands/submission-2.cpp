class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int islandCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        // 1. ALLOCATE THE TRACKER
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 2. CHECK BOTH THE GRID AND THE TRACKER
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islandCount++;
                    bfs(grid, visited, i, j); // Pass the tracker by reference!
                }
            }
        }
        
        return islandCount;
    }

private:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int start_i, int start_j) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        
        q.push({start_i, start_j});
        // 3. MARK THE TRACKER, NOT THE GRID
        visited[start_i][start_j] = true; 
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto dir : directions) {
                int new_r = r + dir.first;
                int new_c = c + dir.second;
                
                // 4. CHECK THE TRACKER BEFORE PUSHING
                if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && 
                    grid[new_r][new_c] == '1' && !visited[new_r][new_c]) {
                    
                    q.push({new_r, new_c});
                    visited[new_r][new_c] = true; // Mark the tracker!
                }
            }
        }
    }
};