#include "pch.h"


#include "iostream"
#include "vector"
#include "string"
using namespace System;
class Avion {
private:
    int locuriLibere;
    int locuriPasageri;
    int putere;
    int numarMotoare;
    std::string marca;
    int anFabricatie;
    int capacitateRezervor;
    double costInchiriere;

public:
    Avion(int locuriLibere, int locuriPasageri, int putere, int numarMotoare,
        std::string marca, int anFabricatie, int capacitateRezervor,
        double costInchiriere) {
        this->locuriLibere = locuriLibere;
        this->locuriPasageri = locuriPasageri;
        this->putere = putere;
        this->numarMotoare = numarMotoare;
        this->marca = marca;
        this->anFabricatie = anFabricatie;
        this->capacitateRezervor = capacitateRezervor;
        this->costInchiriere = costInchiriere;
    }

   
    

    void afisareDetalii() {
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "An fabricatie: " << anFabricatie << std::endl;
        std::cout << "Numar locuri pasageri: " << locuriPasageri << std::endl;
        std::cout << "Cost inchiriere: " << costInchiriere << std::endl;
        std::cout << std::endl;
    }

    void setCostInchiriere(double cost) {
        costInchiriere = cost;
    }

    bool fabricatInAnul(int an) {
        return anFabricatie == an;
    }

    bool operator<(const Avion& other) const {
        return locuriPasageri < other.locuriPasageri;
    }

    bool operator>(const Avion& other) const {
        return locuriPasageri > other.locuriPasageri;
    }
};

void afisareAvioaneFabricateInAnul(std::vector<Avion>& avioane, int an) {
    std::cout << "Avioane fabricate in anul " << an << ":" << std::endl;
    for (const auto& avion : avioane) {
        if (avion.fabricatInAnul(an)) {
            avion.afisareDetalii();
        }
    }
}

void afisareAvioaneSortateDupaLocuri(std::vector<Avion>& avioane, bool crescator) {
    if (crescator) {
        std::sort(avioane.begin(), avioane.end());
        std::cout << "Avioane sortate crescator dupa numarul de locuri pasageri:" << std::endl;
    }
    else {
        std::sort(avioane.rbegin(), avioane.rend());
        std::cout << "Avioane sortate descrescator dupa numarul de locuri pasageri:" << std::endl;
    }

    for (const auto& avion : avioane) {
        avion.afisareDetalii();
    }
}



int main() {
    Avion avion1(10, 200, 10000, 2, "Boeing", 2005, 15000, 3000.0);
    Avion   Avion2(15, 300, 12000, 3, "Airbus", 2009, 20000, 5200.0);
    // După crearea obiectelor avion1 și avion2

    // Afișează detaliile avionului 1
    { std::cout << "Detalii avion 1:" << std::endl;
    avion1.afisareDetalii();
    }

    // Afișează detaliile avionului 2
    {std::cout << "Detalii avion 2:" << std::endl;
    avion2.afisareDetalii();
    }
    // După crearea obiectelor avion1 și avion2

// Setează un nou cost de închiriere pentru avion1
    { double noulCost = 3500.0;
    avion1.setCostInchiriere(noulCost);
    }
    // Afișează detaliile actualizate ale avionului 1
    {std::cout << "Detalii avion 1 (dupa actualizarea costului de inchiriere):" << std::endl;
    avion1.afisareDetalii();
    }
    // Creează un vector de avioane și adaugă obiectele existente
    {std::vector<Avion> avioane;
    avioane.push_back(avion1);
    avioane.push_back(avion2);
    }

    // Afișează avioanele fabricate în anul 2005
    { int anCautat = 2005;
    afisareAvioaneFabricateInAnul(avioane, anCautat);
    }
    // Sortează și afișează avioanele în ordine crescătoare după numărul de locuri pasageri
    afisareAvioaneSortateDupaLocuri(avion, true);

    // Sortează și afișează avioanele în ordine descrescătoare după numărul de locuri pasageri
    afisareAvioaneSortateDupaLocuri(avion, false);

}