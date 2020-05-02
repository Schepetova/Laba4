#include "human.hpp"
#include <stdlib.h>
#include <string.h>

human::human()
{
	Number = age = 0;
	name = surename = answer = NULL;
}

human::human(int nu, char* sun, char* na, int a, char* ans)
{
	Number = nu;
	age = a;
	surename = new char[strlen(sun) + 1];
	surename[0] = '\0';
	strcpy(surename, (strlen(sun) + 1) * sizeof(char), sun);
	name = new char[strlen(na) + 1];
	name[0] = '\0';
	strcpy(name, (strlen(na) + 1) * sizeof(char), na);
	answer = new char[strlen(ans) + 1];
	answer[0] = '\0';
	strcpy(answer, (strlen(ans) + 1) * sizeof(char), ans);
}

human::human(const human& item)
{
	Number = item.Number;
	age = item.age;
	surename = new char[strlen(item.surename) + 1];
	surename[0] = '\0';
	strcpy(surename, (strlen(item.surename) + 1) * sizeof(char), item.surename);
	name = new char[strlen(item.name) + 1];
	name[0] = '\0';
	strcpy(name, (strlen(item.name) + 1) * sizeof(char), item.name);
	answer = new char[strlen(item.answer) + 1];
	answer[0] = '\0';
	strcpy(answer, (strlen(item.answer) + 1) * sizeof(char), item.answer);
}

human::~human()
{
	delete name;
	delete surename;
	delete answer;
}



void Pechat(human* mass, int Number) //Print function
{
	cout << "N Surename Name Age Answer" << endl;
	for (int i = 0; i < Number; i++) {
		cout << mass[i].Number << " " << mass[i].surename << " " << mass[i].name << " " << mass[i].age << " " << mass[i].answer << endl;
	}
	printf("\n");
} //End of Print function

human& human::operator=(const human& item)
{
	Number = item.Number;
	age = item.age;
	name = new char[strlen(item.name) + 1];
	name[0] = '\0';
	strcpy(name, (strlen(item.name) + 1) * sizeof(char), item.name);
	surename = new char[strlen(item.surename) + 1];
	surename[0] = '\0';
	strcpy(surename, (strlen(item.surename) + 1) * sizeof(char), item.surename);
	answer = new char[strlen(item.answer) + 1];
	answer[0] = '\0';
	strcpy(answer, (strlen(item.answer) + 1) * sizeof(char), item.answer);
	return *this;
}

human* Add(human* mass, int Number) // Add element function
{
	int dob;
	char buf[100];
	cout << "Number -";
	cin.getline(buf, 99);
	dob = atoi(buf);
	for (int i = 0; i < Number; i++)
	{
		if (mass[i].Number == dob)
		{
			cout << "Sorry,This Number is occupied. Try another one." << endl;
			return mass;
		}
	}
	human* res = new human[Number + 1];
	for (int i = 0; i < Number; i++)
		res[i] = mass[i];
	res[Number].Number = dob;
	cout << "Enter surename - ";
	cin.getline(buf, 99);
	res[Number].surename = new char[strlen(buf) + 1];
	res[Number].surename[0] = '\0';
	strcpy(res[Number].surename, (strlen(buf) + 1) * sizeof(char), buf);
	cout << "Enter name -";
	cin.getline(buf, 99);
	res[Number].name = new char[strlen(buf) + 1];
	res[Number].name[0] = '\0';
	strcpy(res[Number].name, (strlen(buf) + 1) * sizeof(char), buf);
	cout << "Enter age -";
	cin.getline(buf, 99);
	res[Number].age = atoi(buf);
	cout << "What did This human answer to the question?-";
	cin.getline(buf, 99);
	res[Number].answer = new char[strlen(buf) + 1];
	res[Number].answer[0] = '\0';
	strcpy(res[Number].answer, (strlen(buf) + 1) * sizeof(char), buf);
	return res;
} //End of Add function

human* Delete(human* mass, int Number) //Delete function
{
	Pechat(mass, Number);
	cout << "Enter number of human you want to Delete-" << endl;
	char buf[100];
	cin.getline(buf, 99);
	int i = atoi(buf);
	if (i<1 || i>Number)
	{
		cout << "Something is wrong! Try Again" << endl;
		return mass;
	}
	human* res = new human[Number - 1];
	int a = 0;
	for (int j = 0; j < Number; j++)
		if (i != j)
			res[a++] = mass[j];
	return res;
} //End of Delete function

int Save(human* mass, int Number, char* way)
{
	ofstream out(way);
	if (!out.is_open())
		return 0;
	out << Number << endl;
	for (int i = 0; i < Number; i++)
		out << mass[i];
	out.close();
	return 1;
} //End of Save function

human* Read(char* way, int* Number)
{
	ifstream in(way);
	if (!in.is_open())
		return NULL;
	char buf[100];
	in.getline(buf, 99);
	*Number = atoi(buf);
	human* res = new human[*Number];
	for (int i = 0; i < *Number; i++)
		in >> res[i];
	in.close();
	return res;
}// End of Read function

void Searchh(human* mass, int Number)
{
	cout << "Enter human you want us to find ('surename name')" << endl;
	int tmp = -1;
	char surename[100];
	char name[100];
	cin.getline(surename, 99);
	cin.getline(name, 99);
	for (int i = 0; i < Number; i++)
	{
		if ((strcmp(mass[i].surename, surename) == 0) && (strcmp(mass[i].name, name) == 0))
		{
			cout << mass[i].Number << " " << mass[i].surename << " " << mass[i].name << " " << mass[i].age << " " << mass[i].answer << endl;
			tmp = 1;
			break;
		}
	}
	if (tmp == -1)
	{
		cout << "Sorry, we can't find it" << endl;
	}
}

int Menu()
{
	int a = 0;
	char buf[10];
	while (a < 1 || a> 7)
	{
		cout << "1: Enter New human" << endl << "2: Delete human" << endl << "3: Search" << endl << "4: Edit human's information" << endl << "5: Print Data" << endl << "6: Save in file" << endl << "7: Complete the work" << endl;
		cin.getline(buf, 9);
		a = atoi(buf);
	}
	return a;
} //end of main function

human* Edit(human* mass, int Number)
{
	Pechat(mass, Number);
	cout << "Input N of human you want to edit: ";
	char buf[100];
	cin.getline(buf, 99);
	int num = atoi(buf);
	int i;
	for (i = 0; i < Number; i++)
		if (mass[i].Number == num)
			break;
	if (i == Number)
	{
		cout << "Human not found!" << endl;
		return mass;
	}
	cout << "Want you want to edit? 1 - Number, 2 - Surename, 3 - Name, 4 - Age, 5 - Answer" << endl;
	cin.getline(buf, 99);
	int mode = atoi(buf);
	switch (mode)
	{
	case 1:
		cout << "Input new Number: ";
		cin.getline(buf, 99);
		mass[i].Number = atoi(buf);
		break;
	case 2:
		cout << "Input new Surename: ";
		cin.getline(buf, 99);
		delete mass[i].surename;
		mass[i].surename = new char[strlen(buf) + 1];
		mass[i].surename[0] = '\0';
		strcpy(mass[i].surename, (strlen(buf) + 1) * sizeof(char), buf);
		break;
	case 3:
		cout << "Input new Name: ";
		cin.getline(buf, 99);
		delete mass[i].name;
		mass[i].name = new char[strlen(buf) + 1];
		mass[i].name[0] = '\0';
		strcpy(mass[i].name, (strlen(buf) + 1) * sizeof(char), buf);
		break;
	case 4:
		cout << "Input new Age: ";
		cin.getline(buf, 99);
		mass[i].age = atoi(buf);
		break;
	case 5:
		cout << "Input new Answer: ";
		cin.getline(buf, 99);
		delete mass[i].answer;
		mass[i].answer = new char[strlen(buf) + 1];
		mass[i].answer[0] = '\0';
		strcpy(mass[i].answer, (strlen(buf) + 1) * sizeof(char), buf);
		break;
	default:
		cout << "wrong edit mode!" << endl;
		break;
	}
	return mass;
}

istream& operator>>(istream& in, human& item)
{
	char buf[100];
	in.getline(buf, 99);
	item.Number = atoi(buf);
	in.getline(buf, 99);
	item.surename = new char[strlen(buf) + 1];
	item.surename[0] = '\0';
	strcpy(item.surename, (strlen(buf) + 1) * sizeof(char), buf);
	in.getline(buf, 99);
	item.name = new char[strlen(buf) + 1];
	item.name[0] = '\0';
	strcpy(item.name, (strlen(buf) + 1) * sizeof(char), buf);
	in.getline(buf, 99);
	item.age = atoi(buf);
	in.getline(buf, 99);
	item.answer = new char[strlen(buf) + 1];
	item.answer[0] = '\0';
	strcpy(item.answer, (strlen(buf) + 1) * sizeof(char), buf);
	return in;
}

ostream& operator<<(ostream& out, human& item)
{
	out << item.Number << endl << item.surename << endl << item.name << endl << item.age << endl << item.answer << endl;
	return out;
}
