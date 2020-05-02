#include <iostream>
#include "human.hpp"

using namespace std;

void main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "wrong program start!" << endl;
		return;
	}
	cout << "Hello! This is automation of polling" << endl;
	int Selection;
	int Number;
	human* mass = Read(argv[1], &Number);
	while ((Selection = Menu()) != 0 && Selection != 7)
		switch (Selection)
		{
		case 1:
			mass = Add(mass, Number);
			Number++;
			break;
		case 2:
			mass = Delete(mass, Number);
			Number--;
			break;
		case 3:
			Searchh(mass, Number);
			break;
		case 4:
			mass = Edit(mass, Number);
			break;
		case 5:
			Pechat(mass, Number);
			break;
		case 6:
			Save(mass, Number, argv[1]);
			break;
		default:
			cout << "wrong mode, try again!" << endl;
			break;
		}
	return;
}
