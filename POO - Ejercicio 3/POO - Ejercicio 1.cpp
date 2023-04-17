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

int main(){
Bidon bidonBanana,bidonAnana,bidonSandia;
string sabor;
int capacidad;
int codigoBatido;

cout<<"Ingrese el sabor del primer bidon:";
cin>>sabor;
bidonBanana.setSabor(sabor);
cout<<"Ingrese su capacidad:";
cin>>capacidad;
bidonBanana.setCapacidad(capacidad);

cout<<"Ingrese el sabor del segundo bidon:";
cin>>sabor;
bidonAnana.setSabor(sabor);
cout<<"Ingrese su capacidad:";
cin>>capacidad;
bidonAnana.setCapacidad(capacidad);

cout<<"Ingrese el sabor del tercer bidon:";
cin>>sabor;
bidonSandia.setSabor(sabor);
cout<<"Ingrese su capacidad:";
cin>>capacidad;
bidonSandia.setCapacidad(capacidad);

cout<<"Ingrese codigo de batido:";
cin>>codigoBatido;

while(codigoBatido!=0){


cout<<"Ingrese codigo de batido:";
cin>>codigoBatido;
}


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



