#pragma once
#include <deque>
#include <vector>
#include <string>
#include "Card.h"

class Player {
	private:
		std::deque<Card> deck;
		std::vector<Card> hand;
		
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