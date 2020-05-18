#include <iostream>
#include <time.h>
using namespace std;

//菜单
int Menu() {
	cout << "====================" << endl;
	cout << "======游戏菜单======" << endl;
	cout << "=====1.开始游戏=====" << endl;
	cout << "=====2.结束游戏=====" << endl;
	cout << "====================" << endl;
	cout << "请输入您的选择" << endl;
	int choice;
	cin >> choice;
	return choice;
}

#define MAX_ROW 3
#define MAX_COL 3
void ChessBoardInit(char ChessBoard[MAX_ROW][MAX_COL]) {
	srand((unsigned)time(0));
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++)
			ChessBoard[row][col] = ' ';
	}
}
void ChessBoardPrint(char ChessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		cout << "+---+---+---+" << endl;
		cout << "| ChessBoard[row][0] | ChessBoard[row][1] | ChessBoard[row][2]" << endl;
	}
	cout << "+---+---+---+" << endl;
}

void PlayerMove(char ChessBoard[MAX_ROW][MAX_COL]) {
	cout << "轮到玩家落子" << endl;
	while (1) {
		cout << "请输入您要落棋子的位置:(row,col)" << endl;
		int row = 0;
		int col = 0;
		cin << row << col;
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			cout << "您的输入有误" << endl;
			continue;
		}
		if (ChessBoard[row][col] != ' ') {
			cout << "该位置已经有棋子了" << endl;
			continue;
		}
		ChessBoard[row][col] = 'X';
		break;
	}
}

void ComputerMove(ChessBoard[MAX_ROW][MAX_COL]) {
	cout << "轮到电脑落棋子" << endl;
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (ChessBoard[row][col] != ' ')
			continue;
		ChessBoard[row][col] = 'o';
		break;
	}
}

int IsFull(char ChessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (ChessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char Check(char ChessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		if (ChessBoard[row][0] != ' '
			&&ChessBoard[row][0] == ChessBoard[row][1]
			&& ChessBoard[row][0] == ChessBoard[row][2])
			return ChessBoard[row][0];
	}

	for (int col = 0; row < MAX_COL; col++) {
		if (ChessBoard[0][col] != ' '
			&&ChessBoard[0][col] == ChessBoard[1][col]
			&& ChessBoard[0][col] == ChessBoard[2][col]) {
			return ChessBoard[0][col];
		}
	}

	if (ChessBoard[0][0] != ' '
		&&ChessBoard[0][0] == ChessBoard[1][1]
		&& ChessBoard[0][0] == ChessBoard[2][2]) {
		return ChessBoard[0][0];
	}
	if (ChessBoard[0][2] != ' '
		&&ChessBoard[0][2] == ChessBoard[1][1]
		&& ChessBoard[0][2] == ChessBoard[2][0]) {
		return ChessBoard[0][2];

	}
	if (IsFull(ChessBoard)) {
		return 'Q';
	}
	return ' ';
}

void game() {
	char ChessBoard[MAX_ROW][MAX_COL] = { 0 };
	ChessBoardInit(ChessBoard);
	char winner = ' ';
	while (1) {
		ChessBoardPrint(ChessBoard);
		PlayerMove(ChessBoard);
		winer = Check(ChessBoard);
		if (winner != ' ') {
			break;
		}
		ComputerMove(ChessBoard);
		winner = Check(ChessBoard);
		if (winner != ' ') {
			break;
		}
	}
	ChessBoardPrint(ChessBoard);
	if (winner == 'X') {
		cout << "恭喜您,获得胜利" << endl;

	}
	else if (winner == '0') {
		cout << "您真菜,连电脑都下不过" << endl;

	}
	else {
		cout << "您真菜,连电脑都下不过" << endl;
	}

}
int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			game();
		}
		else if (choice == 0) {
			printf("Goodbye!\n");
			break;
		}
		else {
			printf("您的输入有误!\n");
		}
	}
	return 0;
}
