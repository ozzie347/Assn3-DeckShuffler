//Name:	Nicholas Oshukany 200329674
//		Justin Schieck 200328630
//OS:	Windows 10
//IDE:	Microsoft Visual Studio


#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>


using namespace std;

const int cardsPerDeck = 52;

class card {
public:
	card(string cardFace, string cardSuit);
	string print() const;
	card();

private:
	string face;
	string suit;
};

card::card() {

}

card::card(string cardFace, string cardSuit) {
	face = cardFace;
	suit = cardSuit;
}

string card::print() const {
	return (face + suit);
}

class deckOfCards {
public:
	deckOfCards();
	void shuffle();
	card dealCard();
	void printDeck() const;

private:
	card *deck;
	int currentCard;
};

void deckOfCards::printDeck() const {
	cout << left;
	for (int i = 0; i < cardsPerDeck; i++) {
		cout << setw(5) << deck[i].print();
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
}

deckOfCards::deckOfCards() {
	string faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string suits[] = { "♣", "♦", "♥", "♠" };
	deck = new card[cardsPerDeck];
	currentCard = 0;
	for (int count = 0; count < cardsPerDeck; count++)
		deck[count] = card(faces[count % 13], suits[count / 13]);
}

void deckOfCards::shuffle() {
	currentCard = 0;
	for (int first = 0; first < cardsPerDeck; first++) {
		int second = (rand() + time(0)) % cardsPerDeck;
		card temp = deck[first];
		deck[first] = deck[second];
		deck[second] = temp;
	}
}

card deckOfCards::dealCard() {
	return deck[0];
}

int main() {
	deckOfCards deck;
	card currentCard;
	deck.printDeck();
	deck.shuffle();
	for (int i = 0; i < 52; i++) {
		currentCard = deck.dealCard();
		cout << currentCard.print() << endl;
	}
	system("pause");


	return 0;
}