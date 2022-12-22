#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#define widght 11

//
//char plus = '+';
char space = ' ';
char numbers[10] = { '1', '2', '3', '4','5','6','7','8','9','10' };
char letters[10] = { 'a', 'b', 'c', 'd','e','f','j','h','i','j' };
char symbols[2] = { '*', '.' };
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
		cout << "0 - exit" << endl;
		cout << ">>>: ";
		cin >> menu;
		switch (menu) {
		case 1: cout << "PvP" << endl; break;
		case 2: cout << "PvE" << endl; break;
		case 3: fill_ground_random(battle_ground_first_player_ship); break;
		}
	} while (menu != 0);

	return 0;
}

void fill_ground_space(char b1[][widght]) {

	b1[0][0] = '+';

	for (int i = 0; i < 1; i++) {
		for (int j = 1; j < widght; j++) {
			b1[i][j] = numbers[j-1];
		}
	}

	for (int i = 1; i < widght; i++) {
		for (int j = 0; j < 1; j++) {
			b1[i][j] = letters[i-1];
		}
	}

	for (int i = 1; i < widght; i++) {
		for (int j = 1; j < widght; j++) {
			b1[i][j] = space;
		}
	}
}

void show_ground(char b1[][widght]) {
	for (int i = 0; i < widght; i++) {
		for (int j = 0; j < widght; j++) {
			cout << b1[i][j] << " ";
		}cout << endl;
	}
	system("pause");
}

void fill_ground_random(char b1[][widght]) {
	//������� ����������
		//������� ��������� ������ ���� ����� ���� �����
		//�������� �������� ����� ������.���� � ��� ����� ���� "�����" ��� "�����" ��� "�����" ��� "���������" ����� �� ����� ���� �������, � �� �������� ������ ���� �� ������� ������
		//�������� �������� �����������.
		//�������� ����� �������, ������� ���� ���������
		//��������� ���� ����� ������� �� ����� ������ �� ����� �� ���������� "�����" ��� "�����" ��� "�����" ��� "���������", �� ������� ����� �������
		// ���� ����� j - const
		// ���� ����� i - const
	//---------------------------------------------------------------------------------------------------------------------------------------------------

	//������� ���-�� ��������
	int ship_count = 10;
	//���������� ��������� ����� �������
	//int x_rand_for_start_ship = rand() % 10;
	//int y_rand_for_start_ship = rand() % 10;
	bool flag = 0;
	//����������� ����������(1 = ����� ��� 0 = �����)
	//int dir = rand() % 1;


	//system("pause");

	do 
	{
		//���������� ��������� ����� �������
		int x_rand_for_start_ship = rand() % 10;
		int y_rand_for_start_ship = rand() % 10;
		//����������� ����������(1 = ����� ��� 0 = �����)
		int dir = rand() % 1;
		cout << "x = " << x_rand_for_start_ship << "; y = " << y_rand_for_start_ship << "; dir = " << dir << endl;
		if (b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[0]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[1]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[2]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[3]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[4]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[5]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[6]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[7]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[8]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != numbers[9]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[0]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[1]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[2]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[3]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[4]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[5]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[6]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[7]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[8]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != letters[9]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[0]
			&& b1[x_rand_for_start_ship][y_rand_for_start_ship] != symbols[1]
		)
		{
			//--y_rand_for_start_ship; cout << "new_y = " << y_rand_for_start_ship << endl;
			if (b1[x_rand_for_start_ship][y_rand_for_start_ship-1] != numbers[0]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[1]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[2]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[3]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[4]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[5]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[6]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[7]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[8]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != numbers[9]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[0]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[1]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[2]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[3]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[4]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[5]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[6]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[7]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[8]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != letters[9]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[0]
				&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] != symbols[1]
				){
				//y_rand_for_start_ship--; cout << "new_y = " << y_rand_for_start_ship << endl;
				if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[0]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[1]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[2]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[3]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[4]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[5]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[6]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[7]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[8]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != numbers[9]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[0]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[1]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[2]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[3]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[4]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[5]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[6]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[7]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[8]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != letters[9]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[0]
					&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] != symbols[1]
					) {
					//y_rand_for_start_ship--; cout << "new_y = " << y_rand_for_start_ship << endl;
					if (b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[0]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[1]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[2]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[3]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[4]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[5]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[6]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[7]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[8]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != numbers[9]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[0]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[1]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[2]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[3]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[4]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[5]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[6]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[7]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[8]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != letters[9]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[0]
						&& b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] != symbols[1]
						) {
							//���������� �������
							b1[x_rand_for_start_ship][y_rand_for_start_ship] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 1] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 2] = symbols[0];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 3] = symbols[0];
							//���������� ������� ������ �������
								//��������� ������� ����
							b1[x_rand_for_start_ship+1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship+1][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship+1][y_rand_for_start_ship - 2] = symbols[1];
							b1[x_rand_for_start_ship+1][y_rand_for_start_ship - 3] = symbols[1];
								//��������� ������� ����
							b1[x_rand_for_start_ship-1][y_rand_for_start_ship] = symbols[1];
							b1[x_rand_for_start_ship-1][y_rand_for_start_ship - 1] = symbols[1];
							b1[x_rand_for_start_ship-1][y_rand_for_start_ship - 2] = symbols[1];
							b1[x_rand_for_start_ship-1][y_rand_for_start_ship - 3] = symbols[1];
								//��������� ������� �����
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship - 4] = symbols[1];
							b1[x_rand_for_start_ship][y_rand_for_start_ship - 4] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship - 4] = symbols[1];
								//��������� ������� ������
							b1[x_rand_for_start_ship + 1][y_rand_for_start_ship + 1] = symbols[1];
							b1[x_rand_for_start_ship][y_rand_for_start_ship + 1] = symbols[1];
							b1[x_rand_for_start_ship - 1][y_rand_for_start_ship + 1] = symbols[1];
							flag = true;
							ship_count--;
						}
					}
				}
		}
	} while (flag != true);
	flag = false;
	//cout << "flag = " << flag << endl;
	show_ground(b1);
}