#include <iostream>
#include "colores.h"
using namespace std;
using namespace rlutil;

int cartaDesafio(){
    //FUNCIÓN UTILIZADA PARA DARLE UNA CARTA DESAFÍO A HUMANO Y CPU
    int h;
    return h=rand()%10+1;
    }

string detalleCartaDesafio(int h){
    //FUNCIÓN QUE DESCRIBE CUÁL ES EL OBJETIVO DE CADA CARTA DESAFÍO

    switch(h){
        case 1:return "GANAR UNA CARTA DE NIEVE";
        break;
        case 2: return "GANAR UNA CARTA DE FUEGO";
        break;
        case 3: return "GANAR UNA CARTA DE AGUA";
        break;
        case 4: return "GANAR DOS CARTAS ROJAS";
        break;
        case 5: return "GANAR DOS CARTAS AMARILLAS";
        break;
        case 6: return "GANAR DOS CARTAS VERDES";
        break;
        case 7: return "GANAR DOS CARTAS AZULES";
        break;
        case 8: return "GANAR UNA CARTA CON EL MISMO ELEMENTO QUE EL ADVERSARIO";
        break;
        case 9: return "GANAR DOS CARTAS CON EL MISMO NÚMERO";
        break;
        case 10:return "GANAR DOS RONDAS DE MANERA CONSECUTIVA";
        break;
        }
}

bool ganarCartaNieveHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
//FUNCIÓN QUE DETERMINA SI EL USUARIO GANÓ UNA CARTA DE NIEVE
//PARA ESO, DETERMINAMOS SI LA CARTA DEL USUARIO ES DE FUEGO O NIEVE (NIEVE DE NÚMERO ESPECÍFICO PUEDE GANAR)
//LO IMPORTANTE ES QUE LA CARTA DE LA CPU SÍ O SÍ DEBE SER DE NIEVE
//LOS STRING DE CLON NO SON NECESARIOS, PERO SE COLOCARON PARA QUE SEA DE FÁCIL INTERPRETACIÓN PARA EL LECTOR
int x,numeroCartaHumano,numeroCartaCPU;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
bool desafioCumplidoHumano=false;
string clonCartaHumano,clonCartaCPU;

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}
    }
    for(x=0;x<20;x++){
        if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(x==20&&clonCartaCPU!="NIEVE"){
        return false;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="NIEVE"){
        return true;
    }else if(clonCartaHumano=="NIEVE"&&clonCartaCPU=="NIEVE"){
        if(numeroCartaHumano>numeroCartaCPU){
            return true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2==0){
        return true;}else{return false;}
    }{return false;}
}


bool ganarCartaFuegoHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
//FUNCIÓN CON MISMO ENGRANAJE QUE LA ANTERIOR, SÓLO QUE CAMBIAMOS "GANAR NIEVE" POR "GANAR FUEGO"
int x,numeroCartaHumano,numeroCartaCPU;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
bool desafioCumplidoHumano=false;
string clonCartaHumano,clonCartaCPU;

    for(x=0;x<20;x++){
        if(vAgua[x]==cartaHumano){
            clonCartaHumano="AGUA";
            x=20;
        }else if(vFuego[x]==cartaHumano){
        clonCartaHumano="FUEGO";
        x=20;}
    }
    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(x==20&&clonCartaCPU!="FUEGO"){
        return false;}
    }

    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="AGUA"&&clonCartaCPU=="FUEGO"){
        return true;
    }else if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="FUEGO"){
        if(numeroCartaHumano>numeroCartaCPU){
            return true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2==0){
        return true;}else{return false;}
    }{return false;}

}

bool ganarCartaAguaHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
int x,numeroCartaHumano,numeroCartaCPU;
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
bool desafioCumplidoHumano=false;
string clonCartaHumano,clonCartaCPU;

    for(x=0;x<20;x++){
        if(vNieve[x]==cartaHumano){
            clonCartaHumano="NIEVE";
            x=20;
        }else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }
    for(x=0;x<20;x++){
        if(vAgua[x]==cartaCPU){
            clonCartaCPU="AGUA";
            x=20;
        }else if(x==20&&clonCartaCPU!="AGUA"){
        return false;}
    }

    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="NIEVE"&&clonCartaCPU=="AGUA"){
        return true;
    }else if(clonCartaHumano=="AGUA"&&clonCartaCPU=="AGUA"){
        if(numeroCartaHumano>numeroCartaCPU){
            return true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2==0){
        return true;}else{return false;}
    }{return false;}
}

bool ganarDosCartasRojasHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
//FUNCIÓN QUE UTILIZA UN CONTADOR PARA DETERMINAR SI SE GANARON DOS CARTAS ROJAS
//PARA DETERMINAR SI LA CARTA GANADA ES ROJA, SE UTILIZA UN VECTOR (VROJO)
//COMPARTE ESTRUCTURA Y FIN CON GANARCARTAAZUL,GANARCARTAAMARILLA Y GANARCARTAVERDE
int x;
int vRojo[15]={1,2,3,4,5,21,22,23,24,25,41,42,43,44,45};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaCPU;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vRojo[x]==cartaCPU){
            colorCartaCPU="ROJO";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="NIEVE"&&colorCartaCPU=="ROJO"||clonCartaHumano=="NIEVE"&&clonCartaCPU=="AGUA"&&colorCartaCPU=="ROJO"||clonCartaHumano=="AGUA"&&clonCartaCPU=="FUEGO"&&colorCartaCPU=="ROJO"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaCPU=="ROJO"){
    if(numeroCartaHumano>numeroCartaCPU&&colorCartaCPU=="ROJO"||numeroCartaHumano==numeroCartaCPU&&ronda%2==0&&colorCartaCPU=="ROJO"){
        return true;
    }else{return false;}
        }return false;
}

bool ganarDosCartasAmarillasHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
int x;
int vAmarillo[15]={6,7,8,9,10,26,27,28,29,30,46,47,48,49,50};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaCPU;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vAmarillo[x]==cartaCPU){
            colorCartaCPU="AMARILLO";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="NIEVE"&&colorCartaCPU=="AMARILLO"||clonCartaHumano=="NIEVE"&&clonCartaCPU=="AGUA"&&colorCartaCPU=="AMARILLO"||clonCartaHumano=="AGUA"&&clonCartaCPU=="FUEGO"&&colorCartaCPU=="AMARILLO"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaCPU=="AMARILLO"){
    if(numeroCartaHumano>numeroCartaCPU&&colorCartaCPU=="AMARILLO"||numeroCartaHumano==numeroCartaCPU&&ronda%2==0&&colorCartaCPU=="AMARILLO"){
        return true;
    }else{return false;}
        }return false;

}

bool ganarDosCartasVerdesHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
int x;
int vVerde[15]={11,12,13,14,15,31,32,33,34,35,51,52,53,54,55};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaCPU;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vVerde[x]==cartaCPU){
            colorCartaCPU="VERDE";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="NIEVE"&&colorCartaCPU=="VERDE"||clonCartaHumano=="NIEVE"&&clonCartaCPU=="AGUA"&&colorCartaCPU=="VERDE"||clonCartaHumano=="AGUA"&&clonCartaCPU=="FUEGO"&&colorCartaCPU=="VERDE"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaCPU=="VERDE"){
    if(numeroCartaHumano>numeroCartaCPU&&colorCartaCPU=="VERDE"||numeroCartaHumano==numeroCartaCPU&&ronda%2==0&&colorCartaCPU=="VERDE"){
        return true;
    }else{return false;}
        }return false;
}

bool ganarDosCartasAzulesHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
int x;
int vAzules[15]={16,17,18,19,20,36,37,38,39,40,56,57,58,59,60};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaCPU;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vAzules[x]==cartaCPU){
            colorCartaCPU="AZUL";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="NIEVE"&&colorCartaCPU=="AZUL"||clonCartaHumano=="NIEVE"&&clonCartaCPU=="AGUA"&&colorCartaCPU=="AZUL"||clonCartaHumano=="AGUA"&&clonCartaCPU=="FUEGO"&&colorCartaCPU=="AZUL"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaCPU=="AZUL"){
    if(numeroCartaHumano>numeroCartaCPU&&colorCartaCPU=="AZUL"||numeroCartaHumano==numeroCartaCPU&&ronda%2==0&&colorCartaCPU=="AZUL"){
        return true;
    }else{return false;}
        }return false;
}
bool ganarMismoElementoHumano(int cartaHumano, int cartaCPU,int cartaDesafioHumano,int ronda){
    //FUNCIÓN QUE COMPARTE CIERTAS CARACTERÍSTICAS QUE LAS ANTERIORES, SÓLO QUE CONFIRMAMOS QUE LAS CARTAS TIRADAS SON DE UN MISMO ELEMENTO
    //SI LA FUNCIÓN DETECTA QUE NO SON DE MISMO ELEMENTO, RETORNARÁ AL MAIN Y CONTINUARÁ EL JUEGO
int x;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
int numeroCartaHumano,numeroCartaCPU;

     for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano==clonCartaCPU){
        if(numeroCartaHumano>numeroCartaCPU||numeroCartaHumano==numeroCartaCPU&&ronda%2==0){
            return true;
        }else{return false;}
    }else{return false;}
}

bool ganarDosCartasMismoNumeroHumano(int cartaHumano, int cartaCPU, int cartaDesafioHumano, int ronda,int cartasGanadasHumanoDesafio9[]){
    //SIMILAR A LA ANTERIOR, SÓLO QUE TENIENDO EN CUENTA EL NÚMERO
    //SE UTILIZAN CINCO VECTORES (POR LOS CINCO NÚMEROS DEL 1 AL 5) PARA DETERMINAR SI LA CARTA GANADA ES DE UN NÚMERO ESPECÍFICO O NO

int x,j;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaCPU;
int numeroCartaHumano,numeroCartaCPU;
bool manoGanadaPorHumano=false;
int cartaAEvaluar;
bool dosCartasIguales=false;

for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="NIEVE"||clonCartaHumano=="NIEVE"&&clonCartaCPU=="AGUA"||clonCartaHumano=="AGUA"&&clonCartaCPU=="FUEGO"){
        manoGanadaPorHumano=true;
    }else if(clonCartaHumano==clonCartaCPU&&numeroCartaHumano>numeroCartaCPU){
            manoGanadaPorHumano=true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2==0){
        manoGanadaPorHumano=true;}else{return false;}

        if(manoGanadaPorHumano==true){
            for(x=0;x<60;x++){
                if(cartasGanadasHumanoDesafio9[x]==0){
                    cartasGanadasHumanoDesafio9[x]=numeroCartaCPU;
                    x=60;
                }
            }
        }else{return false;}

       for(x=0;x<60;x++){
        if(cartasGanadasHumanoDesafio9[x]!=0){
            cartaAEvaluar=cartasGanadasHumanoDesafio9[x];
        }else{x=60;}
        for(j=0;j<60;j++){
            if(cartaAEvaluar==cartasGanadasHumanoDesafio9[x+1]){
                dosCartasIguales=true;
                j=60;
                x=60;
                }
            }
        }

    if(dosCartasIguales==true){
        return true;
    }else{return false;}

    }


bool ganarDosRondasConsecutivasHumano(int cartaHumano,int cartaCPU,int cartaDesafioHumano,int ronda){
    //FUNCIÓN BÁSICA QUE UTILIZA UN CONTADOR QUE AL LLEGAR A 2 PASA EL DESAFÍO A TRUE
    //EN CASO DE PERDER UNA RONDA EN EL MEDIO, EL CONTADOR (QUE FIGURA EN EL MAIN) VOLVERÁ A 0
int x;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaCPU;
int numeroCartaHumano,numeroCartaCPU;
bool manoGanadaPorHumano=false;


for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano=="FUEGO"&&clonCartaCPU=="NIEVE"||clonCartaHumano=="NIEVE"&&clonCartaCPU=="AGUA"||clonCartaHumano=="AGUA"&&clonCartaCPU=="FUEGO"){
        manoGanadaPorHumano=true;
    }else if(clonCartaHumano==clonCartaCPU&&numeroCartaHumano>numeroCartaCPU){
            manoGanadaPorHumano=true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2==0){
        manoGanadaPorHumano=true;}else{return false;}

    if(manoGanadaPorHumano==true){
        return true;
    }else{return false;}

}

bool combinacionGanadoraHumanoCumplida(int mazoHumano[]){
    //FUNCIÓN QUE EVALÚA EL MAZO DEL HUMANO PARA VER SI TIENE ALGUNA DE LAS DOS POSIBLES COMBINACIONES GANADORAS
    //SI DETECTA UNA COMBINACIÓN GANADORA, PASARÁ ESE BOOLEANO EN MAIN A TRUE
    //COMBINACIONES GANADORAS PUEDEN SER:
    //TENER TRES CARTAS DE UN MISMO ELEMENTO
    //TENER TRES CARTAS DE DISTINTO ELEMENTO Y COLOR
int x,j,z;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int contadorFuego=0,contadorNieve=0,contadorAgua=0;
bool combinacionLograda=false;
int vRojo[15]={1,2,3,4,5,21,22,23,24,25,41,42,43,44,45};
int vAmarillo[15]={6,7,8,9,10,26,27,28,29,30,46,47,48,49,50};
int vVerde[15]={11,12,13,14,15,31,32,33,34,35,51,52,53,54,55};
int vAzules[15]={16,17,18,19,20,36,37,38,39,40,56,57,58,59,60};
int fuegoRojo=0,fuegoAmarillo=0,fuegoVerde=0,fuegoAzul=0;
int nieveRojo=0,nieveAmarillo=0,nieveVerde=0,nieveAzul=0;
int aguaRojo=0,aguaAmarillo=0,aguaVerde=0,aguaAzul=0;
bool elementoYColor[12]={};
string nombreColor[12]={"ROJO","AMARILLO","VERDE","AZUL","ROJO","AMARILLO","VERDE","AZUL","ROJO","AMARILLO","VERDE","AZUL"};


    //EVALUAMOS CUANTAS DE CADA ELEMENTO HAY
    for(x=0;x<60;x++){
        for(j=0;j<20;j++){
            if(mazoHumano[x]==vFuego[j]){
                contadorFuego++;
            }else if(mazoHumano[x]==vNieve[j]){
            contadorNieve++;}else if(mazoHumano[x]==vAgua[j]){
        contadorAgua++;}
        }
    }

    if(contadorFuego>=3||contadorNieve>=3||contadorAgua>=3){
        combinacionLograda=true;
    }

    //EVALUAR FUEGO Y COLOR
    for(x=0;x<60;x++){
       for(j=0;j<20;j++){
         for(z=0;z<15;z++){
            if(mazoHumano[x]==vFuego[j]&&mazoHumano[x]==vRojo[z]){
                fuegoRojo++;
            }else if(mazoHumano[x]==vFuego[j]&&mazoHumano[x]==vAmarillo[z]){
            fuegoAmarillo++;}else if(
            mazoHumano[x]==vFuego[j]&&mazoHumano[x]==vVerde[z]){
            fuegoVerde++;}else if(mazoHumano[x]==vFuego[j]&&mazoHumano[x]==vAzules[z]){
         fuegoAzul++;}
       }
    }

}

    //EVALUAR NIEVE Y COLOR
    for(x=0;x<60;x++){
       for(j=0;j<20;j++){
         for(z=0;z<15;z++){
            if(mazoHumano[x]==vNieve[j]&&mazoHumano[x]==vRojo[z]){
                nieveRojo++;
            }else if(mazoHumano[x]==vNieve[j]&&mazoHumano[x]==vAmarillo[z]){
            nieveAmarillo++;}else if(
            mazoHumano[x]==vNieve[j]&&mazoHumano[x]==vVerde[z]){
            nieveVerde++;}else if(mazoHumano[x]==vNieve[j]&&mazoHumano[x]==vAzules[z]){
         nieveAzul++;}
       }
    }

}

    //EVALUAR AGUA Y COLOR
     for(x=0;x<60;x++){
       for(j=0;j<20;j++){
         for(z=0;z<15;z++){
            if(mazoHumano[x]==vAgua[j]&&mazoHumano[x]==vRojo[z]){
                aguaRojo++;
            }else if(mazoHumano[x]==vAgua[j]&&mazoHumano[x]==vAmarillo[z]){
            aguaAmarillo++;}else if(
            mazoHumano[x]==vAgua[j]&&mazoHumano[x]==vVerde[z]){
            aguaVerde++;} else if(mazoHumano[x]==vAgua[j]&&mazoHumano[x]==vAzules[z]){
         aguaAzul++;}
       }
    }

}

    //COMBINACIONES
    for(x=0;x<12;x++){
        elementoYColor[x]=false;
    }

    for(x=0;x<12;x++){
        if(fuegoRojo!=0){
            elementoYColor[0]=true;
        }
        if(fuegoAmarillo!=0){
        elementoYColor[1]=true;}
        if(fuegoVerde!=0){
        elementoYColor[2]=true;}
        if(fuegoAzul!=0){
        elementoYColor[3]=true;}
    }
    //EVALUAMOS QUE CARTAS DE NIEVE TENEMOS
    for(x=0;x<12;x++){
        if(nieveRojo!=0){
            elementoYColor[4]=true;
        }
        if(nieveAmarillo!=0){
        elementoYColor[5]=true;}
        if(nieveVerde!=0){
        elementoYColor[6]=true;}
        if(nieveAzul!=0){
        elementoYColor[7]=true;}
    }

    //EVALUAMOS QUE CARTAS DE AGUA TENEMOS
    for(x=0;x<12;x++){
        if(aguaRojo!=0){
            elementoYColor[8]=true;
        }
        if(aguaAmarillo!=0){
        elementoYColor[9]=true;}
        if(aguaVerde!=0){
        elementoYColor[10]=true;}
        if(aguaAzul!=0){
        elementoYColor[11]=true;}
    }

   //COMBINACIONES FUEGO ROJO
   if(fuegoRojo!=0){
        if(nieveAmarillo!=0){
            if(aguaAzul!=0||aguaVerde!=0){
                combinacionLograda=true;
            }
        }else if(nieveAzul!=0){
        if(aguaAmarillo!=0||aguaVerde!=0){
            combinacionLograda=true;
            }
        }else if(nieveVerde!=0){
        if(aguaAmarillo!=0||aguaAzul!=0){
            combinacionLograda=true;
            }
        }
   }

   //COMBINACIONES FUEGO AMARILLO
   if(fuegoAmarillo!=0){
        if(nieveRojo!=0){
            if(aguaAzul!=0||aguaVerde!=0){
                combinacionLograda=true;
            }
        }else if(nieveAzul!=0){
        if(aguaRojo!=0||aguaVerde!=0){
            combinacionLograda=true;
            }
        }else if(nieveVerde!=0){
        if(aguaRojo!=0||aguaAzul!=0){
            combinacionLograda=true;
                }
            }
        }

   //COMBINACIONES FUEGO VERDE
   if(fuegoVerde!=0){
        if(nieveRojo!=0){
            if(aguaAzul!=0||aguaAmarillo!=0){
                combinacionLograda=true;
            }
        }else if(nieveAzul!=0){
        if(aguaRojo!=0||aguaAmarillo!=0){
            combinacionLograda=true;
            }
        }else if(nieveAmarillo!=0){
        if(aguaRojo!=0||aguaAzul!=0){
            combinacionLograda=true;
                }
            }
        }

   //COMBINACIONES FUEGO AZUL
   if(fuegoAzul!=0){
        if(nieveRojo!=0){
            if(aguaVerde!=0||aguaAmarillo!=0){
                combinacionLograda=true;
            }
        }else if(nieveVerde!=0){
        if(aguaRojo!=0||aguaAmarillo!=0){
            combinacionLograda=true;
            }
        }else if(nieveAmarillo!=0){
        if(aguaRojo!=0||aguaVerde!=0){
            combinacionLograda=true;
                }
            }
        }


    if(combinacionLograda==true){
        return true;
    }else{return false;}
}

//A PARTIR DE ACÁ SON LAS MISMAS FUNCIONES QUE LAS ANTERIORES, SÓLO QUE LAS APLICAMOS PARA LA CPU
bool ganarCartaNieveCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda){
int x,numeroCartaHumano,numeroCartaCPU;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
bool desafioCumplidoCPU=false;
string clonCartaHumano,clonCartaCPU;

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}
    }
    for(x=0;x<20;x++){
        if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(x==20&&clonCartaHumano!="NIEVE"){
        return false;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="NIEVE"){
        return true;
    }else if(clonCartaCPU=="NIEVE"&&clonCartaHumano=="NIEVE"){
        if(numeroCartaCPU>numeroCartaHumano){
            return true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2!=0){
        return true;}else{return false;}
    }{return false;}
}

bool ganarCartaFuegoCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda){
int x,numeroCartaHumano,numeroCartaCPU;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
bool desafioCumplidoCPU=false;
string clonCartaHumano,clonCartaCPU;

    for(x=0;x<20;x++){
        if(vAgua[x]==cartaCPU){
            clonCartaCPU="AGUA";
            x=20;
        }else if(vFuego[x]==cartaCPU){
        clonCartaCPU="FUEGO";
        x=20;}
    }
    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(x==20&&clonCartaHumano!="FUEGO"){
        return false;}
    }

    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="AGUA"&&clonCartaHumano=="FUEGO"){
        return true;
    }else if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="FUEGO"){
        if(numeroCartaCPU>numeroCartaHumano){
            return true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2!=0){
        return true;}else{return false;}
    }{return false;}
}



bool ganarCartaAguaCPU(int cartaHumano,int cartaCPU,int c,int ronda){
int x,numeroCartaHumano,numeroCartaCPU;
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
bool desafioCumplidoCPU=false;
string clonCartaHumano,clonCartaCPU;

    for(x=0;x<20;x++){
        if(vNieve[x]==cartaCPU){
            clonCartaCPU="NIEVE";
            x=20;
        }else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<20;x++){
        if(vAgua[x]==cartaHumano){
            clonCartaHumano="AGUA";
            x=20;
        }else if(x==20&&clonCartaHumano!="AGUA"){
        return false;}
    }

    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="NIEVE"&&clonCartaHumano=="AGUA"){
        return true;
    }else if(clonCartaCPU=="AGUA"&&clonCartaHumano=="AGUA"){
        if(numeroCartaCPU>numeroCartaHumano){
            return true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2!=0){
        return true;}else{return false;}
    }{return false;}
}

bool ganarDosCartasRojasCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda){
int x;
int vRojo[15]={1,2,3,4,5,21,22,23,24,25,41,42,43,44,45};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaHumano;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vRojo[x]==cartaHumano){
            colorCartaHumano="ROJO";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="NIEVE"&&colorCartaHumano=="ROJO"||clonCartaCPU=="NIEVE"&&clonCartaHumano=="AGUA"&&colorCartaHumano=="ROJO"||clonCartaCPU=="AGUA"&&clonCartaHumano=="FUEGO"&&colorCartaHumano=="ROJO"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaHumano=="ROJO"){
    if(numeroCartaCPU>numeroCartaHumano&&colorCartaHumano=="ROJO"||numeroCartaHumano==numeroCartaCPU&&ronda%2!=0&&colorCartaHumano=="ROJO"){
        return true;
    }else{return false;}
        }return false;
}

bool ganarDosCartasAmarillasCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda){
int x;
int vAmarillo[15]={6,7,8,9,10,26,27,28,29,30,46,47,48,49,50};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaHumano;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vAmarillo[x]==cartaHumano){
            colorCartaHumano="AMARILLO";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="NIEVE"&&colorCartaHumano=="AMARILLO"||clonCartaCPU=="NIEVE"&&clonCartaHumano=="AGUA"&&colorCartaHumano=="AMARILLO"||clonCartaCPU=="AGUA"&&clonCartaHumano=="FUEGO"&&colorCartaHumano=="AMARILLO"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaHumano=="AMARILLO"){
    if(numeroCartaCPU>numeroCartaHumano&&colorCartaHumano=="AMARILLO"||numeroCartaHumano==numeroCartaCPU&&ronda%2!=0&&colorCartaHumano=="AMARILLO"){
        return true;
    }else{return false;}
        }return false;
}

bool ganarDosCartasVerdesCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda){
int x;
int vVerde[15]={11,12,13,14,15,31,32,33,34,35,51,52,53,54,55};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaHumano;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vVerde[x]==cartaHumano){
            colorCartaHumano="VERDE";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="NIEVE"&&colorCartaHumano=="VERDE"||clonCartaCPU=="NIEVE"&&clonCartaHumano=="AGUA"&&colorCartaHumano=="VERDE"||clonCartaCPU=="AGUA"&&clonCartaHumano=="FUEGO"&&colorCartaHumano=="VERDE"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaHumano=="VERDE"){
    if(numeroCartaCPU>numeroCartaHumano&&colorCartaHumano=="VERDE"||numeroCartaHumano==numeroCartaCPU&&ronda%2!=0&&colorCartaHumano=="VERDE"){
        return true;
    }else{return false;}
        }return false;
}

bool ganarDosCartasAzulesCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda){
int x;
int vAzules[15]={16,17,18,19,20,36,37,38,39,40,56,57,58,59,60};
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaHumano;
int numeroCartaHumano,numeroCartaCPU;

    for(x=0;x<15;x++){
        if(vAzules[x]==cartaHumano){
            colorCartaHumano="AZUL";
            x=15;
        }
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="NIEVE"&&colorCartaHumano=="AZUL"||clonCartaCPU=="NIEVE"&&clonCartaHumano=="AGUA"&&colorCartaHumano=="AZUL"||clonCartaCPU=="AGUA"&&clonCartaHumano=="FUEGO"&&colorCartaHumano=="AZUL"){
        return true;
    }else if(clonCartaHumano==clonCartaCPU&&colorCartaHumano=="AZUL"){
    if(numeroCartaCPU>numeroCartaHumano&&colorCartaHumano=="AZUL"||numeroCartaHumano==numeroCartaCPU&&ronda%2!=0&&colorCartaHumano=="AZUL"){
        return true;
    }else{return false;}
        }return false;
}

bool ganarMismoElementoCPU(int cartaHumano, int cartaCPU,int cartaDesafioCPU,int ronda){
int x;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
int numeroCartaHumano,numeroCartaCPU;

     for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaHumano==clonCartaCPU){
        if(numeroCartaCPU>numeroCartaHumano||numeroCartaHumano==numeroCartaCPU&&ronda%2!=0){
            return true;
        }else{return false;}
    }else{return false;}

}

bool ganarDosCartasMismoNumeroCPU(int cartaHumano, int cartaCPU, int cartaDesafioCPU, int ronda,int cartasGanadasCPUDesafio9[]){
int x,j;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaCPU;
int numeroCartaHumano,numeroCartaCPU;
bool manoGanadaPorCPU=false;
int cartaAEvaluar;
bool dosCartasIguales=false;

for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="NIEVE"||clonCartaCPU=="NIEVE"&&clonCartaHumano=="AGUA"||clonCartaCPU=="AGUA"&&clonCartaHumano=="FUEGO"){
        manoGanadaPorCPU=true;
    }else if(clonCartaHumano==clonCartaCPU&&numeroCartaCPU>numeroCartaHumano){
            manoGanadaPorCPU=true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2!=0){
        manoGanadaPorCPU=true;}else{return false;}

        if(manoGanadaPorCPU==true){
            for(x=0;x<60;x++){
                if(cartasGanadasCPUDesafio9[x]==0){
                    cartasGanadasCPUDesafio9[x]=numeroCartaHumano;
                    x=60;
                }
            }
        }else{return false;}

       for(x=0;x<60;x++){
        if(cartasGanadasCPUDesafio9[x]!=0){
            cartaAEvaluar=cartasGanadasCPUDesafio9[x];
        }else{x=60;}
        for(j=0;j<60;j++){
            if(cartaAEvaluar==cartasGanadasCPUDesafio9[x+1]){
                dosCartasIguales=true;
                j=60;
                x=60;
                }
            }
        }
    if(dosCartasIguales==true){
        return true;
    }else{return false;}
}

bool ganarDosRondasConsecutivasCPU(int cartaHumano,int cartaCPU,int cartaDesafioCPU,int ronda){
int x;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
string clonCartaHumano,clonCartaCPU;
string colorCartaHumano;
int numeroCartaHumano,numeroCartaCPU;
bool manoGanadaPorCPU=false;


for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            clonCartaHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        clonCartaHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        clonCartaHumano="AGUA";
        x=20;}
    }

    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            clonCartaCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        clonCartaCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        clonCartaCPU="AGUA";
        x=20;}
    }
    for(x=0;x<12;x++){
        if(Vuno[x]==cartaHumano){
            numeroCartaHumano=1;
            x=12;
        }else if(Vdos[x]==cartaHumano){
        numeroCartaHumano=2;
        x=12;}else if(Vtres[x]==cartaHumano){
        numeroCartaHumano=3;
        x=12;}else if(Vcuatro[x]==cartaHumano){
        numeroCartaHumano=4;
        x=12;}else if(Vcinco[x]==cartaHumano){
        numeroCartaHumano=5;
        x=12;}
    }
      for(x=0;x<12;x++){
        if(Vuno[x]==cartaCPU){
            numeroCartaCPU=1;
            x=12;
        }else if(Vdos[x]==cartaCPU){
        numeroCartaCPU=2;
        x=12;}else if(Vtres[x]==cartaCPU){
        numeroCartaCPU=3;
        x=12;}else if(Vcuatro[x]==cartaCPU){
        numeroCartaCPU=4;
        x=12;}else if(Vcinco[x]==cartaCPU){
        numeroCartaCPU=5;
        x=12;}
    }

    if(clonCartaCPU=="FUEGO"&&clonCartaHumano=="NIEVE"||clonCartaCPU=="NIEVE"&&clonCartaHumano=="AGUA"||clonCartaCPU=="AGUA"&&clonCartaHumano=="FUEGO"){
        manoGanadaPorCPU=true;
    }else if(clonCartaCPU==clonCartaHumano&&numeroCartaCPU>numeroCartaHumano){
            manoGanadaPorCPU=true;
        }else if(numeroCartaHumano==numeroCartaCPU&&ronda%2!=0){
        manoGanadaPorCPU=true;}else{return false;}

    if(manoGanadaPorCPU==true){
        return true;
    }else{return false;}
}

bool combinacionGanadoraCPUCumplida(int mazoCPU[]){
int x,j,z;
int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int contadorFuego=0,contadorNieve=0,contadorAgua=0;
bool combinacionLograda=false;
int vRojo[15]={1,2,3,4,5,21,22,23,24,25,41,42,43,44,45};
int vAmarillo[15]={6,7,8,9,10,26,27,28,29,30,46,47,48,49,50};
int vVerde[15]={11,12,13,14,15,31,32,33,34,35,51,52,53,54,55};
int vAzules[15]={16,17,18,19,20,36,37,38,39,40,56,57,58,59,60};
int fuegoRojo=0,fuegoAmarillo=0,fuegoVerde=0,fuegoAzul=0;
int nieveRojo=0,nieveAmarillo=0,nieveVerde=0,nieveAzul=0;
int aguaRojo=0,aguaAmarillo=0,aguaVerde=0,aguaAzul=0;
bool elementoYColor[12]={};
string nombreColor[12]={"ROJO","AMARILLO","VERDE","AZUL","ROJO","AMARILLO","VERDE","AZUL","ROJO","AMARILLO","VERDE","AZUL"};


    //EVALUAMOS CUANTAS DE CADA ELEMENTO HAY
    for(x=0;x<60;x++){
        for(j=0;j<20;j++){
            if(mazoCPU[x]==vFuego[j]){
                contadorFuego++;
            }else if(mazoCPU[x]==vNieve[j]){
            contadorNieve++;}else if(mazoCPU[x]==vAgua[j]){
        contadorAgua++;}
        }
    }

    if(contadorFuego>=3||contadorNieve>=3||contadorAgua>=3){
        combinacionLograda=true;
    }

    //EVALUAR FUEGO Y COLOR
    for(x=0;x<60;x++){
       for(j=0;j<20;j++){
         for(z=0;z<15;z++){
            if(mazoCPU[x]==vFuego[j]&&mazoCPU[x]==vRojo[z]){
                fuegoRojo++;
            }else if(mazoCPU[x]==vFuego[j]&&mazoCPU[x]==vAmarillo[z]){
            fuegoAmarillo++;}else if(
            mazoCPU[x]==vFuego[j]&&mazoCPU[x]==vVerde[z]){
            fuegoVerde++;}else if(mazoCPU[x]==vFuego[j]&&mazoCPU[x]==vAzules[z]){
         fuegoAzul++;}
       }
    }

}

    //EVALUAR NIEVE Y COLOR
    for(x=0;x<60;x++){
       for(j=0;j<20;j++){
         for(z=0;z<15;z++){
            if(mazoCPU[x]==vNieve[j]&&mazoCPU[x]==vRojo[z]){
                nieveRojo++;
            }else if(mazoCPU[x]==vNieve[j]&&mazoCPU[x]==vAmarillo[z]){
            nieveAmarillo++;}else if(
            mazoCPU[x]==vNieve[j]&&mazoCPU[x]==vVerde[z]){
            nieveVerde++;}else if(mazoCPU[x]==vNieve[j]&&mazoCPU[x]==vAzules[z]){
         nieveAzul++;}
       }
    }

}

    //EVALUAR AGUA Y COLOR
     for(x=0;x<60;x++){
       for(j=0;j<20;j++){
         for(z=0;z<15;z++){
            if(mazoCPU[x]==vAgua[j]&&mazoCPU[x]==vRojo[z]){
                aguaRojo++;
            }else if(mazoCPU[x]==vAgua[j]&&mazoCPU[x]==vAmarillo[z]){
            aguaAmarillo++;}else if(
            mazoCPU[x]==vAgua[j]&&mazoCPU[x]==vVerde[z]){
            aguaVerde++;} else if(mazoCPU[x]==vAgua[j]&&mazoCPU[x]==vAzules[z]){
         aguaAzul++;}
       }
    }

}

    //COMBINACIONES
    for(x=0;x<12;x++){
        elementoYColor[x]=false;
    }
    //EVALUAMOS QUE CARTAS DE FUEGO TENEMOS.
    for(x=0;x<12;x++){
        if(fuegoRojo!=0){
            elementoYColor[0]=true;
        }
        if(fuegoAmarillo!=0){
        elementoYColor[1]=true;}
        if(fuegoVerde!=0){
        elementoYColor[2]=true;}
        if(fuegoAzul!=0){
        elementoYColor[3]=true;}
    }
    //EVALUAMOS QUE CARTAS DE NIEVE TENEMOS
    for(x=0;x<12;x++){
        if(nieveRojo!=0){
            elementoYColor[4]=true;
        }
        if(nieveAmarillo!=0){
        elementoYColor[5]=true;}
        if(nieveVerde!=0){
        elementoYColor[6]=true;}
        if(nieveAzul!=0){
        elementoYColor[7]=true;}
    }

    //EVALUAMOS QUE CARTAS DE AGUA TENEMOS
    for(x=0;x<12;x++){
        if(aguaRojo!=0){
            elementoYColor[8]=true;
        }
        if(aguaAmarillo!=0){
        elementoYColor[9]=true;}
        if(aguaVerde!=0){
        elementoYColor[10]=true;}
        if(aguaAzul!=0){
        elementoYColor[11]=true;}
    }

      //COMBINACIONES FUEGO ROJO
   if(fuegoRojo!=0){
        if(nieveAmarillo!=0){
            if(aguaAzul!=0||aguaVerde!=0){
                combinacionLograda=true;
            }
        }else if(nieveAzul!=0){
        if(aguaAmarillo!=0||aguaVerde!=0){
            combinacionLograda=true;
            }
        }else if(nieveVerde!=0){
        if(aguaAmarillo!=0||aguaAzul!=0){
            combinacionLograda=true;
            }
        }
   }

   //COMBINACIONES FUEGO AMARILLO
   if(fuegoAmarillo!=0){
        if(nieveRojo!=0){
            if(aguaAzul!=0||aguaVerde!=0){
                combinacionLograda=true;
            }
        }else if(nieveAzul!=0){
        if(aguaRojo!=0||aguaVerde!=0){
            combinacionLograda=true;
            }
        }else if(nieveVerde!=0){
        if(aguaRojo!=0||aguaAzul!=0){
            combinacionLograda=true;
                }
            }
        }

   //COMBINACIONES FUEGO VERDE
   if(fuegoVerde!=0){
        if(nieveRojo!=0){
            if(aguaAzul!=0||aguaAmarillo!=0){
                combinacionLograda=true;
            }
        }else if(nieveAzul!=0){
        if(aguaRojo!=0||aguaAmarillo!=0){
            combinacionLograda=true;
            }
        }else if(nieveAmarillo!=0){
        if(aguaRojo!=0||aguaAzul!=0){
            combinacionLograda=true;
                }
            }
        }

   //COMBINACIONES FUEGO AZUL
   if(fuegoAzul!=0){
        if(nieveRojo!=0){
            if(aguaVerde!=0||aguaAmarillo!=0){
                combinacionLograda=true;
            }
        }else if(nieveVerde!=0){
        if(aguaRojo!=0||aguaAmarillo!=0){
            combinacionLograda=true;
            }
        }else if(nieveAmarillo!=0){
        if(aguaRojo!=0||aguaVerde!=0){
            combinacionLograda=true;
                }
            }
        }
    if(combinacionLograda==true){
        return true;
    }else{return false;}
}








