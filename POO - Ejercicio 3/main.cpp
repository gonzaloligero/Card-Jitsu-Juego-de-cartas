#include <iostream>


using namespace std;


int main(){
Bidon bidonBanana,bidonAnana,bidonSandia;
string sabor;
int capacidad;

cout<<"Sabor del primer bidon:";
cin>>sabor;
Bidon::setCapacidad(sabor)

cout<<"Capacidad:";
cin>>capacidad;
Bidon::setCapacidad(capacidad);



return 0;
}

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
