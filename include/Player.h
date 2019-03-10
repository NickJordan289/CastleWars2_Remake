#pragma once
#include <deque>
#include <vector>
#include <string>
#include "Card.h"

class Player {
	private:
		std::deque<Card> deck;
		std::vector<Card> hand;
		
		int castle=30;
		int wall=15;
		
		int builders=2;
		int recruits=2;
		int mages=2;
	
		int bricks;
		int weapons;
		int crystals;
		
	public:
		Player(std::deque<Card> deck, std::vector<Card> hand) {
			this->deck = deck;

			this->hand = hand;
		}
		
		std::string getHand() {
			std::string str = "";
			for(Card c : hand) {
				str += c.getName() + " ";
			}
			return str;
		}
		
		// Damage function that support ambushing
		void takeDamage(int amnt, bool ambush=false) {
			if(!ambush) { // only deal wall damage if ambush=true
				wall -= amnt; // deal damage to wall
				amnt = (wall < 0) ? std::abs(wall) : 0; // Get the overflow amount if damage overflowed
				wall = std::max(0, wall); // restrict range
			}
			castle = std::max(0, castle - amnt); // deal overflow to castle
			std::cout << "Wall: " << wall << " Castle: " << castle << std::endl;	
		}
		
		void useBricks(int amnt) {
			this->bricks = std::max(0, this->bricks-amnt);
		}
		
		void useWeapons(int amnt) {
			this->weapons = std::max(0, this->weapons-amnt);
		}
		
		void useCrystals(int amnt) {
			this->crystals = std::max(0, this->crystals-amnt);
		}
		
		int getBricks() {
			return this->bricks;
		}
		
		int getWeapons() {
			return this->weapons;
		}
		
		int getCrystals() {
			return this->crystals;
		}
};