#ifndef DESAFIOS_H_INCLUDED
#define DESAFIOS_H_INCLUDED

#include <iostream>
using namespace std;

int cartaDesafio();
string detalleCartaDesafio(int h);
bool objetivosCumplidosHumano(bool desafioCumplidoHumano,bool vectorObjetivosCumplidosHumano[]);
bool objetivosCumplidosCPU(bool desafioCumplidoCPU,bool vectorObjetivosCumplidosCPU[]);
bool cumplirDesafioHumanoElementos(int cartaHumano,int cartaCPU, int cartaDesafioHumano,int ronda);
bool cumplirDesafioCPUElementos(int cartaHumano,int cartaCPU, int cartaDesafioCPU);
bool cumplirDosRondasGanadasConsecutivasHumano(int cartaHumano,int cartaCPU);
bool cumplirDosRondasGanadasConsecutivasCPU(int cartaHumano,int cartaCPU);
bool ganarCartaNieveHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarCartaNieveCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarCartaFuegoHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarCartaFuegoCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarCartaAguaHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarCartaAguaCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarDosCartasRojasHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarDosCartasRojasCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarDosCartasAmarillasHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarDosCartasAmarillasCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarDosCartasVerdesHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarDosCartasVerdesCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarDosCartasAzulesHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarDosCartasAzulesCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarMismoElementoHumano(int cartaHumano, int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarMismoElementoCPU(int cartaHumano, int cartaCPU,int cartaDesafioCPU,int ronda);
bool ganarDosCartasMismoNumeroHumano(int cartaHumano, int cartaCPU, int cartaDesafioHumano, int ronda,int cartasGanadasHumanoDesafio9[]);
bool ganarDosCartasMismoNumeroCPU(int cartaHumano, int cartaCPU, int cartaDesafioCPU, int ronda,int cartasGanadasCPUDesafio9[]);
bool ganarDosRondasConsecutivasHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda);
bool ganarDosRondasConsecutivasCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda);
bool combinacionGanadoraHumanoCumplida(int mazoHumano[]);
bool combinacionGanadoraCPUCumplida(int mazoCPU[]);
#endif // DESAFIOS_H_INCLUDED
