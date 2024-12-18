#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Angajat {
    string nume;
    string prenume;
    float salariu;
    int aniMunca;
    string functie;
    string nivel;
};

bool comparaAniMunca(const Angajat &a, const Angajat &b) {
    return a.aniMunca < b.aniMunca;
}

bool comparaSalariu(const Angajat &a, const Angajat &b) {
    return a.salariu > b.salariu;
}

bool esteFemeie(const Angajat &a) {

    return a.prenume.back() == 'a';
}

int main() {

    Angajat angajati[15] = {
        {"Popescu", "Andrei", 3200.00, 5, "Angajat"},
        {"Ionescu", "Maria", 6000.00, 11, "Director"},
        {"Dumitrescu", "Ana", 3000.00, 3, "Angajat"},
        {"Dumitru", "Cristian", 5500.00, 15, "Administrator"},
        {"Vasilescu", "Elena", 2800.00, 2, "Angajat"},
        {"Marinescu", "Radu", 4000.00, 6, "Angajat"},
        {"Petrescu", "Adriana", 3500.00, 4, "Angajat"},
        {"Stoica", "Gabriel", 5000.00, 9, "Angat"},
        {"Tanase", "Irina", 3700.00, 5, "Angajat"},
        {"Grigore", "Paul", 2900.00, 3, "Angajat"},
        {"Ciobanu", "Mihai", 5800.00, 7, "Angajat"},
        {"Moldovan", "Ioana", 3100.00, 2, "Angajat"},
        {"Rusu", "Daniel", 4500.00, 8, "Angajat"},
        {"Nistor", "Diana", 4200.00, 6, "Angajat"},
        {"Sandu", "Alina", 3400.00, 4, "Angajat"}
    };

    sort(angajati, angajati + 15, comparaAniMunca);

    for (int i = 0; i < 15; i++) {
        if (angajati[i].functie == "Angajat") {
            angajati[i].salariu = 2800 + angajati[i].aniMunca * 100;

            if (angajati[i].aniMunca < 5) {
                angajati[i].nivel = "Incepator";
            } else if (angajati[i].aniMunca >= 5 && angajati[i].aniMunca <= 9) {
                angajati[i].nivel = "Experimentat";
            } else {
                angajati[i].nivel = "Maistru";
            }
        }
    }

    sort(angajati, angajati + 15, comparaSalariu);

    vector<Angajat> femei;
    vector<Angajat> barbati;
    for (int i = 0; i < 15; i++) {
        if (esteFemeie(angajati[i])) {
            femei.push_back(angajati[i]);
        } else {
            barbati.push_back(angajati[i]);
        }
    }

    cout << "INFORMATII - FEMEI:\n";
    cout << "\n";
    for (size_t i = 0; i < femei.size(); i++) {
        cout << "Angajat " << i + 1 << ":\n";
        cout << "Functie: " << femei[i].functie << endl;
        cout << "Nume: " << femei[i].nume << endl;
        cout << "Prenume: " << femei[i].prenume << endl;
        cout << "Salariu: " << femei[i].salariu << " RON" << endl;
        cout << "Ani de munca: " << femei[i].aniMunca << " ani\n";
        cout << "Nivel: " << femei[i].nivel << endl;
        cout << "\n \n \n";
    }

    cout << "INFORMATII - BARBATI:\n";
    cout << "\n";
    for (size_t i = 0; i < barbati.size(); i++) {
        cout << "Angajat " << i + 1 << ":\n";
        cout << "Functie: " << barbati[i].functie << endl;
        cout << "Nume: " << barbati[i].nume << endl;
        cout << "Prenume: " << barbati[i].prenume << endl;
        cout << "Salariu: " << barbati[i].salariu << " RON" << endl;
        cout << "Ani de munca: " << barbati[i].aniMunca << " ani\n";
        cout << "Nivel: " << barbati[i].nivel << endl;
        cout << "\n";
    }

    return 0;
}
