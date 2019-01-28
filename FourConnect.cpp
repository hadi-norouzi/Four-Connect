#include <iostream>
#include <windows.h>
using namespace std;

char table[17][33];
char a = 219;
char elementPlayerOne = 177;
char elementPlayerTwo = 178;
int colorOfPlayerOne, colorOfPlayerTwo;
int scorePlayerOne, scorePlayerTwo;

void firstPage();
void createTable();
void print();
int fill();
int horizontalCheck();
int verticalCheck();
int diagonalCheck();
int choosePlayerColor();


enum color{

	green = 34,
	blue = 17,
	red = 68,
	yellow = 102,
	white = 7
};

int main(){

	int i = 1;
	char answer;

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	firstPage();
	Sleep(2000);
	system("cls");
	choosePlayerColor();

	while(1){

	char answer;

	if(i == 2){

		cout << "Change colors? (y/n) ";
		cin >> answer;
		if(answer == 'y'){

			system("cls");
			choosePlayerColor();
		}
	}

	system("cls");

	createTable();

		
		if(fill() == 1){
		
			cout << "\nplayer ";
			SetConsoleTextAttribute(hConsole, 0 | colorOfPlayerOne);
			cout << elementPlayerOne << elementPlayerOne << elementPlayerOne;
			SetConsoleTextAttribute(hConsole, 0 | white);
			cout << " Winner";
			scorePlayerOne++;
		}
		
		if(fill() == 2){

			cout << "\nplayer ";
			SetConsoleTextAttribute(hConsole, 0 | colorOfPlayerTwo);
			cout << elementPlayerTwo << elementPlayerTwo << elementPlayerTwo ;
			SetConsoleTextAttribute(hConsole, 0 | white);
			cout << " Winner";
			scorePlayerTwo++;
			
			}
	
	cout << "\n\n\nPlay Again ? (y/n) ";
	cin >> answer;

	if(answer == 'y'){

		system("cls");
		i++;
		continue;
	}
	else{
		system("cls");
		cout << "Player ";
		SetConsoleTextAttribute(hConsole, 0 | colorOfPlayerOne);
		cout << elementPlayerOne << elementPlayerOne << elementPlayerOne << " ";
		SetConsoleTextAttribute(hConsole, 0 | white);
		cout << scorePlayerOne << endl;

		cout << "Player ";
		SetConsoleTextAttribute(hConsole, 0 | colorOfPlayerTwo);
		cout << elementPlayerTwo << elementPlayerTwo << elementPlayerTwo << " ";
		SetConsoleTextAttribute(hConsole, 0 | white);
		cout << scorePlayerTwo << endl;
		Sleep(3000);
		return 0;
	}

	}
	return 0;
}
void firstPage(){

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for(int i = 1; i < 16; i++){

		for(int j = 1; j < 16; j++){


			SetConsoleTextAttribute(hConsole,0 | j);
			cout << "*FOUR CONNECT* ";
			Sleep(15);
		}
	}
}

void createTable(){

	for(int i = 0; i < 17; i++){

		for(int j = 0; j < 33; j++)

			table[i][j] = 0;
	}

	for(int i = 0; i < 17; i+=2){

		for(int j = 0; j < 33; j++)

			table[i][j] = a;
	}

	for(int i = 0; i < 33; i+=4){

		for(int j = 0; j < 17; j++)

			table[j][i] = a;
	}
}

int choosePlayerColor(){

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "Player 1 Enter your color : \n\n";
	cout << "1.";
	SetConsoleTextAttribute(hConsole, 0 | blue);
	cout << "Blue\n";
	SetConsoleTextAttribute(hConsole, 0 | white);
	cout << "2.";
	SetConsoleTextAttribute(hConsole, 0 | green);
	cout << "Green\n";
	SetConsoleTextAttribute(hConsole, 0 | white);
	cout << "3.";
	SetConsoleTextAttribute(hConsole, 0 | red);
	cout << "Red\n";
	SetConsoleTextAttribute(hConsole, 0 | white);
	cout << "4.";
	SetConsoleTextAttribute(hConsole, 0 | yellow);
	cout << "Yellow\n";
	SetConsoleTextAttribute(hConsole, 0 | white);

	cout << "\nEnter a Number : ";
	cin >> colorOfPlayerOne;

	while( !(colorOfPlayerOne) >= 4 && colorOfPlayerOne != 0){

		cout << "Try Again! \n Enter a Number : ";
		cin >> colorOfPlayerOne;
	}

	if(colorOfPlayerOne == 1)
		colorOfPlayerOne = blue;

	else if(colorOfPlayerOne == 2)
		colorOfPlayerOne = green;

	else if(colorOfPlayerOne == 3)
		colorOfPlayerOne = red;

	else if(colorOfPlayerOne == 4)
		colorOfPlayerOne = yellow;

	else if(colorOfPlayerOne == 0)
		exit(0);


	system("cls");

	cout << "Player 2 Enter your color : \n\n";
	cout << "1.";
	SetConsoleTextAttribute(hConsole, 0 | blue);
	cout << "Blue\n";
	SetConsoleTextAttribute(hConsole, 0 | white);
	cout << "2.";
	SetConsoleTextAttribute(hConsole, 0 | green);
	cout << "Green\n";
	SetConsoleTextAttribute(hConsole, 0 | white);
	cout << "3.";
	SetConsoleTextAttribute(hConsole, 0 | red);
	cout << "Red\n";
	SetConsoleTextAttribute(hConsole, 0 | white);
	cout << "4.";
	SetConsoleTextAttribute(hConsole, 0 | yellow);
	cout << "Yellow\n";
	SetConsoleTextAttribute(hConsole, 0 | white);

	cout << "\nEnter a Number : ";
	cin >> colorOfPlayerTwo;

	if(colorOfPlayerTwo == 1)
		colorOfPlayerTwo = blue;

	else if(colorOfPlayerTwo == 2)
		colorOfPlayerTwo = green;

	else if(colorOfPlayerTwo == 3)
		colorOfPlayerTwo = red;

	else if(colorOfPlayerTwo == 4)
		colorOfPlayerTwo = yellow;

	else if(colorOfPlayerTwo == 0)
		exit(0);

	system("cls");
}

int horizontalCheck(){

	for(int i = 1; i < 17; i+=2){

		for(int j = 2; j < 33; j+=4){

			if(table[i][j] == elementPlayerOne && table[i][j + 4] == elementPlayerOne && table[i][j + 8] == elementPlayerOne && table[i][j + 12] == elementPlayerOne){

				return 1;
			}
		}
	}
	for(int i = 1; i < 17; i+=2){

		for(int j = 2; j < 33; j+=4){

			if(table[i][j] == elementPlayerTwo && table[i][j + 4] == elementPlayerTwo && table[i][j + 8] == elementPlayerTwo && table[i][j + 12] == elementPlayerTwo){

				return 2;
			}
		}
	}
}

int verticalCheck(){

	for(int j = 2; j < 33; j+=4){

		for(int i = 1; i < 17; i+=2){

			if(table[i][j] == elementPlayerOne && table[i + 2][j] == elementPlayerOne && table[i + 4][j] == elementPlayerOne && table[i + 6][j] == elementPlayerOne){

				return 1;
			}
		}
	}
	for(int j = 2; j < 33; j+=4){

		for(int i = 1; i < 17; i+=2){

			if(table[i][j] == elementPlayerTwo && table[i + 2][j] == elementPlayerTwo && table[i + 4][j] == elementPlayerTwo && table[i + 6][j] == elementPlayerTwo){

				return 2;
			}
		}
	}
}

int diagonalCheck(){

	for(int i = 7; i <= 15; i+=2){

		for(int j = 1; j <= 17; j+=4){

		    if (table[i][j] == elementPlayerOne && table[i - 2][j + 4] == elementPlayerOne && table[i - 4][j + 8] == elementPlayerOne && table[i - 6][j + 12] == elementPlayerOne) {
		        return 1;
		    }
		    if (table[i][j] == elementPlayerTwo && table[i - 2][j + 4] == elementPlayerTwo && table[i - 4][j + 8] == elementPlayerTwo && table[i - 6][j + 12] == elementPlayerTwo) {
		        return 2;
		    }
		}
	}
	for(int i = 7; i <= 15; i+=2){

		for(int j = 29; j >= 13; j-=4){

		    if (table[i][j] == elementPlayerOne && table[i - 2][j - 4] == elementPlayerOne && table[i - 4][j - 8] == elementPlayerOne && table[i - 6][j - 12] == elementPlayerOne) {
		        return 1;
		    }
		    if (table[i][j] == elementPlayerTwo && table[i - 2][j - 4] == elementPlayerTwo && table[i - 4][j - 8] == elementPlayerTwo && table[i - 6][j - 12] == elementPlayerTwo) {
		        return 2;
		    }
		}
	}
}
int fill(){

	int column,counter = 0;
	char answer;
	
	if(horizontalCheck() == 1 || verticalCheck() == 1 || diagonalCheck() == 1){

			return 1;
	}
	else if(horizontalCheck() == 2 || verticalCheck() == 2 || diagonalCheck() == 2){

			return 2;
	}

	print();

	while(1){
		

		cout << "\nEnter a column  : "; //Enter a Number of Columns
		cin >> column;

	while( !(column < 9) || !(column >= 0)){ //condition for column variable

		cout << "\nTry Again! \n Enter a column  : ";
	    cin >> column;

	}

	if(column == 0){

		cout << "ARE YOU SURE ? (y/n) ";
		cin >> answer;

		if(answer == 'y')
			exit(0);
	}
	
	for(int i = 15 ; i > 0; i-=2){
		
		if( table[i][4 * column - 3] == 0){

			if(counter % 2 == 0){
	
				table[15][4 * column - 3] = elementPlayerOne;
				table[15][4 * column - 2] = elementPlayerOne;
				table[15][4 * column - 1] = elementPlayerOne;
				break;
			}
			else{
	
				table[15][4 * column - 3] = elementPlayerTwo;
				table[15][4 * column - 2] = elementPlayerTwo;
				table[15][4 * column - 1] = elementPlayerTwo;
				break;
			}
		}
	}

	counter++;
	system("cls");
	print();
	
	if(horizontalCheck() == 1 || verticalCheck() == 1 || diagonalCheck() == 1){

			return 1;
	}
	else if(horizontalCheck() == 2 || verticalCheck() == 2 || diagonalCheck() == 2){

			return 2;
	}

	}
}

void print(){

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "Player One : " << scorePlayerOne << endl;
	cout << "Player Two : " << scorePlayerTwo << endl;

	for(int i = 0; i < 17; i++){

		for(int j = 0; j < 33; j++){

			if(table[i][j] == elementPlayerOne){

				SetConsoleTextAttribute(hConsole, 0 | colorOfPlayerOne);
				cout << table[i][j];
				SetConsoleTextAttribute(hConsole, 0 | white);
				continue;
			}
			if(table[i][j] == elementPlayerTwo){

				SetConsoleTextAttribute(hConsole, 0 | colorOfPlayerTwo);
				cout << table[i][j];
				SetConsoleTextAttribute(hConsole, 0 | white);
				continue;
			}
			if(table[i][j] == a){

				cout << table[i][j];
				continue;
			}
			if(table[i][j] == 0){

				cout << table[i][j];
				continue;
			}
		}
		cout << endl;
	}
	cout << "  1   2   3   4   5   6   7   8" << endl;
}
