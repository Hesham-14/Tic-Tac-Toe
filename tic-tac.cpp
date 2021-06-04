#include "pch.h"
#include <iostream>

using namespace std;

char board[3][3] = { ' ', ' ', ' ',
						' ', ' ', ' ',
						' ', ' ', ' ', };
int turn = 1;
char mark='X';

void PrintMatrix()
{
	cout << "\t\t\t\t" << "1 | 2 | 3" << endl;
	cout << "\t\t\t\t" << "4 | 5 | 6" << endl;
	cout << "\t\t\t\t" << "7 | 8 | 9" << endl;
	cout << endl << "\t\t=============================================" << endl << endl;
}

void PrintGame()
{
	cout << endl;
	cout << "\t\t\t\t" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "\t\t\t\t" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "\t\t\t\t" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << endl << "\t\t=============================================" << endl << endl;
}

int Marking(int input)
{
	for (int i = 0, k = 1;i < 3;i++)
		for (int j = 0; j < 3; j++, k++)
		{
			if(k == input)
				if (board[i][j] == ' ')
				{
					board[i][j] = mark;
					return 1;
				}
				else
				{
					cout << "** Used Input **" << endl;
					return 0;
				}
		}
}

int Checking()
{
	if ((board[0][0] == mark && board[0][1] == mark && board[0][2] == mark) ||
		(board[1][0] == mark && board[1][1] == mark && board[1][2] == mark) ||
		(board[2][0] == mark && board[2][1] == mark && board[2][2] == mark))
		return 1;	//Rows Winning

	if ((board[0][0] == mark && board[1][0] == mark && board[2][0] == mark) ||
		(board[0][1] == mark && board[1][1] == mark && board[2][1] == mark) ||
		(board[0][2] == mark && board[1][2] == mark && board[2][2] == mark))
		return 1;	//Columns Winning

	if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
		(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
		return 1;	//Diagonals Winning

	return 0;
}


int main()
{
	int input = 0, validinput = 0, win = 0;
	

	for (int i = 0; i < 9; i++)
	{
		system("cls");
		cout << "\t\t\t Welcome to TIK TAK TOE Game\n";
		PrintGame();
		PrintMatrix();
		if (turn)
		{
			cout << "Its \"X\" Turn." << endl << endl;
			mark = 'X';
		}
		else
		{
			cout << "Its \"O\" Turn." << endl << endl;
			mark = 'O';
		}
		cout << "Please, Enter Input number from the Input Matrix" << endl;
		cin >> input;
		while (input < 0 || input > 9)
		{ 
			cout << "Invalid Input, please enter valid one:";
			cin >> input;
		}
		validinput = Marking(input);
		if (!validinput)
		{
			--i;
			continue;
		}
		win = Checking();
		if (win)
		{
			system("cls");
			PrintGame();
			cout << endl << "\t\t\tWINNER.. WINNER.. CHICKEN DINER!!" << endl;
			if(turn)
				cout << endl << "\t\t\t  ### Player \"X\" - You Won ###" <<endl;
			else
				cout << endl << "\t\t\t  ### Player \"O\" - You Won ###" << endl;
			break;
		}
		if (i == 8)
		{
			system("cls");
			PrintGame();
			cout << endl << "\t\t\t \^/\^/\^/ MATCH DRAW \^/\^/\^/" << endl;
		}
		turn = !turn;
	}
	return 0;
}
