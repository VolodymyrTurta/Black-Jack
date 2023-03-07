#include <iostream>
#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

class Card
{
public:
    enum CardSuit
    {
	    SUIT_CLUB,
	    SUIT_DIAMOND,
	    SUIT_HEART,
	    SUIT_SPADE,
	    MAX_SUITS
    };

    enum CardRank
    {
	    RANK_2,
	    RANK_3,
	    RANK_4,
	    RANK_5,
	    RANK_6,
	    RANK_7,
	    RANK_8,
	    RANK_9,
	    RANK_10,
	    RANK_JACK,
	    RANK_QUEEN,
	    RANK_KING,
	    RANK_ACE,
	    MAX_RANKS
    };
private:
    CardRank m_rank;
    CardSuit m_suit;

public:
    Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS)
        : m_rank(rank), m_suit(suit)
    {

    }

    void printCard() const
    {
	    switch (m_rank)
	    {
		    case RANK_2:		std::cout << '2'; break;
		    case RANK_3:		std::cout << '3'; break;
		    case RANK_4:		std::cout << '4'; break;
		    case RANK_5:		std::cout << '5'; break;
		    case RANK_6:		std::cout << '6'; break;
		    case RANK_7:		std::cout << '7'; break;
		    case RANK_8:		std::cout << '8'; break;
		    case RANK_9:		std::cout << '9'; break;
		    case RANK_10:		std::cout << 'T'; break;
		    case RANK_JACK:		std::cout << 'J'; break;
		    case RANK_QUEEN:	std::cout << 'Q'; break;
		    case RANK_KING:		std::cout << 'K'; break;
		    case RANK_ACE:		std::cout << 'A'; break;
	    }

        switch (m_suit)
	    {
		    case SUIT_CLUB:		std::cout << 'C'; break;
		    case SUIT_DIAMOND:	std::cout << 'D'; break;
		    case SUIT_HEART:	std::cout << 'H'; break;
		    case SUIT_SPADE:	std::cout << 'S'; break;
	    }
    }

    int getCardValue() const
    {
	    switch (m_rank)
	    {
	        case RANK_2:		return 2;
	        case RANK_3:		return 3;
	        case RANK_4:		return 4;
	        case RANK_5:		return 5;
	        case RANK_6:		return 6;
	        case RANK_7:		return 7;
	        case RANK_8:		return 8;
	        case RANK_9:		return 9;
	        case RANK_10:		return 10;
	        case RANK_JACK:		return 10;
	        case RANK_QUEEN:	return 10;
	        case RANK_KING:		return 10;
	        case RANK_ACE:		return 11;
	    }
	    return 0;
    }
};

class Deck
{
private:
    std::array<Card, 52> m_deck;
	int *m_cardIndex = 0;

	// generate random number in range
    int getRandomNumber(int min, int max)
    {
	    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    void swapCard(Card &a, Card &b)
    {
	    Card temp = a;
	    a = b;
	    b = temp;
    }

public:
    Deck()
    {
		// constructor for intialize deck
	    int card = 0;
	    for (int suit = 0; suit < Card::MAX_SUITS; ++suit){
	        for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
	        {
		        m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
		        ++card;
	        }
        }
    }

    void printDeck() const
    {
        for(const auto &card : m_deck)
        {
            card.printCard();
            std::cout << ' ';
        }
    }

    void shuffleDeck()
    {
	    // iterate all deck card
	    for (int index = 0; index < 52; ++index)
	    {
		    // choose random card
		    int swapIndex = getRandomNumber(0, 51);
			// swap current and random card
		    swapCard(m_deck[index], m_deck[swapIndex]);
	    }
    }

	const Card *dealCard()
	{
		return &deck[*m_index++];
	}
};
 
// char getPlayerChoice()
// {
// 	std::cout << "(h) to hit, or (s) to stand: ";
// 	char choice;
// 	do
// 	{
// 		std::cin >> choice;
// 	} while (choice != 'h' && choice != 's');
	
// 	return choice;
// }
 
// bool playBlackjack(const std::array<Card, 52> deck)
// {
// 	const Card *cardPtr = &deck[0];
 
// 	int playerTotal = 0;
// 	int dealerTotal = 0;
 
// 	// Дилер отримує одну карту
// 	dealerTotal += getCardValue(*cardPtr++);
// 	std::cout << "The dealer is showing: " << dealerTotal << '\n';
 
// 	// Гравець отримує дві карти
// 	playerTotal += getCardValue(*cardPtr++);
// 	playerTotal += getCardValue(*cardPtr++);
 
// 	// Гравець починає
// 	while (1)
// 	{
// 		std::cout << "You have: " << playerTotal << '\n';
// 		char choice = getPlayerChoice();
// 		if (choice == 's')
// 			break;
 
// 		playerTotal += getCardValue(*cardPtr++);
		
// 		// Дивимося, чи гравець не програв
// 		if (playerTotal > 21)
// 			return false;
// 	}
 
// 	// Якщо гравець не програв (у нього не більше 21 очка), тоді дилер отримує карти до тих пір, поки у нього в підсумку буде не менше 17 очків
// 	while (dealerTotal < 17)
// 	{
// 		dealerTotal += getCardValue(*cardPtr++);
// 		std::cout << "The dealer now has: " << dealerTotal << '\n';
// 	}
 
// 	// Якщо у дилера більше 21 очка, то він програв, а гравець виграв
// 	if (dealerTotal > 21)
// 		return true;
 
// 	return (playerTotal > dealerTotal);
// }
 
int main()
{
	srand(static_cast<unsigned int>(time(0))); // use system clock to set start number
	rand(); // reset the start number
 
	// std::array<Card, 52> deck;
	
	// shuffleDeck(deck);
 
	// if (playBlackjack(deck))
	// 	std::cout << "You win!\n";
	// else
	// 	std::cout << "You lose!\n";

    Deck deck;
    deck.printDeck();
    deck.shuffleDeck();
    deck.printDeck();
}