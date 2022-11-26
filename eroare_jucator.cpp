
#include "eroare_jucator.h"
#include <string>

eroare_jucator::eroare_jucator(const std::string &arg) : runtime_error(arg){}

eroare_varstaJucator::eroare_varstaJucator(): eroare_jucator("Varsta jucatorului este prea mica") { }

eroare_pozitieJucator::eroare_pozitieJucator() : eroare_jucator("Pozitia jucatorului nu este valida (portar, fundas, mijlocas, atacant)"){}

