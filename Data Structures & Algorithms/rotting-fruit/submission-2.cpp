class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Simpler queue: just needs coordinates!
        queue<pair<int, int>> q; 
        int fresh_count = 0;

        // Step 1: Initialize the queue and count fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }

        // Early exit: if there are no fresh oranges to begin with
        if (fresh_count == 0) return 0;

        int minutes = 0;
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        // Step 2: BFS using the Level-Size Trick
        while (!q.empty()) {
            int size = q.size();
            bool rotted_this_minute = false;

            // Process EXACTLY the oranges that rotted in the current minute
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // Check all 4 neighbors
                for (int d = 0; d < 4; d++) {
                    int nrow = row + dRow[d];
                    int ncol = col + dCol[d];

                    // If valid and fresh
                    if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;  // Rot it immediately in the grid
                        q.push({nrow, ncol});  // Push to next minute's batch
                        fresh_count--;         // One less fresh orange in the world
                        rotted_this_minute = true;
                    }
                }
            }
            
            // Only increment time if we actually rotted something
            if (rotted_this_minute) {
                minutes++;
            }
        }

        // Step 3: Check if we successfully rotted everything
        return fresh_count == 0 ? minutes : -1;
    }
};