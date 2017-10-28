#include <iostream>
#include <memory>
#include <array>
#include "Engine/Game.h"
#include "Engine/Player.h"


void print(Game g)
{
	for (int i = 0; i < g.getSize(); i++) {
		for (int j = 0; j < g.getSize(); j++) {
			switch ((int)g.getState(j, i)) {
			case 0:
				std::cout << "   ";
				break;
			case 1:
				std::cout << " B ";
				break;
			case 2:
				std::cout << " W ";
				break;
			}
			if (j < g.getSize() - 1) std::cout << "|";
			else std::cout << std::endl;
		}
		if (i < g.getSize() - 1) for (int k = 0; k < g.getSize(); k++) std::cout << "--- ";
		std::cout << std::endl;
	}
}

int main()
{
	Game g;

	int option;
	std::cout << "1. Human vs AI\n2. Human vs human\nSelect option:";
	std::cin >> option;
	if (option == 1)
	{
		std::array<int, 5> xai{ 1, 1, 1, 1 , 1 };
		std::array<int, 5> yai{ 0, 1, 2, 3, 4 };
		int i = 0;
		while (g.checkWin() == results::nowin)
		{
			// Ruch gracza
			unsigned int x, y;
			std::cin >> x >> y;
			g.move(x, y);
			print(g);

			// Ruch AI
			g.move(xai[i], yai[i]);
			i++;
			print(g);
		}
	}
	else
	{
		while (g.checkWin() == results::nowin)
		{
			// Ruch gracza
			unsigned int x, y;
			std::cin >> x >> y;
			g.move(x, y);
			print(g);
		}
	}
	std::cout << "Wynik: " << (int)g.checkWin() << std::endl;
	system("PAUSE");
}

/*//Testowy main
int main()
{
	//Inicjalizacja silnika gry
	Game g;

	//Inicializacja graczy
	Human h(g.getMap(), states::white);
	AI ai(g.getMap(), states::black);

	//Wykonanie ruchow dajacych remis
	g.move(h, 0, 0);
	g.move(ai, 1, 0);
	g.move(h, 0, 1);
	g.move(ai, 1, 1);
	g.move(h, 0, 2);
	g.move(ai, 1, 2);
	g.move(h, 0, 3);
	g.move(ai, 1, 3);
	g.move(h, 0, 4);
	g.move(ai, 1, 4);

	//Rysowanie planszy dla podgladu

	//Sprawdzanie wyniku (3 to states::draw)
	std::cout << "Oczekiwany wynik to 3\n";
	std::cout << "Wynik: " << (int)g.checkWin() << std::endl;

	system("PAUSE");
	return 0;
}*/