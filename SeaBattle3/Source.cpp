#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
using namespace std;
#define widght 11

//
//char plus = '+';
char space = ' ';
char numbers[10] = { '1', '2', '3', '4','5','6','7','8','9','X' };
char letters[10] = { 'a', 'b', 'c', 'd','e','f','j','h','i','j' };
char symbols[3] = { '*', '.', '+'};
//

void show_ground(char b1[][widght]);

void gamePvp(char* b1, char* b2, char* b3, char* b4);
void gamePve(char* b1, char* b2, char* b3, char* b4);

void fill_ground_space(char b1[][widght]);
void fill_ground_player(char b1[][widght]);
void fill_ground_random(char b1[][widght]);

void bang(char* b1, char* b2);
void bang_computer(char* b1, char* b2);
void show_battle_ground(char* b1, char* b2);

int main() {

	srand(time(NULL));
	int n = 0; //���������� ��� ������ ����� ������ �� ���
	//Game g;
	char battle_ground_first_player_ship[widght][widght];
	char battle_ground_first_player_bang[widght][widght];
	char battle_ground_second_player_ship[widght][widght];
	char battle_ground_second_player_bang[widght][widght];
	//���������� ����� ���������
	fill_ground_space(battle_ground_first_player_ship);
	fill_ground_space(battle_ground_first_player_bang);
	fill_ground_space(battle_ground_second_player_ship);
	fill_ground_space(battle_ground_second_player_ship);
	//--------------------------------------------------
	int menu;
	do {
		system("cls");
		cout << "\tMain Menu" << endl;
		cout << "1 - Player vs Player " << endl;
		cout << "2 - Player vs Computer " << endl;
		cout << "3 - test " << endl;
		cout << "4 - show bg" << endl;
		cout << "0 - exit" << endl;
		cout << ">>>: ";
		cin >> menu;
		switch (menu) {
		case 1: cout << "PvP" << endl; break;
		case 2: cout << "PvE" << endl; break;
		case 3: fill_ground_player(battle_ground_first_player_ship); break;
		case 4: show_ground(battle_ground_first_player_ship); system("pause"); break;
		}
	} while (menu != 0);

	return 0;
}

void fill_ground_space(char b1[][widght]) {

	b1[0][0] = '+';

	for (int i = 0; i < 1; i++) {
		for (int j = 1; j < widght; j++) {
			b1[i][j] = numbers[j - 1];
		}
	}

	for (int i = 1; i < widght; i++) {
		for (int j = 0; j < 1; j++) {
			b1[i][j] = letters[i - 1];
		}
	}

	for (int i = 1; i < widght; i++) {
		for (int j = 1; j < widght; j++) {
			b1[i][j] = space;
		}
	}
}

void show_ground(char b1[][widght]) {
	system("cls");
	for (int i = 0; i < widght; i++) {
		for (int j = 0; j < widght; j++) {
			cout << b1[i][j] << " ";
		}cout << endl;
	}
	//system("pause");
}

bool chek_random_left_first(char b1[][widght],const int &x_rand_for_start_ship,const int &y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_left_second(char b1[][widght],const int &x_rand_for_start_ship,const int &y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_left_therd(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[2]
		) chek = true;
		return chek;
}
bool chek_random_left_fourth(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_up_first(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_up_second(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_up_therd(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_up_fourth(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
void fill_ground_random(char b1[][widght]) {
	system("cls");
	bool flag = 0;
	int ship_count = 10;
	//4 palubi
	int dir = rand() % 2;
	if (dir == 0) {
		do
		{
			//���������� ��������� ����� �������
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			cout << "4 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl << endl;
			if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_left_fourth(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//���������� �������
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] = symbols[0];
							//���������� ������� ������ �������
								//��������� ������� ���� 
							if (x_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 3] = symbols[1];
							}
							//��������� ������� ����//������� ���� �� ������ ���� ������
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 3] = symbols[1];
							}
							//��������� ������� ����� 
							if (y_rand_for_start_ship - 3 > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 4] = symbols[1];//����������� ����� �����
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 4] = symbols[1];//������� ����� �����
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 4] = symbols[1];//������ ����� �����
							}
							//��������� ������� ������ //������� ������ �� ������ ���� ������ 
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];//���������� ������ �����
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];//������� ������ �����
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];//������ ������ �����
							}
							flag = true;
							ship_count--;
							cout << "4 palub ship is bilding!" << endl;
						}
					}
				}
			}
		} while (flag != true);
		flag = false;
		show_ground(b1);
	} //����� 
	else {
		do
		{
			//���������� ��������� ����� �������
			int x_rand_for_start_ship = rand() % 11;
			int y_rand_for_start_ship = rand() % 11;
			cout << "4 palubi: ";
			cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl << endl;
			if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
				if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_up_fourth(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//���������� �������
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] = symbols[0];
							//���������� ������� ������ �������
								//��������� ������� ���� 
							if (x_rand_for_start_ship - 3 > 1) {
								b1[x_rand_for_start_ship - 4][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 4][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship - 4][y_rand_for_start_ship + 1] = symbols[1];
							}
							//��������� ������� ����
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							}
							//��������� ������� ����� 
							if (y_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship - 1] = symbols[1];
							}
							//��������� ������� ������ 
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship + 1] = symbols[1];
							}
							flag = true;
							ship_count--;
							cout << "4 palub ship is bilding!" << endl;
						}
					}
				}
			}
		} while (flag != true);
		flag = false;
		show_ground(b1);
	} //�����

	//3 palubi
	do {
		dir = rand() % 2;
		if (dir == 0) {
			do
			{
				//���������� ��������� ����� �������
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "3 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << endl;
				if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_left_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//���������� �������
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[0];
							//���������� ������� ������ �������
								//��������� ������� ����
							if (x_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
							}
							//��������� ������� ����
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
							}
							//��������� ������� �����
							if (y_rand_for_start_ship - 2 > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] = symbols[1];
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 3] = symbols[1];
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 3] = symbols[1];
							}
							//��������� ������� ������
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
								if (x_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
								if (x_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							}
							flag = true;
							ship_count--;
							cout << "3 palub ship is bilding!" << endl;
						}
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //����� 
		else {
			do
			{
				//���������� ��������� ����� �������
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "3 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						if (chek_random_up_therd(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
							//���������� �������
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[0];
							//���������� ������� ������ �������
								//��������� ������� ����
							if (x_rand_for_start_ship - 2 > 1) {
								b1[x_rand_for_start_ship - 3][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship - 3][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship - 3][y_rand_for_start_ship + 1] = symbols[1];
							}
							//��������� ������� ����
							if (x_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
								if (y_rand_for_start_ship > 1)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
								if (y_rand_for_start_ship < 10)
									b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							}
							//��������� ������� �����
							if (y_rand_for_start_ship > 1) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
							}
							//��������� ������� ������
							if (y_rand_for_start_ship < 10) {
								b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
							}
							flag = true;
							ship_count--;
							cout << "3 palub ship is bilding!" << endl;
						}
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //�����
	} while (ship_count > 7);


	//2 palubi
	do {
		dir = rand() % 2;
		if (dir == 0) {
			do
			{
				//���������� ��������� ����� �������
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "2 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_left_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)
						) {
						//���������� �������
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
						//���������� ������� ������ �������
							//��������� ������� ����
						if (x_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						}
						//��������� ������� ����
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
						}
						//��������� ������� �����
						if (y_rand_for_start_ship - 1 > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[1];
							if (x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 2] = symbols[1];
							if (x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 2] = symbols[1];
						}
						//��������� ������� ������
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							if (x_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
							if (x_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						flag = true;
						ship_count--;
						cout << "2 palub ship is bilding!" << endl;
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //����� 
		else {
			do
			{
				//���������� ��������� ����� �������
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "2 palubi: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					if (chek_random_up_second(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
						//���������� �������
						b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[0];
						//���������� ������� ������ �������
							//��������� ������� ����
						if (x_rand_for_start_ship - 1 > 1) {
							b1[x_rand_for_start_ship - 2][y_rand_for_start_ship] = symbols[1];
							if (y_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship - 1] = symbols[1];
							if (y_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship - 2][y_rand_for_start_ship + 1] = symbols[1];
						}
						//��������� ������� ����
						if (x_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
							if (y_rand_for_start_ship > 1)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
							if (y_rand_for_start_ship < 10)
								b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						//��������� ������� �����
						if (y_rand_for_start_ship > 1) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						}
						//��������� ������� ������
						if (y_rand_for_start_ship < 10) {
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
						}
						flag = true;
						ship_count--;
						cout << "2 palub ship is bilding!" << endl;
					}
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //�����
	} while (ship_count > 4);


	//1 palubi
	do {
		dir = rand() % 2;
		if (dir == 0) {
			do
			{
				//���������� ��������� ����� �������
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "1 paluba: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_left_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					//���������� �������
					b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
					//���������� ������� ������ �������
						//��������� ������� ����
					if (x_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
					}
					//��������� ������� ����
					if (x_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
					}
					//��������� ������� �����
					if (y_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
						if (x_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						if (x_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
					}
					//��������� ������� ������
					if (y_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
						if (x_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
						if (x_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					flag = true;
					ship_count--;
					cout << "1 palub ship is bilding!" << endl;
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //����� 
		else {
			do
			{
				//���������� ��������� ����� �������
				int x_rand_for_start_ship = rand() % 11;
				int y_rand_for_start_ship = rand() % 11;
				cout << "1 paluba: ";
				cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
				if (chek_random_up_first(b1, x_rand_for_start_ship, y_rand_for_start_ship)) {
					//���������� �������
					b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
					//���������� ������� ������ �������
						//��������� ������� ����
					if (x_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship - 1][y_rand_for_start_ship] = symbols[1];
						if (y_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 1] = symbols[1];
						if (y_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					//��������� ������� ����
					if (x_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] = symbols[1];
						if (y_rand_for_start_ship > 1)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 1] = symbols[1];
						if (y_rand_for_start_ship < 10)
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
					}
					//��������� ������� �����
					if (y_rand_for_start_ship > 1) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[1];
					}
					//��������� ������� ������
					if (y_rand_for_start_ship < 10) {
						b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
					}
					flag = true;
					ship_count--;
					cout << "1 palub ship is bilding!" << endl;
				}
			} while (flag != true);
			flag = false;
			show_ground(b1);
		} //�����
	} while (ship_count > 0);
	system("pause");
}

bool chek_no_symbols(char b1[][widght], int i, int j) {
	bool chek = false;
	if (b1[i][j] != symbols[0] &&
		b1[i][j] != symbols[1] &&
		b1[i][j] != symbols[2]
		)chek = true;
	return chek;
}
bool chek_no_numbers(char b1[][widght], int i, int j) {
	bool chek = false;
	if (b1[i][j] != numbers[0] &&
		b1[i][j] != numbers[1] &&
		b1[i][j] != numbers[2] &&
		b1[i][j] != numbers[3] &&
		b1[i][j] != numbers[4] &&
		b1[i][j] != numbers[5] &&
		b1[i][j] != numbers[6] &&
		b1[i][j] != numbers[7] &&
		b1[i][j] != numbers[8] &&
		b1[i][j] != numbers[9]
		)chek = true;
	return chek;
}
bool chek_no_letters(char b1[][widght], int i, int j) {
	bool chek = false;
	if (b1[i][j] != letters[0] &&
		b1[i][j] != letters[1] &&
		b1[i][j] != letters[2] &&
		b1[i][j] != letters[3] &&
		b1[i][j] != letters[4] &&
		b1[i][j] != letters[5] &&
		b1[i][j] != letters[6] &&
		b1[i][j] != letters[7] &&
		b1[i][j] != letters[8] &&
		b1[i][j] != letters[9]
		)chek = true;
	return chek;
}

bool chek_random_right_first(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_right_second(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_right_therd(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 2] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_right_fourth(char b1[][widght], int x_rand_for_start_ship, int y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship + 3] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_down_first(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_down_second(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship + 1][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_down_therd(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship + 2][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
bool chek_random_down_fourth(char b1[][widght], const int& x_rand_for_start_ship, const int& y_rand_for_start_ship) {
	bool chek = false;
	if (b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[0] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[1] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[2] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[3] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[4] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[5] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[6] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[7] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[8] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != numbers[9] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[0] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[1] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[2] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[3] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[4] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[5] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[6] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[7] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[8] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != letters[9] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != symbols[0] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != symbols[1] &&
		b1[x_rand_for_start_ship + 3][y_rand_for_start_ship] != symbols[2]
		) chek = true;
	return chek;
}
void copy_ground(char b1[][widght], char b2[][widght]) {
	for (int i = 0; i < widght; i++) {
		for (int j = 0; j < widght; j++) {
			b2[i][j] = b1[i][j];
		}
	}
}
void dir_down(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	if (x_start == x_finish) {//����� ����������� horizont
		//��������� ������ �������
		for (int i = x_start, j = y_start; j <= y_finish; j++) {
			b1[i][j] = space;
		}
		//���������� ����� �������
		x_start++;
		x_finish = x_start;
		//�������, ��� �� �� �������� �� ������ ������� �������������� ������� x_start < widght � �� ����� ���� �� ���� '.'
		if (x_start < widght && b1[x_start][y_start] != symbols[1] && b1[x_finish][y_finish] != symbols[1]) {
			for (int i = x_start, j = y_start; j <= y_finish; j++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
		else {
			x_start--;
			x_finish = x_start;
			for (int i = x_start, j = y_start; j <= y_finish; j++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}

	}
	else {//����� ����������� vertical
		//��������� ������ �������
		for (int i = x_start, j = y_start; i <= x_finish; i++) {
			b1[i][j] = space;
		}
		//���������� ����� �������
		x_start++;
		x_finish++;
		//�������, ��� �� �� �������� �� ������ ������� �������������� ������� x_finish < widght + 1
		if (x_finish < widght && b1[x_finish][y_finish] != symbols[1]) {
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
		else{
			x_start--;
			x_finish--;
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
	}
}
void dir_up(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	if (x_start == x_finish) {//����� ����������� horizont
		for (int i = x_start, j = y_start; j <= y_finish; j++) {
			b1[i][j] = space;
		}
		//���������� ����� �������
		x_start--;
		x_finish = x_start;
		if (x_start > 0 && b1[x_start][y_start] != symbols[1] && b1[x_finish][y_finish] != symbols[1]) {
			for (int i = x_start, j = y_start; j <= y_finish; j++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
		else{
			x_start++;
			x_finish = x_start;
			for (int i = x_start, j = y_start; j <= y_finish; j++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
	}
	else {//����� ����������� vertical
		for (int i = x_start, j = y_start; i <= x_finish; i++) {
			b1[i][j] = space;
		}
		//���������� ����� �������
		x_start--;
		x_finish--;
		if (x_start > 0 && b1[x_start][y_start] != symbols[1]) {
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
		else {
			x_start++;
			x_finish++;
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
	}
}
void dir_right(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	//cout << "Dir right;" << endl;
	//cout << "Start det: b1[" << x_start << "][" << y_start << "]" << endl;
	//cout << "Finish det: b1[" << x_finish << "][" << y_finish << "]" << endl;
	//system("pause");
	if (x_start == x_finish) {//����� ����������� horizont
		b1[x_start][y_start] = space;
		y_start++;
		y_finish++;
		//cout << "befor dir right;" << endl;
		//cout << "Start det: b1[" << x_start << "][" << y_start << "]" << endl;
		//cout << "Finish det: b1[" << x_finish << "][" << y_finish << "]" << endl;
		//system("pause");
		if (y_finish < widght && b1[x_finish][y_finish] != symbols[1]) {
			//for (int i = x_start, j = y_start; j < y_finish; j++) {
			//	b1[i][j] = symbols[0];
			//}
			b1[x_finish][y_finish] = symbols[0];
			show_ground(b1);
		}
		else {
			y_start--;
			y_finish--;
			b1[x_start][y_start] = symbols[0];
			show_ground(b1);
		}

	}
	else {//����� ����������� vertical
		for (int i = x_start, j = y_start; i <= x_finish; i++) {
			b1[i][j] = space;
		}
		//���������� ����� �������
		y_start++;
		y_finish = y_start;
		if (y_start < widght && b1[x_finish][y_finish] != symbols[1] && b1[x_start][y_start] != symbols[1]) {
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
		else {
			y_start--;
			y_finish = y_start;
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}

	}
}
void dir_left(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	if (x_start == x_finish) {//����� ����������� horizont
		b1[x_finish][y_finish] = space;
		y_start--;
		y_finish--;
		if (y_start > 0 && b1[x_start][y_start] != symbols[1]) {
			//for (int i = x_start, j = y_start; j <= y_finish; j++) {
			//	b1[i][j] = symbols[0];
			//}
			b1[x_start][y_start] = symbols[0];
			show_ground(b1);
		}
		else {
			y_start++;
			y_finish++;
			b1[x_finish][y_finish] = symbols[0];
		}
	}
	else {//����� ����������� vertical
		for (int i = x_start, j = y_start; i <= x_finish; i++) {
			b1[i][j] = space;
		}
		//���������� ����� �������
		y_start--;
		y_finish = y_start;
		if (y_finish > 0 && b1[x_start][y_start] != symbols[1] && b1[x_finish][y_finish] != symbols[1]) {
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
		else {
			y_start++;
			y_finish = y_start;
			for (int i = x_start, j = y_start; i <= x_finish; i++) {
				b1[i][j] = symbols[0];
			}
			show_ground(b1);
		}
	}
}
void fill_det_around_ship(char b1[][widght]) {
	for (int i = 0; i < widght; i++) {
		for (int j = 0; j < widght; j++) {
			if (b1[i][j] == symbols[0]) {
				//if (i + 1 > 0 && i + 1 < 10 && j + 1 > 0 && j + 1 < 10) {
				//	b1[i + 1][j + 1] = symbols[1];
				//}
				//if (i - 1 > 0 && i - 1 < widght && j - 1 > 0 && j - 1 < widght) {
				//	b1[i - 1][j - 1] = symbols[1];
				//}
				//if (i + 1 > 0 && i + 1 < 10 && j - 1 > 0 && j - 1 < widght) {
				//	b1[i + 1][j - 1] = symbols[1];
				//}
				//if (i - 1 > 0 && i - 1 < widght && j + 1 > 0 && j + 1 < 10) {
				//	b1[i - 1][j + 1] = symbols[1];
				//}
				//������ �������
				if (b1[i + 1][j] != symbols[0] && i + 1 > 0 && i + 1 < widght) {
					b1[i + 1][j] = symbols[1];
					if(j + 1 < widght)
						b1[i + 1][j + 1] = symbols[1];//����� ������ ������ �������
					if(j - 1 > 0)
						b1[i + 1][j - 1] = symbols[1];//����� ����� ������ �������
				}
				//������� ������� ����������� �������
				if (b1[i - 1][j] != symbols[0] && i - 1 > 0 && i - 1 < widght) {
					b1[i - 1][j] = symbols[1];
					if (j + 1 < widght)
						b1[i - 1][j + 1] = symbols[1];//����� ������ ������� �������
					if (j - 1 > 0)
						b1[i - 1][j - 1] = symbols[1];//����� ����� ������� �������
				}
				//������ ������� ����������� �������
				if (b1[i][j + 1] != symbols[0] && j + 1 > 0 && j + 1 < widght) {
					b1[i][j + 1] = symbols[1];
				}
				//����� ������� ����������� �������
				if (b1[i][j - 1] != symbols[0] && j - 1 > 0 && j - 1 < widght) {
					b1[i][j - 1] = symbols[1];
				}
			}
		}
	}
	show_ground(b1);
	system("pause");
}

void tap_ship_four_part_random_horizont(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	bool flag = false;
	int x;
	int y;
	do {
		x = rand() % 11;
		y = rand() % 11;
		if (chek_random_left_first(b1, x, y)) {
			if (chek_random_left_second(b1, x, y)) {
				if (chek_random_left_therd(b1, x, y)) {
					if (chek_random_left_fourth(b1, x, y)) {
						//���������� �������
						b1[x][y] = symbols[0];
						b1[x][y - 1] = symbols[0];
						b1[x][y - 2] = symbols[0];
						b1[x][y - 3] = symbols[0];
						flag = true;
					}
				}
			}
		}
	} while (flag != true);
	x_start = x;
	y_start = y - 3;
	x_finish = x;
	y_finish = y;
}
void tap_ship_four_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	bool flag = false;
	int x;
	int y;
	do {
		x = rand() % 11;
		y = rand() % 11;
		if (chek_random_up_first(b1, x, y)) {
			if (chek_random_up_second(b1, x, y)) {
				if (chek_random_up_therd(b1, x, y)) {
					if (chek_random_up_fourth(b1, x, y)) {
						//���������� �������
						b1[x][y] = symbols[0];
						b1[x - 1][y] = symbols[0];
						b1[x - 2][y] = symbols[0];
						b1[x - 3][y] = symbols[0];
						flag = true;
					}
				}
			}
		}
	} while (flag != true);
	x_start = x - 3;
	y_start = y;
	x_finish = x;
	y_finish = y;
}
void tap_ship_three_part_random_horizont(char b1[][widght], int &x_start, int &y_start, int &x_finish, int &y_finish) {
	bool flag = false;
	int x;
	int y;
	do {
		x = rand() % 11;
		y = rand() % 11;
		if (chek_random_left_first(b1, x, y)) {
			if (chek_random_left_second(b1, x, y)) {
				if (chek_random_left_therd(b1, x, y)) {
					//���������� �������
					b1[x][y] = symbols[0];
					b1[x][y - 1] = symbols[0];
					b1[x][y - 2] = symbols[0];
					flag = true;
				}
			}
		}
	} while (flag != true);
	x_start = x;
	y_start = y - 2;
	x_finish = x;
	y_finish = y;
}
void tap_ship_three_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	bool flag = false;
	int x;
	int y;
	do {
		x = rand() % 11;
		y = rand() % 11;
		if (chek_random_up_first(b1, x, y)) {
			if (chek_random_up_second(b1, x, y)) {
				if (chek_random_up_therd(b1, x, y)) {
					//���������� �������
					b1[x][y] = symbols[0];
					b1[x - 1][y] = symbols[0];
					b1[x - 2][y] = symbols[0];
					flag = true;
				}
			}
		}
	} while (flag != true);
	x_start = x - 2;
	y_start = y;
	x_finish = x;
	y_finish = y;
}
void tap_ship_two_part_random_horizont(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	bool flag = false;
	int x;
	int y;
	do {
		x = rand() % 11;
		y = rand() % 11;
		if (chek_random_left_first(b1, x, y)) {
			if (chek_random_left_second(b1, x, y)) {
				//���������� �������
				b1[x][y] = symbols[0];
				b1[x][y - 1] = symbols[0];
				flag = true;
			}
		}
	} while (flag != true);
	x_start = x;
	y_start = y - 1;
	x_finish = x;
	y_finish = y;
}
void tap_ship_two_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	bool flag = false;
	int x;
	int y;
	do {
		x = rand() % 11;
		y = rand() % 11;
		if (chek_random_up_first(b1, x, y)) {
			if (chek_random_up_second(b1, x, y)) {
				//���������� �������
				b1[x][y] = symbols[0];
				b1[x - 1][y] = symbols[0];
				flag = true;
			}
		}
	} while (flag != true);
	x_start = x - 1;
	y_start = y;
	x_finish = x;
	y_finish = y;
}
void tap_ship_one_part_random_vertical(char b1[][widght], int& x_start, int& y_start, int& x_finish, int& y_finish) {
	bool flag = false;
	int x;
	int y;
	do {
		x = rand() % 11;
		y = rand() % 11;
		if (chek_random_up_first(b1, x, y)) {
			//���������� �������
			b1[x][y] = symbols[0];
			flag = true;
		}
	} while (flag != true);
	x_start = x;
	y_start = y;
	x_finish = x;
	y_finish = y;
}
int count_ship_part(char b1[][widght]) {
	int count_part = 0;
	for (int i = 0; i < widght; i++) {
		for (int j = 0; j < widght; j++) {
			if (b1[i][j] == symbols[0]) count_part++;
		}
	}
	return count_part;
}

void fill_ground_player(char b1[][widght]) {
	system("cls");
	char temp[widght][widght];
	char dir;
	int x_start;
	int y_start;
	int x_finish;
	int y_finish;
	int x;
	int y;
	int count_thre = 2;
	int count_two = 3;
	int count_one = 4;
	//���������� 4 �������� ��������
	do {
		cout << "choose direction h - horisont v - vertical " << endl;
		cout << "You can change direction anytime." << endl;
		do {
			dir = _getch();
			if (dir == 'h') {
				fill_ground_space(b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_four_part_random_horizont(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'v') {
				fill_ground_space(b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_four_part_random_vertical(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'w') {
				dir_up(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 's') {
				dir_down(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'a') {
				dir_left(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'd') {
				dir_right(b1, x_start, y_start, x_finish, y_finish);
			}
		} while (dir != 13);
		fill_det_around_ship(b1);//������ ����� ������ �������
		copy_ground(b1, temp);//��������� ��������� ������� ������� � �������� ������
		show_ground(b1);
		dir = ' ';
		cout << "count_ship_part = " << count_ship_part(b1) << endl;
	} while (count_ship_part(b1) != 4);
	
	//���������� 3 �������� ��������
	do {
		cout << "choose direction h - horisont v - vertical " << endl;
		cout << "You can change direction anytime." << endl;
		do {
			dir = _getch();
			if (dir == 'h') {
				//��������� ����� ��� ������ ��������� ������� �������
				copy_ground(temp, b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_three_part_random_horizont(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'v') {
				copy_ground(temp, b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_three_part_random_vertical(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'w') {
				dir_up(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 's') {
				dir_down(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'a') {
				dir_left(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'd') {
				dir_right(b1, x_start, y_start, x_finish, y_finish);
			}
		} while (dir != 13);
		count_thre--;
		fill_det_around_ship(b1);//������ ����� ������ �������
		copy_ground(b1, temp);//��������� ��������� ������� ������� � �������� ������
		show_ground(b1);
		cout << "count_ship_part = " << count_ship_part(b1) << endl;
	} while (count_ship_part(b1) <= 10);
	dir = ' ';
	//���������� 2 �������� ��������
	do {
		cout << "choose direction h - horisont v - vertical " << endl;
		cout << "You can change direction anytime." << endl;
		do {
			dir = _getch();
			if (dir == 'h') {
				//��������� ����� ��� ������ ��������� ������� �������
				copy_ground(temp, b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_two_part_random_horizont(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'v') {
				copy_ground(temp, b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_two_part_random_vertical(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'w') {
				dir_up(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 's') {
				dir_down(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'a') {
				dir_left(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'd') {
				dir_right(b1, x_start, y_start, x_finish, y_finish);
			}
		} while (dir != 13);
		count_two--;
		fill_det_around_ship(b1);//������ ����� ������ �������
		copy_ground(b1, temp);//��������� ��������� ������� ������� � �������� ������
		show_ground(b1);
	} while (count_two > 0);
	dir = ' ';
	//���������� 1 �������� ��������
	do {
		cout << "choose direction h - horisont v - vertical " << endl;
		cout << "You can change direction anytime." << endl;
		do {
			dir = _getch();
			if (dir == 'h') {
				//��������� ����� ��� ������ ��������� ������� �������
				copy_ground(temp, b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_one_part_random_vertical(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'v') {
				copy_ground(temp, b1);
				x_start = 0;
				y_start = 0;
				x_finish = 0;
				y_finish = 0;
				tap_ship_one_part_random_vertical(b1, x_start, y_start, x_finish, y_finish);
				show_ground(b1);
			}
			if (dir == 'w') {
				dir_up(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 's') {
				dir_down(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'a') {
				dir_left(b1, x_start, y_start, x_finish, y_finish);
			}
			if (dir == 'd') {
				dir_right(b1, x_start, y_start, x_finish, y_finish);
			}
		} while (dir != 13);
		count_one--;
		fill_det_around_ship(b1);//������ ����� ������ �������
		copy_ground(b1, temp);//��������� ��������� ������� ������� � �������� ������
		show_ground(b1);
	} while (count_one > 0);
	dir = ' ';
}
