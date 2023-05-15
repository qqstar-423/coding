#include <bits/stdc++.h>
// #include <direct.h>

using namespace std;

class Solution {
public:

    bool dfs(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    for(char a = '1'; a <= '9'; a++){
                        if(isvaild(i, j, a, board)){
                            board[i][j] = a;
                            bool check = dfs(board);
                            if(check) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvaild(int row, int col, char a, vector<vector<char>>& board){
        for(int j = 0; j < 9; ++j){
            if(board[row][j] == a) return false;
        }
        for(int i = 0; i < 9; ++i){
            if(board[i][col] == a) return false;
        }
        int startRow = (row / 3) * 3;   // 使用余数来找九宫格开始的索引
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == a) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solveSudoku(vector<vector<char>>& board) {
        return dfs(board);
    }
};

int main()
{

	vector<vector<char>> board = { {'3','.','1','8','.','.','.','.','.'},
								   {'.','.','.','.','.','7','.','.','4'},
								   {'.','.','.','9','2','.','.','7','3'},
								   {'.','.','5','.','.','9','6','.','.'},
								   {'.','2','.','.','1','.','.','4','.'},
								   {'.','.','4','6','.','.','5','.','.'},
								   {'8','1','.','.','9','2','.','.','.'},
								   {'5','.','.','7','.','.','.','.','.'},
								   {'.','.','.','.','.','6','9','.','7'} };

	Solution so;

	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

	bool flag = so.solveSudoku(board);

	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

	if(flag){
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				cout << '[' << board[i][j] << "], ";
			}
			cout << endl;
		}
	}else{
		cout << "失败" << endl;
	}
	

	cout << "solve time cost = " << time_used.count() << " seconds. " << endl;

	return 0;
}



    

