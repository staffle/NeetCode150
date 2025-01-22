class Solution {
public:
    const int SZ = 9, SZ_SQRT = 3;
    bool isRowValid(vector<vector<char>>& board, int r_id) {
        set<char> occ;
        for(int i = 0; i < SZ; i++) {
            char here = board[r_id][i];
            if(here == '.') continue;
            else{
                if(occ.find(here) != occ.end())
                    return false;
                occ.insert(here);
            }
        }
        return true;
    }
    bool isColValid(vector<vector<char>>& board, int c_id) {
        set<char> occ;
        for(int i = 0; i < SZ; i++) {
            char here = board[i][c_id];
            if(here == '.') continue;
            else{
                if(occ.find(here) != occ.end())
                    return false;
                occ.insert(here);
            }
        }
        return true;
    }
    bool isSqrValid(vector<vector<char>>& board, int r_id, int c_id) {
        set<char> occ;
        for(int i = 0; i < SZ_SQRT; i++) {
            for(int j = 0; j < SZ_SQRT; j++) {
                char here = board[r_id + i][c_id + j];
                if(here == '.') continue;
                else{
                    if(occ.find(here) != occ.end())
                        return false;
                    occ.insert(here);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < SZ; i++) 
            if(!isRowValid(board, i))
                return false;
        for(int i = 0; i < SZ; i++) 
            if(!isColValid(board, i))
                return false;
        
        for(int i = 0; i < SZ; i += SZ_SQRT) {
            for(int j = 0; j < SZ; j+= SZ_SQRT) 
                if(!isSqrValid(board, i, j)) return false;
        }
        return true;
    }
};
