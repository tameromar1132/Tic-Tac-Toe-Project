#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

int Random(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int ReadNumberInRange(int From, int To)
{
	int Number = 0;
	do
	{

		cout << "\nEnter Number Between" << From << " And " << To << " To Make Move : ";
		cin >> Number;

		//while (cin.fail())
		//{
			//cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//cout << "Invalid Number, Enter a Valid one : ";
			//cin >> Number;

		//}

	} while (Number <From || Number >To);
	return Number;
}

void ReadBoard(char arr[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			(j != 2) ? (cout << arr[i][j] << "  |  ") : (cout << arr[i][j]);
		}
		(i != 2) ? (cout << "\n---------------\n") : (cout << "");

	}



}

void MakeMoveForPlayer(char arr[3][3], int Number)
{

	int move = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (move == Number)
			{
				arr[i][j] = 'X';
			}
			move++;
		}

	}


}

void MakeMoveForComputer(char arr[3][3], int Number)
{

	int move = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (move == Number)
			{
				arr[i][j] = 'O';
			}
			move++;
		}

	}


}

bool IsPlayerWin(char arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == 'X')
			return 1;
	}
	for (int j = 0; j < 3; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] == 'X')
			return 1;
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == 'X')
		return 1;

	else if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] == 'X')
		return 1;

	else
		return 0;

}

bool IsComputerWin(char arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == 'O')
			return 1;
	}
	for (int j = 0; j < 3; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] == 'O')
			return 1;
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == 'O')
		return 1;

	else if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] == 'O')
		return 1;

	else
		return 0;

}

bool BoardFull(char arr[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}


	}

	return 1;

}

bool IsValidMove(char arr[3][3], int Number)
{
	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((count == Number))
			{
				return (arr[i][j] != 'X' && arr[i][j] != 'O');
			}
			count++;
		}





	}
	return false;
}

void Color(char arr[3][3])
{
	if (IsComputerWin(arr))
		system("color 4F");
	else if (IsPlayerWin(arr))
		system("color 2F");

	else
		system("color 6F");

}

string Tape(int NumberOfTap)
{
	for (int i = 0; i < NumberOfTap; i++)
	{
		cout << "\t";
	}
	return "";
}

void ShowGameOver(char arr[3][3])
{
	
	cout << "\n";
	cout << Tape(2) << "____________________________________________________________\n";
	cout << Tape(2) << "                      +GameOver+                            \n";
	cout << Tape(2) << "____________________________________________________________\n";


	if (IsPlayerWin(arr))
		cout << Tape(2) << setw(32) << "Player Win" << setw(11) << endl;
	else if (IsComputerWin(arr))
		cout << Tape(2) << setw(34) << "Computer Win" << setw(11) << endl;
	else
		cout << Tape(2) << setw(38) << "Draw" << setw(11) << endl;

}

void PlayRound(char arr[3][3])
{
	int count = 1;
	int Move;
	do
	{
		system("cls");
		cout << endl;
		ReadBoard(arr);
		cout << "\n\nRound [" << count << "]\n";
		Move = ReadNumberInRange(1, 9);


		while (!IsValidMove(arr, Move))
		{

			if (BoardFull(arr) == 1)
			{
				ReadBoard(arr);
				ShowGameOver(arr);
				return;
			}

			cout << "\nThis Position Taken , Try Again :\n";
			Move = ReadNumberInRange(1, 9);
		}
		MakeMoveForPlayer(arr, Move);
		if (IsPlayerWin(arr) == 1)
		{
			ReadBoard(arr);
			ShowGameOver(arr);
			break;
		}


		int ComputerMove = Random(1, 9);

		while (IsValidMove(arr, ComputerMove) == false)
		{

			ComputerMove = Random(1, 9);

			if (BoardFull(arr) == 1)
			{

				ReadBoard(arr);
				ShowGameOver(arr);
				return;

			}
		}
		MakeMoveForComputer(arr, ComputerMove);
		if (IsComputerWin(arr) == 1)
		{
			ReadBoard(arr);
			ShowGameOver(arr);
			break;

		}


		count++;
	} while ((IsComputerWin(arr) == false) && (IsPlayerWin(arr) == false) && BoardFull(arr) == false);

}

void Reset(char arr[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			arr[i][j] = ' ';
		}
	}
	system("color 0F");
	system("cls");

}

void PlayGame(char arr[3][3])
{
	char PlayAgain;
	do {
		Reset(arr);
		cout << "Welcome To Tic Tie Toe Game (XO)\n";
		PlayRound(arr);
		Color(arr);
		cout << "Do You Wont Play Again (Y/N)?\n";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');





}

int main()
{
	srand((unsigned)time(NULL));
	char arr[3][3] = { { ' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	PlayGame(arr);

	return 0;

}