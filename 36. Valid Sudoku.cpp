/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Example 1:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/


/*
coding 期间遇到多维vector初始化问题
https://github.com/sysuleo/leetcode/blob/master/leetcode/多维vector的初始化.md
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9,vector<bool>(10,false));//第一维指列数，第二位记录数字，未出现为false，出现了则为true
        vector<vector<bool>> row(9,vector<bool>(10,false));//第一维指行数
        vector<vector<bool>> grid(9,vector<bool>(10,false)); //每个grid
        for(int i=0;i<9;i++){ //row index
            for(int j=0;j<9;j++){  //col index
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'0';
                if(row[i][num]==false) row[i][num]=true; //num didn't appeared in row 'i',mark it
                else return false; //num has appeared in row 'i',so reture false
                
                if(col[j][num]==false) col[j][num]=true; //num didn't appeared in col 'j',mark it
                else return false;
                
                int gridindex=(i/3)*3+(j/3); //向下取整，得到当前对应的gridindex
                if(grid[gridindex][num]==false) grid[gridindex][num]=true; //num didn't appeared in grid 'gridindex',mark it
                else return false;
            }
        }
        return true;
    }
};


class Solution { //a little bit faster version
public:
    /*
    Runtime: 20 ms, faster than 53.92% of C++ online submissions for Valid Sudoku.
    Memory Usage: 11.8 MB, less than 42.03% of C++ online submissions for Valid Sudoku.
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() == 0)      return false;
        vector<set<char>> parsedBlockChars(9,set<char>());
        vector<set<char>> parsedRowChars(9,set<char>());
        vector<set<char>> parsedColChars(9,set<char>());
        for(int i=0;i<9;i++){ //row index
            for(int j=0;j<9;j++){  //col index
                if(board[i][j]=='.') continue;
                //
                if(parsedRowChars[i].find(board[i][j])!= parsedRowChars[i].end()) 
                    return false; //num has appeared in row 'i',so reture false
                else parsedRowChars[i].insert(board[i][j]); //num didn't appeared in row 'i',insert
                
                
                if(parsedColChars[j].find(board[i][j])!= parsedColChars[j].end()) 
                    return false;
                else parsedColChars[j].insert(board[i][j]); //num didn't appeared in col 'j'
                
                int Gridindex=(i/3)*3+(j/3); //向下取整
                if(parsedBlockChars[Gridindex].find(board[i][j])!= parsedBlockChars[Gridindex].end()) 
                   return false;
                else parsedBlockChars[Gridindex].insert(board[i][j]); //num didn't appeared in grid 'gridindex',mark it
            }
        }
        return true;
    }
};
