#include "pch.h"
#include <iostream>
using namespace System; // pentru Visual C++/CLI
using namespace std; // pentru biblioteci cu functii standard, cunoscute din C++
// de citit despre modificatorii private, public, protected
struct Persoana
{
	unsigned vs;
	char nume[20];
	char prenume[20];
};
class Pers
{
private:
	unsigned vs;
	char nume[20];
	char prenume[20];
public:
	// 2 metode cu acelasi nume cu cel al clasei, adica Pers
	// o metoda cu params si una fara params
	Pers(unsigned vs1, char* num1, char* prenum1)
	{
		vs = vs1;
		/* strcpy(nume, num1);
		strcpy(prenume, prenum1);*/
		strcpy_s(nume, 20, num1);
		strcpy_s(prenume, 20, prenum1);
	}
	Pers() {}
	unsigned arata_vs() {
		return this->vs;
	}
	char* arata_nume() {
		return this->nume;
	}
};
int main()
{
	unsigned int a1 = 0;
	a1 = 17;
	Console::WriteLine("Introduceti numarul de persoane: ");
	int nr_persoane;
	cin >> nr_persoane;
	Persoana* persoane = new Persoana[nr_persoane];
	for (int i = 0; i < nr_persoane; i++) {
		Console::WriteLine("Introduceti numele persoanei {0}: ", i + 1);
		char nume[20];
		cin >> nume;
		strcpy_s(persoane[i].nume, 20, nume);
		Console::WriteLine("Introduceti varsta persoanei {0}: ", i + 1);
		unsigned vs;
		cin >> vs;
		persoane[i].vs = vs;
	}
	Console::WriteLine("Afisam numele persoanelor si varstele aferente: "); //Specific Visual C++ / CLI
		//Console::WriteLine(p1.vs + "\t" + p1.nume + "\t" + p1.prenume); // eroare pe pointerul d caractere
		for (int i = 0; i < nr_persoane; i++) {
			cout << persoane[i].nume << "\t" << persoane[i].vs << endl;
		}
	//getchar();
	Console::ReadKey();// Specific Visual C++/CLI ech
}