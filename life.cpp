#include <iostream>
#include <unistd.h>
//#include <time.h>
#include <string>

#include "Grid.h"

using namespace std;

int main()
{
	int generationMax = 10000;
	//string filename;

	//cout << "File to read from: ";
	//cin >> filename;

	//int size = 42;

	//cout << "World Size: ";
	//cin >> size;

	Grid life(112,58);
	life.randomize(3);
	life.display();

	for (int i = 0; i <= generationMax; i++)
	{
		life.newGeneration();
		life.display();

		usleep(100000);
	}

	return 0;
}