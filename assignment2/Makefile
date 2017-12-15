blackjack: Card.o Deck.o Hand.o Player.o Dealer.o Game.o driver.o
	g++ Card.o Deck.o Hand.o Player.o Dealer.o Game.o driver.o -o blackjack
Card.o: Card.cpp
	g++ -c Card.cpp
Deck.o: Deck.cpp
	g++ -c Deck.cpp
Hand.o: Hand.cpp
	g++ -c Hand.cpp
Player.o: Player.cpp
	g++ -c Player.cpp
Dealer.o: Dealer.cpp
	g++ -c Dealer.cpp
Game.o: Game.cpp
	g++ -c Game.cpp
driver.o: driver.cpp
	g++ -c driver.cpp
clean:
	rm –f *.out *.o blackjack
