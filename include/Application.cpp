#include <iostream>
#include <algorithm> // shuffle
#include <random>
#include <chrono>
#include <deque>
#include <vector>
#include "Player.h"
#include "Card.h"

int main() {
	// Generates Deck
	std::deque<Card> newDeck;
	for(int i = 0; i < 100; i++) {
		newDeck.push_back(Card(std::to_string(i)));
	}
	
	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	
	// Shuffle the your deck when entering the game
	shuffle(newDeck.begin(), newDeck.end(), std::default_random_engine(seed)); 
	
	// Move first 8 cards to hand
	std::vector<Card> newHand;
	for(int i = 0; i < 8; i++) {
		newHand.push_back(newDeck.front());
		newDeck.pop_front();
	}
	
	Player p = Player(newDeck, newHand);
	std::cout << p.getHand() << std::endl;
	
	p.takeDamage(30, false);
	
	std::string in;
	std::cin >> in;
	
	return 0;
}