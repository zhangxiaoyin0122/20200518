#include <iostream>
#include <time.h>
using namespace std;

//�˵�
int Menu() {
	cout << "====================" << endl;
	cout << "======��Ϸ�˵�======" << endl;
	cout << "=====1.��ʼ��Ϸ=====" << endl;
	cout << "=====2.������Ϸ=====" << endl;
	cout << "====================" << endl;
	cout << "����������ѡ��" << endl;
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
	cout << "�ֵ��������" << endl;
	while (1) {
		cout << "��������Ҫ�����ӵ�λ��:(row,col)" << endl;
		int row = 0;
		int col = 0;
		cin << row << col;
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			cout << "������������" << endl;
			continue;
		}
		if (ChessBoard[row][col] != ' ') {
			cout << "��λ���Ѿ���������" << endl;
			continue;
		}
		ChessBoard[row][col] = 'X';
		break;
	}
}

void ComputerMove(ChessBoard[MAX_ROW][MAX_COL]) {
	cout << "�ֵ�����������" << endl;
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
		cout << "��ϲ��,���ʤ��" << endl;

	}
	else if (winner == '0') {
		cout << "�����,�����Զ��²���" << endl;

	}
	else {
		cout << "�����,�����Զ��²���" << endl;
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
			printf("������������!\n");
		}
	}
	return 0;
}
