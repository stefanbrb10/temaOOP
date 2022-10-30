#include <iostream>
#include<string>
#include "match.h"
#include "team.h"
#include "player.h"
#include<vector>

using namespace std;

int main(){
    Match M1("03.11.2022", "FCSB", "Rapid", 1, 1);
    M1.Score();
    cout << endl;
    Match M2("06.11.2022", "FCSB", "West Ham", 0, 3);
    M2.Score();
    return 0;
}
