class Solution {
public:

    bool isValid(vector<vector<char>> ch,char ch1,int i,int j){
        for(int k=0;k<9;k++){
            if(ch[i][k]==ch1) return false;
            if(ch[k][j]==ch1) return false;
            if(ch[3*(i/3)+k/3][3*(j/3)+k%3]==ch1) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) {
                char ch=board[i][j];
                if(ch!='.'){
                    board[i][j]='.';
                    if(!isValid(board,ch,i,j))
                        return false;
                    board[i][j]=ch;
                }
            }
        }
        return true;
    }
};