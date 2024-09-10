#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board){
    vector<vector<int>> row(9, vector<int>(9, 0));
    vector<vector<int>> col(9, vector<int>(9, 0));
    vector<vector<int>> box(9, vector<int>(9, 0));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                int num = board[i][j] - '0' - 1;
                int k = i/3*3 + j/3;
                if(row[i][num] || col[j][num] || box[k][num]){
                    return false;
                }
                row[i][num] = 1;
                col[j][num] = 1;
                box[k][num] = 1;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    if(isValidSudoku(board))
        cout << "true" << endl;
   else
   cout << "false";
}