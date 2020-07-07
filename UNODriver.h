#pragma once
#include <string>
#include <vector>
#include<iostream>

using namespace std;

struct CARDS {
	string color;
	string num;

};
class UNODriver
{

public:

	UNODriver();
	CARDS drawCard();
	void setChoice();
	void switchPlayer();
	void PlayCard();
	bool hasWon();
	void currentCard();
	void currentPlayer();
	void displayCards();


private:
	vector <CARDS>deck;
	vector <string> deckColor;
	vector <string> deckNum;
	int ichoice;
	CARDS c;
	int playerChoice;
	int cPlayer;
	string playedCard;
	CARDS topCard;
	string choice;
	vector <CARDS>player1;
	vector <CARDS>player2;
	vector <CARDS>player3;
	vector <CARDS>player4;
	int Player1 = 1, Player2 = 2, Player3 = 3, Player4 = 4;
	bool check = true;

};

