#pragma once
#include "MainTypes.h"
#include "Map.h"
#include "Player.h"
#include <memory>

class Game
{
protected:
	/* Pola */
	Map m;
	states lastState;
	std::shared_ptr<Player> player;
	std::shared_ptr<Player> opponent;
	std::shared_ptr<Player> currentPlayer;

public:
	/* Konstruktory */
	Game();

	/* Metody */
	virtual void clear();
	virtual bool move(int, int);
	bool rotate(int, int, rotates);
	states getState(int, int);
	results checkWin();

	/* Metody uprzywilejowane */
	int getSize() const { return m.getMapSize() * m.getSegmentSize(); };
	int getMapSize() const { return m.getMapSize(); };
	int getSegmentSize() const { return m.getSegmentSize(); };
	Map& getMap() { return m; }

	/* Klasy zaprzyjaznione */
	friend class MainWindow;

};

class GameWithAI : public Game
{
protected:
	std::shared_ptr<AI> opponent;

	std::pair<int, int> calculateAI() { return opponent->calculatePosition(); }
};