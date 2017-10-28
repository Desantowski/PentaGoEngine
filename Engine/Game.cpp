#include "Game.h"

//Konstruktor silnika gry
//Awesome job by M. Kucharskov (https://kucharskov.pl)
Game::Game() : m(2, 3), lastState(states::clear) {
	clear();
	player = std::make_shared<Player>(getMap(),states::white);
	opponent = std::make_shared<Player>(getMap(),states::black);
	currentPlayer = opponent;
}

//Funkcja czyszczaca mape i resetujaca gre
void Game::clear() {
	m.clear();
	lastState = states::clear;
}

//Funkcja wykonywania ruchu
bool Game::move(int x, int y) {
	// Przestawienie gracza na nastêpnego
	currentPlayer = (currentPlayer == opponent) ? player : opponent;

	//Wykonywanie ruchu i zwracanie powodzenia
	bool isGood{ m.move(x, y, currentPlayer->getState()) };

	//W przypadku niepowodzenia - przestawienie gracza na poprzedniego, by w nastêpnym wywo³aniu move() obecny wykona³ ruch
	if(!isGood)
		currentPlayer = (currentPlayer == opponent) ? player : opponent;

	return isGood;
}

//Funkcja obracajaca w lewo segment na mapie
bool Game::rotate(int x, int y, rotates dir) {
	return m.rotate(x, y, dir);
}

//Funkcja zwracajaca wartosc danego pola
states Game::getState(int x, int y) {
	return m.getState(x, y);
}

//Funkcja sprawdzajaca czy nastapila wygrana
results Game::checkWin() {
	return m.checkWin();
}