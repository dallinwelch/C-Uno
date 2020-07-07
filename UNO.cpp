#include <iostream>
#include <string>
#include<iomanip>
#include"UNODriver.h"
#include<time.h>
#include <vector>



using namespace std;

int main() {
	int choice;
	 UNODriver u;
	
	cout << "Welcome to UNO" << endl;
	cout << "type 1-4 for how many players you would like to play against" << endl;
	cout << "or type zero to quit" << endl;
	u.setChoice();

	while (u.hasWon() == true) {
		u.currentPlayer();
		u.displayCards();
		u.currentCard();
		u.PlayCard();
		u.switchPlayer();
	}
	return 0;
	}
	

