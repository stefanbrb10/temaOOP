#include <iostream>
#include <string>
#include "match.h"
#include "team.h"
#include "player.h"
#include<vector>
#include <fstream>
#include <sstream>

#define SQUAD_SIZE 26
#define AGE_DIF 22
#define MIN_AGE 16

using namespace std;

int main(){
  /*  string st, t;
    ifstream fin("tastatura.txt");
    while(getline(fin, st)){
        stringstream x(st);
        int i = 0;
        string name, team, position;
        int age;
        vector<Player>P;
        while(getline(x,t,'/')) {
            if(i==0)
                name = t;
            else if(i==1)
                team = t;
            else if(i==2)
                position = t;
            else if(i==3) {
                stringstream nr(t);
                nr >> age;
            }
            i++;
        }
        cout << "\n";
        Player player(name,team,position,age);
        P.push_back(player);
    }
    fin.close();*/
    vector<string> prenume = {"Stefan", "Octavian", "Cristian", "Moussoufa",
                              "Marius", "Catalin", "Andrei", "Wesley", "Novak", "Filip", "Robert",
                              "John", "Hugo", "Lionel", "Ruben", "Mihai", "Vlad", "Mohammed", "Darius",
                              "Laurentiu", "Dragos", "George", "Patrick", "Ionut", "Marc", "Giani",
                              "Benjamin", "Marco", "Roberto","Costinel", "Marin", "Rocco", "Adelin",
                              "Denis", "Gabriel", "Giovanny", "Raul", "Horea", "Federico", "Rashid",
                              "Vasile", "Cristian", "Sebastian", "Cosmin", "Gelu", "Antonio", "Cezar",
                              "Mason"};

    vector<string> nume = {"Barbu", "Popescu", "Martinovic", "Patulea", "Rusu",
                           "Chirica", "Florea", "Vlad", "Vasile", "Messi", "Diaz", "Al Rahman", "Olaru",
                           "Lavric", "Elias", "Anghel", "Mihaila", "Marszolik", "Gaina", "Dumitrache", "Cretu"
                                                                                                       "Elias", "Toderean", "Iancu", "Cretu", "Velicu", "Ionescu", "Petrov", "Pozniak",
                           "Neagu", "White", "Eftene", "Pisica", "Milescu", "Pitoi", "Costea", "Nastase",
                           "Dociu", "Lewandowski", "Sapunaru", "Andronic", "Schlotterbeck", "Valverde", "Dragnoi",
                           "Surdu", "Gidoiu", "Bradu", "Melcu", "Chira", "Gabor", "Rus", "Chitu", "Becali",
                           "Tanase", "Istrate", "Nersidan", "Sandu", "Podocea", "Budeanu", "Cimpeanu"};

    vector <string>pos = {"Defender", "Defender", "Defender",
                          "Midfielder", "Midfielder", "Midfielder", "Striker", "Striker"};

    vector<string> teams1 = {"FCSB", "FC Rapid", "CFR Cluj", "U Cluj", "Farul Constanta",
                             "Hermannstadt Sibiu", "Petrolul Ploiesti", "Sepsi OSK", "FC Voluntari",
                             "FC Arges Pitesti", "Chindia Targoviste", "FC Botosani", "UTA Arad", "Craiova 1948",
                             "Universitatea Craiova", "FC Mioveni"};

    vector<string> teams2 = {"CSA Steaua", "Unirea Slobozia", "Csikszereda Miercurea Ciuc",
                             "Poli Iasi", "Buzau", "Unirea Dej", "Otelul Galati", "Dinamo Bucuresti",
                             "CSM Slatina", "FC Brasov", "Selimbar", "Concordia Chiajna", "CSM Oltenita",
                             "Viitorul Tg Jiu", "Minaur Baia Mare", "Progresul Spartac", "Victoria Chirnogi",
                             "FC Dumbravita", "AFC Unirea Constanta", "Poli Timisoara"};


    ofstream liga1("liga1.txt");
    ofstream liga2("liga2.txt");

    for(int i = 0; i < (int)teams1.size(); i++){
        int captain = rand() % SQUAD_SIZE;
        for(int j = 0; j < SQUAD_SIZE; j++){
            liga1 << prenume[rand() % prenume.size()] << " " <<
                  nume[rand() % nume.size()];
            if(j == captain)
                liga1 << "(C)";
            liga1 << "/" << teams1[i] << "/" << rand() % AGE_DIF + MIN_AGE <<
                  "/";
            if(j == 0 || j == 11)
                liga1 << "Goalkeeper" << endl;
            else liga1 << pos[rand() % pos.size()] << endl;
        }
    }

    for(int i = 0; i < (int)teams2.size(); i++){
        int captain = rand() % SQUAD_SIZE;
        for(int j = 0; j < SQUAD_SIZE; j++){
            liga2 << j + 1 << "/" << prenume[rand() % prenume.size()] << " " <<
                  nume[rand() % nume.size()];
            if(j == captain)
                liga2 << "(C)";
            liga2 << "/" << teams2[i] << "/" << rand() % AGE_DIF + MIN_AGE <<
                  "/";
            if(j == 0 || j == 11)
                liga2 << "Goalkeeper" << endl;
            else liga2 << pos[rand() % pos.size()] << endl;
        }
    }

     int etapa[21][21] = {{0}};
     int sz = teams1.size();
     cout << sz;

     for(int i = 0; i < sz; i++){
         cout << "ETAPA " << i+1 << "\n-----------------\n";
         int check[21] = {0};
         for(int j = 0; j < sz / 2; j++){
             int e1 = 20, e2 = 20;
             while(e1 == e2 || etapa[e1][e2] == 1 || etapa[e2][e1] == 1 || check[e1] == 1 || check[e2] == 1){
                 e1 = rand() % sz;
                 e2 = rand() % sz;
             }
             cout << e1 << " " << e2 << endl;
             cout << teams1[e1] << "-" << teams1[e2] << endl;
             check[e1] = 1;
             check[e2] = 1;
             etapa[e1][e2] = 1;
             etapa[e2][e1] = 1;
         }
         for(int k = 0; k < sz; k++)
             cout << check[k] << " ";
         cout << endl;
     }

    return 0;
}
