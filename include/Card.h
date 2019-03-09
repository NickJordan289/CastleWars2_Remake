#pragma once
#include <string>

class Card {
	private:
		std::string name;
		int brickCost;
		int weaponCost;
		int crystalCost;
	
	public:
		Card() {
			this->name = "Default";
		}
		
		Card(std::string name) {
			this->name = name;
		}
		
		std::string getName() {
			return this->name;
		}
		
		int getBrickCost() {
			return this->brickCost;
		}
	
		int getWeaponCost() {
			return this->weaponCost;
		}
		
		int getCrystalCost() {
			return this->crystalCost;
		}
};