#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <iostream>
#include <fstream>

using namespace std;

class human
{
	int Number;
	char* surename;
	char* name;
	int age;
	char* answer;
public:
	human();
	human(int nu, char* sun, char* na, int a, char* ans);
	human(const human& item);
	~human();

	void print();
	human& operator=(const human& item);
	friend human* Add(human* mass, int Number);
	friend human* Delete(human* mass, int Number);
	friend void Searchh(human* mass, int Number);
	friend human* Edit(human* mass, int Number);
	friend istream& operator>>(istream& in, human& item);
	friend ostream& operator<<(ostream& out, human& item);
	friend void Pechat(human* mass, int Number);
};


int Save(human* mass, int Number, char* way);
human* Read(char* way, int* Number);
int Menu(void);


#endif // TEST_H
