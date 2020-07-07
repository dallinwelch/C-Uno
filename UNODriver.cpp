#include "UNODriver.h"
#include <string>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
UNODriver::UNODriver()
{
	for (int i = 0; i < 8; i++) {
		deckNum.push_back("1");
		deckNum.push_back("2");
		deckNum.push_back("3");
		deckNum.push_back("4");
		deckNum.push_back("5");
		deckNum.push_back("6");
		deckNum.push_back("7");
		deckNum.push_back("8");
		deckNum.push_back("9");
		deckNum.push_back("reverse");
		deckNum.push_back("draw 2");


	}
	//cout << "num"<<deckNum.size() << endl;
	for (int i = 0; i < 22; i++) {
		deckColor.push_back("red");
		deckColor.push_back("yellow");
		deckColor.push_back("blue");
		deckColor.push_back("green");
	}
//	cout << "color" << deckColor.size() << endl;
	for (int i = 0; i < deckNum.size(); i++) {
		 deck.push_back({ deckColor[i],deckNum[i] });
	//	 cout << "card "<< i<<") " << deck[i].num<<deck[i].color<<endl;
	}
	
	srand(time(NULL));
	cPlayer = 1;
	for (int i = 0; i < 5; i++){
		player1.push_back(drawCard());

	}
	for (int i = 0; i < 5; i++) {
		player2.push_back(drawCard());
	}
	for (int i = 0; i < 5; i++) {
		player3.push_back(drawCard());
	}
	for (int i = 0; i < 5; i++) {
		player4.push_back(drawCard());
	}

}



void UNODriver::setChoice()
{
	cin >> playerChoice;
}

void UNODriver::switchPlayer()
{


		if (Player1 == 1 && playerChoice > 2 && cPlayer == 1) {

			Player2 = 1;
			Player1 = 2;
			cPlayer = 2;
		}
		else if (Player2 == 1 && playerChoice > 2 && cPlayer == 2) {
			Player3 = 1;
			Player2 = 3;
			cPlayer = 3;
		}
		else if (Player3 == 1 && playerChoice == 4 && cPlayer == 3) {
			Player4 = 1;

			Player3 = 4;
			cPlayer = 4;
		}
		else if (Player4 == 1 && playerChoice == 4 && cPlayer == 4) {
			Player1 = 1;
			Player4 = 4;
			cPlayer = 1;
		}
	

}

void UNODriver::PlayCard()
{
	cin >> ichoice;
	switch (cPlayer) {
	case 1:
			if (topCard.color == player1[ichoice].color || topCard.num == player1[ichoice].num) {
				topCard = player1[ichoice];
					player1.erase(player1.begin() + ichoice);
				
			}
			else {
				cout << "Wrond card" << endl;
				player1.push_back(drawCard());
				break;
			}
		
		break;
	case 2:
		if (topCard.color == player2[ichoice].color || topCard.num == player2[ichoice].num) {
			topCard = player2[ichoice];
			player2.erase(player2.begin() + ichoice);
		}
		else {
			cout << "Wrond card" << endl;
			player2.push_back(drawCard());
			break;
		}
		break;
	case 3:
		if (topCard.color == player3[ichoice].color || topCard.num == player3[ichoice].num) {
			topCard = player3[ichoice];
			player3.erase(player3.begin() + ichoice);
		}
		else {
			cout << "Wrond card" << endl;
			player3.push_back(drawCard());
			break;
		}

		break;
	case 4:
		if (topCard.color == player4[ichoice].color || topCard.num == player4[ichoice].num) {
			topCard = player4[ichoice];
			player4.erase(player4.begin() + ichoice);

		}
		else {
			cout << "Wrond card" << endl;
			player4.push_back(drawCard());
			break;
		}

		break;
	}

}

bool UNODriver::hasWon()
{
	if (player1.size() == 0) {
		return false;
	}else 	if (player2.size() == 0) {
		return false;
	}
	else if (player3.size() == 0) {
		return false;
	}
	else if (player4.size() == 0) {
		return false;
	}
	else {
		return true;
	}
}

void UNODriver::currentCard()
{

	if (check == true) {
		topCard = drawCard();
		check = false;
	}
	
	cout <<"The Current Card is: "<< topCard.color<< " "<< topCard.num<< endl;
	cout << "deck: " << deck.size() << endl;
}

void UNODriver::currentPlayer()
{
	if (cPlayer == 1) {
		cout << "Player 1's turn" << endl;
	}else 	if (cPlayer == 2) {
		cout << "Player 2's turn" << endl;
	}else if (cPlayer == 3) {
		cout << "Player 3's turn" << endl;
	}
	else 	if (cPlayer == 4) {
		cout << "Player 4's turn" << endl;
	}

}

void UNODriver::displayCards()
{

	if (cPlayer == 1) {
			for (int i = 0; i < player1.size(); i++) {
				cout << "("<<i <<") "<< player1[i].color<<" " << player1[i].num << endl;
			}
	}else if (cPlayer == 2) {
		for (int i = 0; i < player2.size(); i++) {
			cout << "(" << i << ") " << player2[i].color << " " <<player2[i].num << endl;
		}
	}else if (cPlayer == 3) {
		for (int i = 0; i < player3.size(); i++) {
			cout << "(" << i << ") " << player3[i].color << " " <<player3[i].num << endl;
		}
	}else if (cPlayer == 4) {
		for (int i = 0; i < player4.size(); i++) {
			cout << "(" << i << ") " << player4[i].color << " " <<player4[i].num << endl;
		}
	}
}



CARDS UNODriver::drawCard()
{
	int i;

	i = rand() % deck.size();
	if (i == deck.size()) {
		(i - 1);
	}
	
	deck.erase(deck.begin() + i);
	return deck[i];


}