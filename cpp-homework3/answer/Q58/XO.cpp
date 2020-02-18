#include<iostream>

using namespace std;

const char* X_Success = "X Success";
const char* O_Success = "O Success";
const char* Dogfall = "Dogfall";

class Board {
public:
	static void setBoard(int x, int y, int player, int** board) {
		if (player == 1) {
			board[x][y] = 1;
		}
		else {
			board[x][y] = 2;
		}
	}
};

class Piece {
private:
	int** board;
	int size;
	int rule;
public:
	static int isWin(int** board, int size, int rule);
	static int isRow(int** board, int size, int rule, int player);
	static int isCol(int** board, int size, int rule, int player);
	static int isCross1(int** board, int size, int rule, int player);
	static int isCross2(int** board, int size, int rule, int player);
};

int isFull(int** board, int size, int rule) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

int Piece::isRow(int** board, int size, int rule, int player){
	int row = 0;
	for (int i = 0; i < size; i++) {
		row = 0;
		for (int j = 0; j < size; j++) {
			if (board[i][j] == player) {
				row++;
			}
			else if (row != 0 && board[i][j] != player) {
				row = 0;
				break;
			}
			if (row == rule) {
				goto end;
			}
		}
	}
end:
	return row;
}

int Piece::isCol(int** board, int size, int rule, int player) {
	int col = 0;
	for (int i = 0; i < size; i++) {
		col = 0;
		for (int j = 0; j < size; j++) {
			if (board[j][i] == player) {
				col++;
			}
			else if (col != 0 && board[j][i] != player) {
				col = 0;
				break;
			}
			if (col == rule) {
				goto end;
			}
		}
	}
end:
	return col;
}

int Piece::isCross1(int** board, int size, int rule, int player) {
	int cross = 0;
	int j = 0;
	while (j <= size - rule) {
		for (int i = 0; i < size; i++) {
			if ((i + j) < size && board[i][i+j] == player) {
				cross++;
			}
			else if ((i + j) < size && cross != 0 && board[i][i+j] != player) {
				cross = 0;
				break;
			}
			if (cross == rule) {
				goto end;
			}
		}
		j++;
	}	
end:
	return cross;
}

int Piece::isCross2(int** board, int size, int rule, int player) {
	int cross = 0;
	int j = 0;
	while (j <= size - rule) {
		for (int i = 0; i < size; i++) {
			if ((size - i - j) < size && board[i][size - i - j] == player) {
				cross++;
			}
			else if ((size - i - j) < size && cross != 0 && board[i][size - i - j] != player) {
				cross = 0;
				break;
			}
			if (cross == rule) {
				goto end;
			}
		}
		j++;
	}
end:
	return cross;
}


int Piece::isWin(int** board, int size, int rule) {
	int result = -1;
	int row1 = Piece::isRow(board, size, rule, 1);
	int col1 = Piece::isCol(board, size, rule, 1);
	int cross11 = Piece::isCross1(board, size, rule, 1);
	int cross12 = Piece::isCross2(board, size, rule, 1);
	int row2 = Piece::isRow(board, size, rule, 2);
	int col2 = Piece::isCol(board, size, rule, 2);
	int cross21 = Piece::isCross1(board, size, rule, 2);
	int cross22 = Piece::isCross2(board, size, rule, 2);
	//cout << row1 << " " << col1 << " " << cross11 << endl;
	//cout << row2 << " " << col2 << " " << cross21 << endl;

	if (row1 == rule || col1 == rule || cross11 == rule || cross12 == rule) {
		result = 1;
	}
	else if (row2 == rule || col2 == rule || cross21 == rule || cross22 == rule) {
		result = 2;
	}
	else if (isFull(board, size, rule) == 1) {
		result = 0;
	}
	return result;
}

int main() {
	int size, rule;
	cin >> size >> rule;
	int** board = new int*[size];
	for (int i = 0; i < size; i++) {
		board[i] = new int[size];
		for (int j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	} 
	
	int result = -1;
	int x, y;
	int player = 1;
	while (result == -1) {
		cin >> x >> y;
		Board::setBoard(x, y, player, board);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				//cout << board[i][j] << " ";
			}
			//cout << endl;
		}
		if (player == 1) {
			player = 2;
		}
		else if (player == 2) {
			player = 1;
		}
		result = Piece::isWin(board, size, rule);
	}

	if (result == 0) {
		cout << "Dogfall";
	}
	else if (result == 1) {
		cout << "O Success";
	}
	else if (result = 2) {
		cout << "X Success";
	}
	
	for (int i = 0; i < size; i++) {
		delete[] board[i];
	}
	delete board;

	//system("pause");
}