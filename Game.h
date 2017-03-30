#pragma once
#include <iostream>

class CGame
{
public:
	CGame(void);
	~CGame(void);

	void playGame(void);

private:
	char board[3][3];
	char playerOne;
	char playerTwo;
	char currentPlayer;
	char winner;
	bool isDone;

	void printBoard(void);
	void clearBoard(void);
	void changePlayer(void);
	void endChoice(bool goodChoice);

	int chooseCoord(int axis);
	bool isValidChoice(int vert, int horizontal, char player);
	bool checkWin(void);
	bool boardFull(void);
};

