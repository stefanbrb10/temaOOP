#include "aplicatie.h"

Aplicatie &Aplicatie::getAplicatie() {
    static Aplicatie aplicatie;
    return aplicatie;
}

void Aplicatie::printMeniu() {
    std::cout << "\n--------MENIU---------\n";
    std::cout << "0. Inchide aplicatie\n";
    std::cout << "1.Adauga jucator\n";
    std::cout << "2. Afiseaza jucatori\n";
}

void Aplicatie::addJucator() {
    int age;
    string position;
    string name;
    string team;
    std::cin >> age >> position >> name >> team;
    Player jucator(name, team, position, age);
    jucatori.push_back(jucator);
}

void Aplicatie::printJucator() {
    for(auto jucator:jucatori)
        std:: cout << jucator << "\n";
}
