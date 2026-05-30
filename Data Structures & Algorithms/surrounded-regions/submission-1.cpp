class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int rows = board.size();
        int cols = board[0].size();


        //this is for row traversal
        for(int i=0; i<rows; i++){
            if(board[i][0] == 'O') dfs(board,i,0);
            if(board[i][cols-1] == 'O') dfs(board, i, cols-1);
        }

        //now I will check all Os that lie on the edge w.r.t columns
        for(int j=0; j < cols; j++){
            if(board[0][j] == 'O') dfs(board, 0, j); //this is the starting
            if(board[rows-1][j] == 'O') dfs(board,rows-1, j);
        }


        //now corners are done, I will traverse in the middle
        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int rows, int cols){
        //this function's work is to check left right up down
        if(rows < 0 || rows >= board.size() || cols < 0 || cols >= board[0].size() || board[rows][cols] != 'O'){
            return;
        }

        board[rows][cols] = 'S';
        //now directional call
        dfs(board, rows-1, cols); 
        dfs(board, rows+1, cols);
        dfs(board, rows, cols-1);
        dfs(board, rows, cols+1);
    }
};
