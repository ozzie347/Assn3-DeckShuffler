//Name:	Nicholas Oshukany 200329674
//		Justin Schieck 200328630
//OS:	Windows 10
//IDE:	Microsoft Visual Studio

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib> 

using namespace std;

enum suits { clubs = 1, diamonds = 2, hearts = 3, spades = 4 };

const int Jack = 11;
const int Queen = 12;
const int King = 13;
const int Ace = 14;
const string clubsSymbol = "♣";
const string diamondsSymbol = "♦";
const string heartsSymbol = "♥";
const string spadesSymbol = "♠";
int random(int i) { return std::rand() % i; }
int value;
suits suit;
int menuSelection;

int main()
{
	menu::menuOptions;
	switch (menuSelection) {
	case 1:
		deck::buildDeck;
	case 2:
		
	case 3:

	case 4:
		return 0;
	};

	system("pause");

    return 0;
}

suits getSuit(int cardSuit) {
	switch (cardSuit) {
	case clubs:
		return clubs;
	case diamonds:
		return diamonds;
	case hearts:
		return hearts;
	case spades:
		return spades;
	}
}

class card {
public:
	card();
	card(int cardValue, int cardSuit) {
		suit = getSuit(cardSuit);
		value = cardValue;
	}
	void display() {
		cout << getDisplay() << endl;
	}
	string getDisplay() {
		string fullCard;
		string cardValue;
		string cardSuit;

		if (value > 1 && value < 11)
		{
			cardValue = to_string(value);
		}
		else if (value == 11) {
			cardValue = "J";
		}
		else if (value == 12) {
			cardValue = "Q";
		}
		else if (value == 13) {
			cardValue = "K";
		}
		else if (value == 14) {
			cardValue = "A";
		}

		if (cardSuit == "clubs") {
			cardSuit = clubsSymbol;
		}
		else if (cardSuit == "diamonds") {
			cardSuit = diamondsSymbol;
		}
		else if (cardSuit == "hearts") {
			cardSuit = heartsSymbol;
		}
		else if (cardSuit == "spades") {
			cardSuit = spadesSymbol;
		}

		fullCard = cardValue + cardSuit;
		return fullCard;
	}

private:
	int value;
	suits suit;
};

class deck {
private:
	vector<card> cards;

public:
	//build the deck
	void buildDeck() {
		int currentCard = 0;
		for (int currentSuit = 1; currentSuit < 5; currentSuit++) {
			for (int currentValue = 2; currentValue < 15; currentValue++) {
				card temp = card(currentCard, currentSuit);
				cards.push_back(temp);
			}
		}
	}

	string display() {
		string output = "{";
		for (int i = 0; i < cards.size(); i++) {
			output.append(cards.at(i).getDisplay());
			if (i != cards.size() - 1) {
				output.append(",");
			}
		}
		output.append("}");
		return output;
	}

	void shuffle() {
		srand(unsigned(std::time(0)));
		vector<int> vectorRandomizer;

		for (int i = 1; i < getSize(); ++i) vectorRandomizer.push_back(i);

		random_shuffle(vectorRandomizer.begin(), vectorRandomizer.end(), random);
	}

	int getSize() {
		return (int)cards.size();
	}

	void displayDeck(vector<card>cards) {
		for (int i = 0; i < 52; i++) {
			if (i % 13 == 0 && i != 0) {
				cout << endl;
			}
			cout << " ";
			cards[i].display();
		}
		cout << endl;
	}
};

class menu {
private:
	int choice;
public:
	void menuOptions() {
		cout << "Please choose an option... \n\n"
			<< "1. Create a deck \n"
			<< "2. Shuffle the deck \n"
			<< "3. Cut the deck to a random card \n"
			<< "4. Exit" << endl;
		
		cin >> choice;
		if (choice >= 1 && choice <= 4) {
			menuSelection = choice;
		}
		else
		{
			cout << "Please enter a valid selection... \n\n"
				<< "1. Create a deck \n"
				<< "2. Shuffle the deck \n"
				<< "3. Cut the deck to a random card \n"
				<< "4. Exit" << endl;
			cin.clear();
			cin.ignore();
		}
	};
};