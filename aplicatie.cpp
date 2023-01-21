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

    Player jucator("Stefan", "CS Timisoara", "Goalkeeper", 22);
    jucatori.push_back(jucator);
}

void Aplicatie::printJucator() {
    for(auto jucator:jucatori)
        std:: cout << jucator << "\n";
}
