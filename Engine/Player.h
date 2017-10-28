#pragma once
#include "MainTypes.h"
#include "Map.h"
#include <algorithm> // std::pair

class Player {
protected:
	/* Pola */
	states myState;
	Map& myMap;

public:
	/* Konstruktory */
	Player(Map&, states);

	/* Metody */
	void setState(states);

	/* Metody uprzywilejowane */
	states getState() const { return myState; };

	bool move(int x, int y);
};

class AI : Player {
public:
	std::pair<int, int> calculatePosition()
	{
		return { 0, 0 }; // zwracamy pozycjê ruchu - po zaimplementowaniu AI
	}
};