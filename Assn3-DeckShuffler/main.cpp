//Name:	Nicholas Oshukany 200329674
//		Justin Schieck 200328630
//OS:	Windows 10
//IDE:	Microsoft Visual Studio

#include "deckOfCards.h"
#include "stdafx.h"
#include "card.h"

using namespace std;

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