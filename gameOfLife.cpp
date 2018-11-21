class Solution {
public:
    int count(vector<vector<int>>& board, int i, int j, int k, int l) {
        int count = 0;
         // Checking left corner 
        if(i > 0 && j > 0 && i < board.size() && j < board[0].size()) {
            if(board[i-1][j-1] == k || board[i-1][j-1] == l) {
                count += 1;
            }
        }  
        //Checking upper cell
        if(i>0 && i < board.size()) {
            if(board[i-1][j] == k || board[i-1][j] == l) {
                count += 1;
            }
        }
        //checking right corner cell
        if(i > 0 && j >= 0 && i < board.size() && j < board[0].size() - 1) {
            if(board[i-1][j+1] == k || board[i-1][j+1] == l) {
                count += 1;
            }
        } 
        //checking right cell
        if(j >= 0 && j < board[0].size() - 1) {
            if(board[i][j+1] == k || board[i][j+1] == l) {
                count += 1;
            }
        }
        //checking down right
        if(i>=0 && j >=0 && i < board.size() -1 && j <  board[0].size()-1) {
            if(board[i+1][j+1] == k || board[i+1][j+1] == l) {
                count += 1;
            }
        }
        //checking down
        if(i>=0 && i < board.size() - 1) {
            if(board[i+1][j] == k || board[i+1][j] == l) {
                count += 1;
            }
        }
        // Checking left corner 
        if(i >= 0 && j > 0 && i < board.size()-1 && j < board[0].size()) {
            if(board[i+1][j-1] == k || board[i+1][j-1] == l) {
                count += 1;
            }
        } 
        //checking left cell
        if(j > 0 && j < board[0].size()) {
            if(board[i][j-1] == k || board[i][j-1] == l) {
                count += 1;
            }
        }
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[0].size(); j++) {
                int alive = count(board, i, j, 1, 2);
                if((board[i][j] == 1) && alive < 2) board[i][j] = 2;
                if((board[i][j] == 1) && (alive > 3)) board[i][j] = 2;
                if((board[i][j] == 0) && (alive == 3)) board[i][j] = 3;
            }
        }
        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[0].size(); j++) {
                if(board[i][j] == 2) board[i][j] = 0;
                if(board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};
