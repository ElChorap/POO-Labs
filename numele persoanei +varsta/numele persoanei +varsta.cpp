#include "pch.h"

#include <iostream>
#include <string>

using namespace std;

struct persoana {
    string nume;
    int varsta;
};

int main() {
    int numar_persoane;

    cout << "Introduceti numarul de persoane: ";
    cin >> numar_persoane;

    persoana* persoane = new persoana[numar_persoane];

    for (int i = 0; i < numar_persoane; i++) {
        cout << "Introduceti numele persoanei " << i + 1 << ": ";
        cin >> persoane[i].nume ;

        cout << "Introduceti varsta persoanei " << i + 1 << ": ";
        cin >> persoane[i].varsta;
    }

    cout << endl << "Persoanele introduse sunt:" << endl;

    for (int i = 0; i < numar_persoane; i++) {
        cout << persoane[i].nume << ", " << persoane[i].varsta << " ani" << endl;
    }

    delete[] persoane;
    return 0;
}
