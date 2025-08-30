class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<pair<int,char>> row,col,grid;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')continue;
                
                if(board[i][j]!='.'){
                int count=(i/3)*3 +j/3;
                
                if(row.find({i,board[i][j]})==row.end())
                    row.insert({{i,board[i][j]}});
                 else return false;

                if(col.find({j,board[i][j]})==col.end())
                    col.insert({{j,board[i][j]}});
                 else return false;

                if(grid.find({count,board[i][j]})==grid.end())
                    grid.insert({{count,board[i][j]}});
                 else  return false;
                }
            }
        }
        return true;     
    }
};