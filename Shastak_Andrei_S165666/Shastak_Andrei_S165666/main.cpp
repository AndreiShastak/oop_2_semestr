#include <iostream>
#include <conio.h>
#include "Human.h"
#include <stdlib.h>   
#include <time.h>

using namespace std;

int main() {
	char ch = 0;
	int width = 50;
	int height = 20;
	/*cout << "podaj szerocosc i wysokosc" << endl;
	cin >> width >> height;*/
	World * myWorld = new World(width, height);
	srand(time(NULL));

	while (ch != 'f') {
		if (ch == 's')
		{
			myWorld->save();
		}
		else if (ch == 'l')
		{
			myWorld->load();
		}
		else
		{
			myWorld->doTurn(ch);
			myWorld->draw();
		}
		ch = _getch();
	}
	delete myWorld;
	return 0;
}