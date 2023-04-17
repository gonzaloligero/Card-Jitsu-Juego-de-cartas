#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#endif // MENU_H_INCLUDED

#include <iostream>
using namespace std;

void mostrarMenu();
string mostrarGraciasPorJugar();
void mostrarCreditos(int num);
void mostrarReglas (int num);
string pedirNombre();
void mostrarOpcionesJuegoPrevioRobarCarta();
void mostrarOpcionesJuegoParaTirarCarta();
int confirmarSalida(int num);
int calcularEstadisticasHumano(bool noPerdioNingunaHumano,string nombreUsuario,bool objetivoHumanoGeneral, bool objetivoCPUGeneral, bool vCombinacionGanadoraCPU,bool vCartaDesafioCPU, int contadorRondasGanadasHumano, int rondasGanadasContraMismoElementoHumano, int resultadoChoquedeCartas, int elementosEmpatados);
int calcularEstadisticasCPU(bool noPerdioNingunaCPU,bool objetivoCPUGeneral, bool objetivoHumanoGeneral, bool vCombinacionGanadoraHumano,bool vCartaDesafioHumano, int contadorRondasGanadasCPU, int rondasGanadasContraMismoElementoCPU,int resultadoChoquedeCartas,int elementosEmpatados);
int decideElAzar();
int quienGanoElJuego(string nombreUsuario,int acumuladorEstadisticasHumano, int acumuladorEstadisticasCPU, bool objetivoHumanoGeneral,bool objetivoCPUGeneral);
