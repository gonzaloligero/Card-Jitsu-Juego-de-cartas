#ifndef CHOQUES_H_INCLUDED
#define CHOQUES_H_INCLUDED

#include <iostream>
using namespace std;

#endif // CHOQUES_H_INCLUDED

int evaluarChoqueElementos(int cartaHumano, int cartaCPU, int mazoHumano[],int mazoCPU[]);
int evaluarChoqueNumeros(int cartaHumano, int cartaCPU);
void choqueNumerosGanaHumano(int cartaHumano, int cartaCPU, int mazoHumano[],int mazoCPU[]);
void choqueNumerosGanaCPU(int cartaHumano, int cartaCPU, int mazoHumano[],int mazoCPU[]);
int evaluarMano (string nombreUsuario,int ronda, int cartaHumano, int cartaCPU, int mazoHumano[], int mazoCPU[]);
void descripcionDeCartasEnChoque(int cartaHumano, int CartaCPU);
void quePasoEnEstaMano(int resultadoChoqueDeCartas);
