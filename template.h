//
// Created by Stefan on 20-Jan-23.
//

#ifndef OOP_TEMPLATE_H
#define OOP_TEMPLATE_H
#include <iostream>
#include <map>
#include "player.h"

template <typename T> T compara(T x, T y)
{
    return (x > y) ? x : y;
}

template<typename T>
class Clasament{
private:
        map<T,int> puncte;
public:
        void addEchipa(T echipa){
            puncte[echipa] = 0;
        }
        void addPuncte(T echipa, int nrPuncte){
            puncte[echipa] += nrPuncte;
        }
        void printClasament(){
            int poz = 1;
            for (const auto &echipa: puncte) {
                std::cout << poz++ << " " << echipa.first << " " << echipa.second << "\n";
            }
        }
    };

#endif //OOP_TEMPLATE_H
