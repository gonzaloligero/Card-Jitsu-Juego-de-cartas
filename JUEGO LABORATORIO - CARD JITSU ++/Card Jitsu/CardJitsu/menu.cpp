#include <iostream>

using namespace std;

//IMPLEMENTACION FUNCIONES MENU

#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "colores.h"
#include <cstdio>
using namespace rlutil;
using namespace std;


void mostrarMenu(){
saveDefaultColor();

//SAVEDEFAULTCOLOR GUARDA EL COLOR BÁSICO DE CONSOLA HASTA EL MOMENTO (NEGRO)
//LOCATE SIRVE PARA COLOCAR EN UN ESPACIO ESPECIFICO DE PANTALLA
//SETCOLOR DETERMINA EL COLOR DE LOS CARACTERES


locate(25,1);
setColor(YELLOW);
cout<<"      =========================================================  "<<endl;
locate(25,2);
setColor(LIGHTRED);
cout<<"       #### ##### ####  ####     #####  #  #####   ####   #  #   "<<endl;
locate(25,3);
setColor(LIGHTRED);
cout<<"       #### ##### ####  ####     #####     #####   ####   #  #   "<<endl;
locate(25,4);
setColor(LIGHTRED);
cout<<"       #    #   # ##  # #   #      #    #    #     #      #  #   "<<endl;
locate(25,5);
setColor(LIGHTRED);
cout<<"       #    ##### ####  #   #      #    #    #      #     #  #   "<<endl;
locate(25,6);
setColor(LIGHTRED);
cout<<"       #### #   # #   # ####     ###    #    #     # #    ####   "<<endl;
locate(25,7);
setColor(LIGHTRED);
cout<<"       #### #   # #   # ####     ###    #    #     # #    ####   "<<endl;
locate(25,8);
setColor(YELLOW);
cout<<"      =========================================================  "<<endl;
resetColor();
locate(45,12);
cout<<"[1] - JUGAR"<<endl;
locate(45,13);
cout<<"[2] - ESTADISTICAS"<<endl;
locate(45,14);
cout<<"[3] - CREDITOS"<<endl;
locate(45,15);
cout<<"[4] - REGLAS DEL JUEGO"<<endl;
locate(45,16);
cout<<"---------------------------"<<endl;
locate(45,17);
cout<<"[0] - SALIR"<<endl;

locate(45,19);
cout<<"¿OPCIÓN?: ";

}

int confirmarSalida(int num){
    int eleccion;
    locate(45,12);
    cout<<"¿Seguro desea salir del juego?"<<endl;
    locate(45,13);
    cout<<"[1]SI"<<endl;
    locate(45,14);
    cout<<"[2]NO"<<endl;
    locate(45,15);
    cout<<"--------"<<endl;
    locate(45,16);
    cout<<"¿OPCIÓN?: ";
    cin>>eleccion;
    if(eleccion==1){
        return 0;
    }else if(eleccion==2){
    return 5;}
}

void mostrarCreditos(int num){

        locate(45,10);
        cout<<"---------------------------------------------"<<endl;
        setBackgroundColor(RED);
        locate(45,11);
        cout<<"JUEGO DESARROLLADO POR LOS ABUELOS DE LA JAVA"<<endl;
        locate(45,12);
        setBackgroundColor(BLACK);
        cout<<"---------------------------------------------"<<endl;
        locate(60,13);
        setColor(LIGHTMAGENTA);
        cout<<"[INTEGRANTES]"<<endl;
        resetColor();
        locate(45,14);
        cout<<"Ariel Rodriguez                  LEGAJO: 27540"<<endl;
        locate(45,15);
        cout<<"Gaston Garcia                    LEGAJO: 27520"<<endl;
        locate(45,16);
        cout<<"Raul Rodriguez                   LEGAJO: 26097"<<endl;
        locate(45,17);
        cout<<"Gonzalo Ligero                   LEGAJO: 27581"<<endl;

}
void mostrarReglas (int num){
saveDefaultColor();
    setColor(YELLOW);
    locate(45,1);
    cout<<"====================="<<endl;
    resetColor();
    setColor(LIGHTRED);
    locate(45,2);
    cout<<"¿QUÉ ES CART-JITSU ++?"<<endl;
    setColor(YELLOW);
    locate(45,3);
    cout<<"====================="<<endl;
    resetColor();
    cout<<"CARD-JITSU++ es un juego de cartas de dos jugadores"<<endl;
    cout<<"El objetivo del juego es obtener una combinación de cartas de elementos y cumplir con una carta desafío específica para cada jugador"<<endl;
    cout<<"El primer jugador en cumplir ambos hitos se convertirá en el ganador del juego"<<endl;
    cout<<endl;
    setColor(LIGHTRED);
    cout<<"¿CÓMO SE JUEGA UNA PARTIDA?"<<endl;
    resetColor();
    cout<<"Las partidas se juegan con una serie de cartas especiales dividida en dos mazos" <<endl;
    cout<<"El primer mazo es el de Desafíos, donde hay 10 tipos de cartas diferentes"<<endl;
    cout<<"Las cartas desafío contienen una descripción del objetivo que deberá cumplir su portador"<<endl;
    cout<<"Antes de comenzar cada partida, los jugadores roban una carta del Mazo Desafío"<<endl;
    cout<<"Cada jugador debe intentar cumplir con la condición de su carta desafío cuanto antes"<<endl;
    cout<<"El segundo mazo es el de Elementos, donde contamos con 60 cartas distinguidas por elemento, color y número" <<endl;
    cout<<"Las cartas de elementos permiten que se desarrolle la partida" <<endl;
    cout<<"Sin embargo, son las que pueden marcar un desafío como cumplido o no"<<endl;
    cout<<"Y son las que permiten cumplir el segundo hito de la partida: obtener una combinación ganadora" <<endl;
    cout<<endl;
    setColor(LIGHTBLUE);
    cout<<"MAZO DE CARTAS DESAFÍO"<<endl;
    resetColor();
    cout<<"Como se indicó anteriormente, este mazo cuenta con 10 cartas distintas" <<endl;
    cout<<"Dos cartas serán robadas antes del inicio de la partida, una para cada jugador" <<endl;
    cout<<"El mazo desafío contiene las siguientes cartas:" <<endl;
    cout<<"1) GANAR UNA CARTA DE NIEVE"<<endl;
    cout<<"2) GANAR UNA CARTA DE FUEGO"<<endl;
    cout<<"3) GANAR UNA CARTA DE AGUA" <<endl;
    cout<<"4) GANAR DOS CARTAS ROJAS" <<endl;
    cout<<"5) GANAR DOS CARTAS AMARILLAS" <<endl;
    cout<<"6) GANAR DOS CARTAS VERDES" <<endl;
    cout<<"7) GANAR DOS CARTAS AZULES" <<endl;
    cout<<"8) GANAR UNA CARTA CON EL MISMO ELEMENTO QUE EL ADVERSARIO" <<endl;
    cout<<"9) GANAR DOS CARTAS CON EL MISMO NÚMERO" <<endl;
    cout<<"10) GANAR DOS RONDAS DE MANERA CONSECUTIVA" <<endl;
    cout<<endl;
    cout<<"Cada jugador conocerá únicamente su carta desafío y cumplirla será excluyente para ganar la partida "<<endl;
    cout<<endl;
    setColor(LIGHTGREEN);
    cout<<"MAZO DE CARTAS DE ELEMENTOS "<<endl;
    resetColor();
    cout<<"Estas cartas contienen un elemento (FUEGO, NIEVE o AGUA), un color (ROJO, AMARILLO, VERDE o AZUL) y un número (de 1 a 5) "<<endl;
    cout<<"En total este mazo cuenta con 60 naipes y sus cartas permiten que se desarrolle el juego"<<endl;
    cout<<"Cada jugador comienza la partida con tres cartas de elementos repartidas al azar"<<endl;
    cout<<"En cada ronda cada jugador tendrá la obligación de robar una carta del mazo de elementos "<<endl;
    cout<<"También, ambos jugadores están obligados a jugar una carta por ronda para competir con la del adversario "<<endl;
    cout<<"Esto significa que un jugador puede recuperar su carta y ganar la del rival, o perder directamente su carta si el rival ganó la mano "<<endl;
    cout<<endl;
    setColor(LIGHTCYAN);
    cout<<"TRANSCURSO DEL JUEGO"<<endl;
    resetColor();
    cout<<"El juego comienza con la Etapa de Desafíos, donde cada jugador recibirá su carta desafío "<<endl;
    cout<<"A partir de allí comenzará la Etapa de elementos, la cual no tiene una cantidad exacta de rondas"<<endl;
    cout<<"El juego finalizará recién cuando un jugador cumpla con dos condiciones:"<<endl;
    cout<<"1) Lograr lo que indica su carta desafío"<<endl;
    cout<<"2) Obtener una combinación ganadora "<<endl;
    cout<<endl;
    setColor(LIGHTRED);
    cout<<"CHOQUE DE CARTAS: DETERMINAR ELEMENTO"<<endl;
    resetColor();
    cout<<"Luego de que ambos jugadores robaran una carta del mazo de elementos, comenzará la etapa de Choque de Cartas "<<endl;
    cout<<"Para determinar qué carta es la victoriosa se siguen ciertos criterios"<<endl;
    cout<<"Entre esos criterios están las ventajas de elementos: "<<endl;
    cout<<"1) FUEGO vence a NIEVE "<<endl;
    cout<<"2) NIEVE vence a AGUA "<<endl;
    cout<<"3) AGUA vence a FUEGO "<<endl;
    cout<<"Estan reglas se cumplen sin importar el número del naipe "<<endl;
    cout<<"Esto significa que cualquier carta FUEGO derrota a cualquiera de NIEVE sin importar su número"<<endl;
    cout<<endl;
    setColor(LIGHTGREEN);
    cout<<"CHOQUE DE CARTAS: DETERMINAR NÚMERO "<<endl;
    resetColor();
    cout<<"En caso de que ambas cartas jugadas compartan elemento, la victoriosa será la que cuenta con un número mayor"<<endl;
    cout<<"Por ejemplo, si ambas cartas son de tipo FUEGO pero una es FUEGO #2 y la otra FUEGO #4, ganará FUEGO #4 ya que 4 es mayor que 2"<<endl;
    cout<<endl;
    setColor(LIGHTCYAN);
    cout<<"CHOQUE DE CARTAS: DETERMINAR MANO "<<endl;
    resetColor();
    cout<<"Existe una tercera posibilidad, donde las cartas tiradas comparten elemento y número"<<endl;
    cout<<"Por ejemplo: FUEGO #4 ROJO contra FUEGO #4 AMARILLO"<<endl;
    cout<<"En este caso, como ambas cartas son prácticamente idénticas, entrará en juego la MANO "<<endl;
    cout<<"El jugador que sea mano en esa ronda será considerado victorioso de ese enfrentamiento "<<endl;
    cout<<"La ronda se determina de una forma muy sencilla"<<endl;
    cout<<"Si la ronda actual es de un número PAR, el jugador HUMANO será mano"<<endl;
    cout<<"Si, por el contrario, la ronda es IMPAR, la mano será la CPU"<<endl;
    cout<<endl;
    setColor(YELLOW);
    cout<<"FIN DEL CHOQUE DE CARTAS "<<endl;
    resetColor();
    cout<<"Luego de determinar el ganador de la ronda, ambas cartas jugadas pasan a ser parte de la mano del jugador que ganó esa ronda"<<endl;
    cout<<"Esto significa que un jugador puede tener muchas cartas en su mano si gana muchas rondas "<<endl;
    cout<<"No obstante, un jugador jamás podrá contar con menos de tres cartas en su mano"<<endl;
    cout<<endl;
    setColor(LIGHTRED);
    cout<<"COMBINACIÓN GANADORA"<<endl;
    resetColor();
    cout<<"Ya detallamos las cartas desafío, su finalidad y cuáles son. Ahora hablaremos de las combinaciones ganadoras"<<endl;
    cout<<"Una combinación ganadora es el segundo objetivo que debe cumplir un jugador para ganar la partida"<<endl;
    cout<<"Hay dos tipos de combinaciones ganadoras:"<<endl;
    cout<<"1) Tener tres cartas de distinto elemento y color"<<endl;
    cout<<"Por ejemplo: FUEGO #4 AZUL, NIEVE #4 VERDE y AGUA #1 ROJO sería una combinación ganadora"<<endl;
    cout<<"2) Tener tres cartas del mismo elemento"<<endl;
    cout<<"Por ejemplo: AGUA #1 VERDE, AGUA #5 VERDE y AGUA #1 AMARILLO sería una combinación ganadora"<<endl;
    cout<<"El primer jugador en cumplir su carta desafío y una combinación ganadora será el ganador de la partida "<<endl;
    cout<<endl;
    setColor(LIGHTMAGENTA);
    cout<<"PUNTOS DE VICTORIA Y ESTADÍSTICAS"<<endl;
    resetColor();
    cout<<"Una vez finalizada la partida se determinan los puntos de victoria obtenidos por el ganador "<<endl;
    cout<<"Estos se calculan de la siguiente manera:"<<endl;
    cout<<"1) +3 PDV por haber ganado la partida"<<endl;
    cout<<"2) -1 PDV si el contrario obtuvo una combinación ganadora"<<endl;
    cout<<"3) -1 PDV si el contrario cumplió el objetivo de su carta desafío"<<endl;
    cout<<"4) +1 PDV por cada ronda ganada en el juego al adversario"<<endl;
    cout<<"5) +5 PDV por cada ronda ganada en el juego con un elemento igual al del adversario"<<endl;
    cout<<endl;
    cout<<"Eso es todo. Le deseamos mucha suerte y esperamos que disfrute del juego"<<endl;
    cout<<endl;
    setColor(LIGHTRED);
    cout<<"LOS ABUELOS DE LA JAVA® "<<endl;
    resetColor();
}

string pedirNombre(){
    string nombre;

    cout<<"NOMBRE DE USUARIO:";
    cin>>nombre;
    system("CLS");
    cout<<"BIENVENIDO "<<nombre<<endl;
    cout<<"VAMOS A JUGAR"<<endl;
    return nombre;

}

void mostrarOpcionesJuegoPrevioRobarCarta(){
    setBackgroundColor(RED);
    locate(45,10);
    cout<<"             CARD JITSU ++          "<<endl;
    setBackgroundColor(BLACK);
    locate(45,11);
    cout<<"------------------------------------"<<endl;
    locate(45,12);
    cout<<"[1]- VER CARTAS DESAFIO"<<endl;
    locate(45,13);
    cout<<"[2]- VER CARTAS DE ELEMENTOS"<<endl;
    locate(45,14);
    cout<<"[3]- ROBAR CARTA ELEMENTO DE LA PILA"<<endl;
    locate(45,15);
    cout<<"------------------------------------"<<endl;

    locate(45,16);
    cout<<"¿OPCIÓN?: ";

}

void mostrarOpcionesJuegoParaTirarCarta(){
    setBackgroundColor(RED);
    locate(45,10);
    cout<<"             CARD JITSU ++          "<<endl;
    setBackgroundColor(BLACK);
    locate(45,11);
    cout<<"------------------------------------"<<endl;
    locate(45,12);
    cout<<"[1]- VER CARTAS DESAFIO"<<endl;
    locate(45,13);
    cout<<"[2]- VER CARTAS DE ELEMENTOS"<<endl;
    locate(45,14);
    cout<<"[3]- JUGAR UNA CARTA"<<endl;
    locate(45,15);
    cout<<"------------------------------------"<<endl;

   locate(45,16);
    cout<<"¿OPCIÓN?: ";

}

//FALTA HACER ESTAS FUNCIONES. SEGUIR DESDE ACA
int calcularEstadisticasHumano(bool noPerdioNingunaHumano,string nombreUsuario,bool objetivoHumanoGeneral, bool objetivoCPUGeneral, bool vCombinacionGanadoraCPU,bool vCartaDesafioCPU, int contadorRondasGanadasHumano, int rondasGanadasContraMismoElementoHumano, int resultadoChoquedeCartas, int elementosEmpatados){
int acumuladorEstadisticasHumanoEnFuncion=0;

      if(rondasGanadasContraMismoElementoHumano!=0){
        acumuladorEstadisticasHumanoEnFuncion+=rondasGanadasContraMismoElementoHumano;
    }

    if(contadorRondasGanadasHumano!=0){
        acumuladorEstadisticasHumanoEnFuncion+=contadorRondasGanadasHumano;
    }

    cout<<endl;
    setColor(LIGHTRED);
    cout<<"CARD-JITSU++"<<endl;
    resetColor();
    setColor(LIGHTBLUE);
    cout<<"ESTADISTICAS HUMANO"<<endl;
    resetColor();
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"HITO                                                 "<<nombreUsuario<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;

    if(objetivoHumanoGeneral==true){
        acumuladorEstadisticasHumanoEnFuncion+=3;
    cout<<"Ganador de la partida                                 3 PDV"<<endl;
        }
    if(vCombinacionGanadoraCPU==true){
        acumuladorEstadisticasHumanoEnFuncion-=1;
    cout<<"Combinacion elementos cumplido por contrario         -1 PDV"<<endl;
    }else{
    cout<<"Combinacion elementos cumplido por contrario          0 PDV"<<endl;}
    if(vCartaDesafioCPU==true){
        acumuladorEstadisticasHumanoEnFuncion-=1;
    cout<<"Carta desafío cumplida por contrario                 -1 PDV"<<endl;
    }else{
    cout<<"Carta desafio no cumplida por contrario               0 PDV"<<endl;}
    cout<<"Rondas ganadas al adversario                          "<<contadorRondasGanadasHumano<<" PDV"<<endl;
    if(rondasGanadasContraMismoElementoHumano!=0){
    cout<<"Rondas ganadas al adversario con igual elemento       "<<rondasGanadasContraMismoElementoHumano<<" PDV"<<endl;}
    if(noPerdioNingunaHumano==true){
        acumuladorEstadisticasHumanoEnFuncion+=5;
    cout<<"No perdió ningún naipe                           +5PDV"<<endl;
    }else{
    cout<<"Perdió un naipe contra el rival                       0 PDV"<<endl;}
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"TOTAL                                                 "<<acumuladorEstadisticasHumanoEnFuncion<<" PDV"<<endl;

 return acumuladorEstadisticasHumanoEnFuncion;

}


int calcularEstadisticasCPU(bool noPerdioNingunaCPU, bool objetivoCPUGeneral, bool objetivoHumanoGeneral, bool vCombinacionGanadoraHumano,bool vCartaDesafioHumano, int contadorRondasGanadasCPU, int rondasGanadasContraMismoElementoCPU,int resultadoChoquedeCartas,int elementosEmpatados){
int acumuladorEstadisticasCPUEnFuncion=0;



    if(vCombinacionGanadoraHumano==true){
        acumuladorEstadisticasCPUEnFuncion-=1;
    }



    if(rondasGanadasContraMismoElementoCPU!=0){
        acumuladorEstadisticasCPUEnFuncion+=rondasGanadasContraMismoElementoCPU;
    }

    acumuladorEstadisticasCPUEnFuncion+=contadorRondasGanadasCPU;

    cout<<endl;
    setColor(LIGHTRED);
    cout<<"CARD-JITSU++"<<endl;
    resetColor();
    setColor(LIGHTGREEN);
    cout<<"ESTADISTICAS CPU"<<endl;
    resetColor();
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"HITO                                                  CPU            "<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    if(objetivoCPUGeneral==true){
        acumuladorEstadisticasCPUEnFuncion+=3;
        cout<<"Ganador de la partida                                 3 PDV"<<endl;
    }
    if(vCombinacionGanadoraHumano==true){
    cout<<"Combinacion elementos cumplido por contrario         -1 PDV"<<endl;
    }else{
    cout<<"Combinacion elementos cumplido por contrario          0 PDV"<<endl;}
    if(vCartaDesafioHumano==true){
        acumuladorEstadisticasCPUEnFuncion-=1;
    cout<<"Carta desafio cumplida por contrario                 -1 PDV"<<endl;
    }else{
    cout<<"Carta desafio no cumplida por contrario               0 PDV"<<endl;}
    cout<<"Rondas ganadas al adversario                          "<<contadorRondasGanadasCPU<<" PDV"<<endl;
    if(rondasGanadasContraMismoElementoCPU!=0){
    cout<<"Rondas ganadas al adversario con igual elemento       "<<rondasGanadasContraMismoElementoCPU<<" PDV"<<endl;}
    if(noPerdioNingunaCPU==true){
        acumuladorEstadisticasCPUEnFuncion+=5;
    cout<<"No perdió ningún naipe                               +5PDV"<<endl;
    }else{
    cout<<"Perdió un naipe contra el rival                       0 PDV"<<endl;}
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"TOTAL                                                 "<<acumuladorEstadisticasCPUEnFuncion<<" PDV"<<endl;


 return acumuladorEstadisticasCPUEnFuncion;
}

string mostrarGraciasPorJugar(){
saveDefaultColor();
//SETBACKGROUNDCOLOR NO CAMBIA EL COLOR DE LOS CARACTERES SINO DEL FONDO
setColor(LIGHTRED);
locate(25,1);
cout<<"            ###### #####   ###### #####  ## ######  ######            "<<endl;
locate(25,2);
cout<<"            ##     ##   #  ##   # ##        ##   #  #            "<<endl;
locate(25,3);
cout<<"            ###### #####   ###### ##     ## ######   ###            "<<endl;
locate(25,4);
cout<<"            ##   # ##   #  ##   # ##     ## ##   #      #            "<<endl;
locate(25,5);
cout<<"            ###### ##    # ##   # #####  ## ##   #  ####            "<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
setColor(LIGHTBLUE);
locate(25,9);
cout<<"                     ###### ##### #####             "<<endl;
locate(25,10);
cout<<"                     ##   # #   # ##   #          "<<endl;
locate(25,11);
cout<<"                     #####  #   # #####       "<<endl;
locate(25,12);
cout<<"                     ##     #   # ##   #     "<<endl;
locate(25,13);
cout<<"                     ##     ##### ##    #    "<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
setColor(LIGHTGREEN);
locate(25,18);
cout<<"              ###### #   # ###### ###### #####            "<<endl;
locate(25,19);
cout<<"                ##   #   # ##     ##   # ##   #            "<<endl;
locate(25,20);
cout<<"                ##   #   # ###### ###### #####            "<<endl;
locate(25,21);
cout<<"                ##   ##### ##   # ##   # ##   #            "<<endl;
locate(25,22);
cout<<"              ####   ##### ###### ##   # ##    #            "<<endl;
resetColor();

}

int decideElAzar(){
int h;

h=rand()%10+1;

if((rand()%10+1)%2==0){
    return 1;
    }else{
    return 2;}
}

int quienGanoElJuego(string nombreUsuario,int acumuladorEstadisticasHumano, int acumuladorEstadisticasCPU, bool objetivoHumanoGeneral,bool objetivoCPUGeneral){

    if(objetivoHumanoGeneral==true&&objetivoCPUGeneral==false){
        return 1;
    }else if(objetivoHumanoGeneral==false&&objetivoCPUGeneral==true){
    return 2;
    }else if(objetivoHumanoGeneral==true&&objetivoCPUGeneral==true){
        if(acumuladorEstadisticasHumano>acumuladorEstadisticasCPU){
            return 1;
        }else if(acumuladorEstadisticasHumano<acumuladorEstadisticasCPU){
        return 2;}else if(acumuladorEstadisticasHumano==acumuladorEstadisticasCPU){
        return 3;}
    }

}




