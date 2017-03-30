#include "Game.h"


CGame::CGame(void)
{
	clearBoard();

	winner = ' ';
	playerOne = 'X';
	playerTwo = 'O';
	isDone = false;
	currentPlayer = playerOne;
}


CGame::~CGame(void)
{
}

void CGame::playGame(void){
	while (!isDone){
		int x = 0;
		int y = 0;
		bool goodChoice = true;
		
		printBoard();

		x = chooseCoord(1);
		y = chooseCoord(2);
		goodChoice = isValidChoice(y, x, currentPlayer);
		isDone = checkWin();
		if (!isDone){
			isDone = boardFull();
		}
		if (!isDone){
			endChoice(goodChoice);
		}

		if (isDone){
			if (winner == playerOne){
				printBoard();
				printf("\nPlayer One wins!\n");
			} else if (winner == playerTwo){
				printBoard();
				printf("\nPlayer Two wins!\n");
			} else {
				printBoard();
				printf("\nIt's a tie, nobody wins.\n");
			}
		}
	}
}

void CGame::printBoard(void){
	printf("%s",std::string(25,'\n').c_str());
	int temp = 0;
	printf("  | 1 | 2 | 3 |\n");
	for (int i = 0; i < 3; i++){
		temp = i+1;
		printf("--+---+---+---+\n");
		printf("%i | %c | %c | %c |\n", 
			temp, board[i][0], board[i][1],board[i][2]);
	}
	printf("--+---+---+---+\n");

	if (currentPlayer == playerOne){
		printf("Player 1:\n");
	} else {
		printf("Player 2:\n");
	}
}

void CGame::clearBoard(void){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			board[j][i] = ' ';
		}
	}
}

void CGame::changePlayer(void){
	if (currentPlayer == playerOne){
		currentPlayer = playerTwo;
	} else {
		currentPlayer = playerOne;
	}
}

void CGame::endChoice(bool goodChoice){
	if (goodChoice){
		changePlayer();
	} else {
		printf("\nSpace is taken, choose an open space.\n");
	}
}

int CGame::chooseCoord(int axis){
	int a = 0;
	if (axis == 1){
		printf("Enter the horizontal position: ");
	} else {
		printf("Enter the vertical position: ");
	}

	while(true){
		std::cin >> a;
		if ((a < 1)||(a > 3)){
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		} else {
			return a;
		}
	}
}

bool CGame::isValidChoice(int vert, int hori, char player){
	vert -= 1;
	hori -= 1;

	if (board[vert][hori] == ' '){
		board[vert][hori] = player;
		return true;
	}

	return false;
}

bool CGame::checkWin(void){
	for (int i = 0; i < 3; i++){
		if ((board[i][0] == board[i][1])&&(board[i][1] == board[i][2])&&(board[i][0] != ' ')){
			winner = currentPlayer;
			return true;
		}

		if ((board[0][i] == board[1][i])&&(board[1][i] == board[2][i])&&(board[0][i] != ' ')){
			winner = currentPlayer;
			return true;
		}
	}

	if ((board[0][0] == board[1][1])&&(board[1][1] == board[2][2])&&(board[0][0] != ' ')){
		winner = currentPlayer;
		return true;
	}

	if ((board[2][0] == board[1][1])&&(board[1][1] == board[0][2])&&(board[2][0] != ' ')){
		winner = currentPlayer;
		return true;
	}

	return false;
}

bool CGame::boardFull(void){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[j][i] == ' '){
				return false;
			}
		}
	}

	return true;
}