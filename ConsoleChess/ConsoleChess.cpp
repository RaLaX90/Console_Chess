#include <iostream>
#include <vector>
#include <sstream>
//#include <iomanip>
//#include "figure.h"

using namespace std;

vector<char> symbol = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

enum class figures {
	WHITE_PAWN = 1,
	BLACK_PAWN,
	WHITE_ROOK,
	BLACK_ROOK,
	WHITE_KNIGHT,
	BLACK_KNIGHT,
	WHITE_BISHOP,
	BLACK_BISHOP,
	WHITE_QUEEN,
	BLACK_QUEEN,
	WHITE_KING,
	BLACK_KING
};

string whatIsIcons(figures &item) {

	switch ((int)item)
	{
		case 0: {
			return "  ";
		}
		case 1: {
			return "WP";
		}
		case 2: {
			return "BP";
		}
		case 3: {
			return "WR";
		}
		case 4: {
			return "BR";
		}
		case 5: {
			return "WN";
		}
		case 6: {
			return "BN";
		}
		case 7: {
			return "WB";
		}
		case 8: {
			return "BB";
		}
		case 9: {
			return "WQ";
		}
		case 10: {
			return "BQ";
		}
		case 11: {
			return "WK";
		}
		case 12: {
			return "BK";
		}
	}

}

void showBoard(vector<vector<figures>> &chessBoard) {

	cout << "\t\t   White" << endl;
	
	for (int8_t i = 0; i < 10; ++i) {
		if (i == 0 || i == 9) {
			for (int8_t j = 0; j < 10; ++j) {
				if (j == 0 || j == 9) {
					cout << "  ";
					//cout << "\xc9";
				}
				else {
					cout << "  " << symbol[j - 1] << "  ";
				}
			}
		}
		else {
			for (int8_t j = 0; j < 10; ++j) {

				if (j == 0 || j == 9) {
					cout << i << " ";
				}
				else {
					cout << "|" << whatIsIcons(chessBoard[i - 1][j - 1]).c_str() << "|" << " ";
				}

			}
		}
		
		cout << endl;
	}
	cout << "\t\t   Black" << endl;

}

void showInfo() {
	cout << "\nAll application commands are shown below:\nstart - to start the game. Without this, you cannot do anything.\ninfo - show command\nrestart - start the game from the beginning. The previous game will be lost!\nsave - the game will be saved and you can continue to play at any other time.\nload - continue the saved game.\nmove d2 d3 - move the figure. The second value indicates the number of sectors vertically and diagonally where the figure is to be moved, the third value indicates the number of sectors vertically and diagonally where the figure is to be moved.\n\nPlease note: YOU ARE NOT ABLE TO MOVE YOUR OWN FIGURES, AND ALSO MAKE THE WAYS WHICH ARE NOT PROVIDED BY THE TRADITIONAL GAME RULES.IF THE GAME IS NOT STARTED, ONLY DOWNLOAD AND START TEAMS WILL WORK." << endl << endl;
}

bool isDataCorrect(string data) {

	if (isalpha(tolower(data[0])) && isdigit(data[1])) {

		auto tempFirst = find(begin(symbol), end(symbol), data[0]);
		if (tempFirst == end(symbol)) {
			cout << "There is no such first vertical coordinate" << endl;
			return false;
		}
		else {
			if (data[1] < 1 || data[1] > 8) {
				cout << "There is no such first horizontal coordinate" << endl;
				return false;
			}
			else {
				return true;
				/*int8_t indexFirst = distance(begin(symbol), tempFirst);
				cout << "First index  = " << indexFirst;*/
			}
		}

	}
	else {
		cout << "First data is NOT OK" << endl;
		return false;
	}

}

int main()
{
	vector<vector<figures>> chessBoard(8);
	for (size_t i = 0; i < 8; ++i) {

		chessBoard[i].resize(8);
		for (size_t j = 0; j < 8; ++j) {
			if (i == 0 && (j == 0 || j == 7)) {
				chessBoard[i][j] = figures::WHITE_ROOK;
			}
			else if (i == 0 && (j == 1 || j == 6)) {
				chessBoard[i][j] = figures::WHITE_KNIGHT;
			}
			else if (i == 0 && (j == 2 || j == 5)) {
				chessBoard[i][j] = figures::WHITE_BISHOP;
			}
			else if (i == 0 && (j == 3)) {
				chessBoard[i][j] = figures::WHITE_QUEEN;
			}
			else if (i == 0 && (j == 4)) {
				chessBoard[i][j] = figures::WHITE_KING;
			}
			else if (i == 1) {
				chessBoard[i][j] = figures::WHITE_PAWN;
			}

			else if (i == 6) {
				chessBoard[i][j] = figures::BLACK_PAWN;
			}
			else if (i == 7 && (j == 4)) {
				chessBoard[i][j] = figures::BLACK_KING;
			}
			else if (i == 7 && (j == 3)) {
				chessBoard[i][j] = figures::BLACK_QUEEN;
			}
			else if (i == 7 && (j == 2 || j == 5)) {
				chessBoard[i][j] = figures::BLACK_BISHOP;
			}
			else if (i == 7 && (j == 1 || j == 6)) {
				chessBoard[i][j] = figures::BLACK_KNIGHT;
			}
			else if (i == 7 && (j == 0 || j == 7)) {
				chessBoard[i][j] = figures::BLACK_ROOK;
			}
		}

	}

	
	bool start = false;
	bool finish = true;

	bool turnWhite = true;

	string usersData;
	string moveDataFirst;

	showBoard(chessBoard);
	cout << "\nHello my friend. I want to play a game with you. You need to defeat another player who will play with you on the same device. You will play in turn. When you are ready, start." << endl;
	showInfo();
	

	while (true)
	{
		cout << endl;

		if (start == true) {
			turnWhite ? cout << "Now it's WHITE's turn" << endl : cout << "Now it's BLACK's turn" << endl;
		}

		cout <<	"Your command is: ";

		cin >> usersData;
		//cout << usersData;

		if (usersData == "start" && start == false) {
			start = true;
			cout << "\n\nWin or lose - the choice is yours. The game started. Good luck." << endl << endl;
		}
		else if (usersData == "restart") {

		}
		else if (usersData == "info") {
			showInfo();
		}
		else if (usersData == "save") {

		}
		else if (usersData == "load") {

		}
		else if (usersData == "move") {

			if (start == true) {

				cin >> usersData;

				if (isalpha(tolower(usersData[0])) && isdigit(usersData[1])) {
					cout << "First number is OK" << endl;

					auto tempFirst = find(begin(symbol), end(symbol), usersData[0]);

					if (tempFirst == end(symbol)) {
						cout << "There is no such first vertical coordinate" << endl;
					}
					else {

						if (usersData[1] < 1 && usersData[1] > 8) {
							cout << "There is no such first horizontal coordinate" << endl;
						}
						else {
							int8_t indexFirst = distance(begin(symbol), tempFirst);
							cout << "First index  = " << indexFirst;

							moveDataFirst = usersData;
							cin >> usersData;/////////////////////////////////////////////////////////////////

							if (isalpha(tolower(usersData[0])) && isdigit(usersData[1])) {
								cout << "Second number is OK" << endl;

								auto tempSecond = find(begin(symbol), end(symbol), usersData[0]);
								if (tempSecond == end(symbol)) {
									cout << "There is no such second vertical coordinate" << endl;
								}
								else {

									if (usersData[1] < 1 && usersData[1] > 8) {
										cout << "There is no such first horizontal coordinate" << endl;
									}
									else {
										int8_t indexSecond = distance(begin(symbol), tempSecond);
										cout << "Second index  = " << indexSecond;
									}
									
								}

							}
							else {
								cout << "Unknown command." << endl;
							}
						}
						
					}
				}
				else {
					cout << "Unknown command." << endl;
				}
			}
			else {
				cout << "Game is not start. Use command \"start\"" << endl;
			}
		}
		else {
			cout << "Unknown command." << endl;
		}

	}

	

	return 0;
}

