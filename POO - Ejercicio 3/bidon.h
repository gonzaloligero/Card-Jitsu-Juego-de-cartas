#ifndef BIDON_H_INCLUDED
#define BIDON_H_INCLUDED
#include <iostream>


using namespace std;
class Bidon{
    private:
    string _sabor;
    int _capacidad;

    public:
    Bidon();
    int extraer(int cantidad);
    void setSabor(string sabor);
    void setCapacidad(int capacidad);
    string getSabor();
    int getCapacidad();
};

#endif // BIDON_H_INCLUDED
