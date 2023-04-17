#include <iostream>
#include "bido

using namespace std;

Bidon::Bidon(){
     _sabor= "Sin sabor";
    _capacidad = 0;
}

int Bidon::extraer(int cantidad){
    if((_capacidad-=cantidad)<0){
        _capacidad=0;
    }
}

void Bidon::setSabor(string sabor){
    _sabor=sabor;
}

void Bidon::setCapacidad(int capacidad){
    _capacidad=capacidad;
}

string Bidon::getSabor(){
    return _sabor;
}

int Bidon::getCapacidad(){
    return _capacidad;
}
