#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED

#endif // MAZO_H_INCLUDED

#include <iostream>
using namespace std;


int mostrarMazoDeElementos(int vec[]);
void llenarMazoElemento();
void vaciarMazoFlagElementos(bool flagElemento[]);
void repartirTresCartasHumano(int vec[],bool flagElemento[]);
void repartirTresCartasCPU(int vec[],int vec2[],bool flagElemento[]);
string descripcionCarta(int cartaHumano);
void cualesSonMisCartas(int mazoHumano[]);
int robarCartaPilaHumano(int mazoHumano[], bool flagElemento[]);
int robarCartaPilaCPU(int mazoCPU[], bool flagElemento[]);
int tirarCartaHumano(int mazoHumano[]);
int tirarCartaCPU(int mazoCPU[]);




