
#ifndef OOP_EROARE_JUCATOR_H
#define OOP_EROARE_JUCATOR_H

#include <stdexcept>

class eroare_jucator: public std::runtime_error{
public:
    explicit eroare_jucator(const char* arg);
};

class eroare_varstaJucator: public eroare_jucator{
public:
    eroare_varstaJucator();
};

class eroare_pozitieJucator: public eroare_jucator{
public:
    eroare_pozitieJucator();
};

#endif //OOP_EROARE_JUCATOR_H
