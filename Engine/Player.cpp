#include "Player.h"

//Konstruktor gracza
Player::Player(Map& m, states s = states::clear) : myMap(m), myState(s) {
}

//Metoda ustawiajaca kolor gracza
void Player::setState(states s) {
	myState = s;
}

bool Player::move(int x, int y) {
	return myMap.move(x, y, getState());
}