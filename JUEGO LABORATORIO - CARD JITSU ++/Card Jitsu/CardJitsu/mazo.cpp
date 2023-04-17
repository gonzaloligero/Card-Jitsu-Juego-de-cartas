#include <iostream>
#include "colores.h"
using namespace std;
using namespace rlutil;


void llenarMazoElemento(){
    //FUNCIÓN QUE PASA LOS ÍNDICES DEL 0 AL 59 Y LES COLOCA 1 A 60
    int x;
    int mazoElemento[60]={};
    for(x=0;x<60;x++){
        mazoElemento[x]=x+1;
    }
}

void repartirTresCartasHumano(int mazoHumano[],bool queCartasSalieron[]){
    //FUNCIÓN QUE SÓLO ENTRA EN JUEGO CUANDO ES LA PRIMERA MANO, SINO NO SE UTILIZA.
    int x,h;

    while(mazoHumano[0]==0||mazoHumano[1]==0||mazoHumano[2]==0){
    h=rand()%60+1;
    if(mazoHumano[0]==0){
        mazoHumano[0]=h;
        queCartasSalieron[h-1]=true;
    }else if(mazoHumano[1]==0&&mazoHumano[0]!=h){
    mazoHumano[1]=h;
    queCartasSalieron[h-1]=true;}else if(mazoHumano[2]==0&&mazoHumano[0]!=h&&mazoHumano[1]!=h){
    mazoHumano[2]=h;}
    queCartasSalieron[h-1]=true;
    }

}


void repartirTresCartasCPU(int mazoCPU[],int mazoHumano[],bool queCartasSalieron[]){
    //FUNCIÓN QUE LE ENTREGA LAS TRES PRIMERAS CARTAS A LA CPU. SE COLOCÓ EL MAZO HUMANO COMO UN DOBLE CHEQUEO, PERO PODRÍA SACARSE MODIFICANDO LA FUNCIÓN
    int x,j;
     while(mazoCPU[0]==0||mazoCPU[1]==0||mazoCPU[2]==0){
    j=rand()%60+1;
    if(mazoCPU[0]==0&&mazoHumano[0]!=j&&mazoHumano[1]!=j&&mazoHumano[2]!=j){
        mazoCPU[0]=j;
        queCartasSalieron[j-1]=true;
    }else if(mazoCPU[1]==0&&mazoCPU[0]!=j&&mazoHumano[0]!=j&&mazoHumano[1]!=j&&mazoHumano[2]!=j){
    mazoCPU[1]=j;
    queCartasSalieron[j-1]=true;}else if(mazoCPU[2]==0&&mazoCPU[0]!=j&&mazoCPU[1]!=j&&mazoHumano[0]!=j&&mazoHumano[1]!=j&&mazoHumano[2]!=j){
    mazoCPU[2]=j;}
    queCartasSalieron[j-1]=true;
    }

}

void vaciarMazoFlagElementos(bool queCartasSalieron[]){
    //FUNCIÓN QUE COLOCA TODOS LOS ÍNDICES DEL VECTOR BOOLEANO QUECARTASSALIERON EN FALSO
    //SI UN ÍNDICE ESTÁ EN FALSO, SIGNIFICA QUE ESA CARTA AÚN NO SALIÓ
    //SI ESTÁ EN TRUE, ESA CARTA YA SALIÓ Y NO PUEDE REPETIRSE
    int x;
    for(x=0;x<60;x++){

        queCartasSalieron[x]=false;
    }

}

string descripcionCarta(int cartaGeneral){
    //SWITCH QUE RECIBE EL NÚMERO DE CARTA DEL 1 AL 60 Y MUESTRA EN PANTALLA A CUÁL SE REFIERE EN REALIDAD
    //MOSTRAMOS NÚMERO DE CARTA REAL (1 A 5), COLOR Y ELEMENTO
    //PODRÍA OPTIMIZARSE, PERO ESTÁ FUNCIONANDO SIN NINGÚN PROBLEMA
    switch(cartaGeneral){
    case 1: setColor(LIGHTRED);
            return "FUEGO ROJO #1";
    break;
    case 2: setColor(LIGHTRED);
            return "FUEGO ROJO #2";
    break;
    case 3: setColor(LIGHTRED);
            return"FUEGO ROJO #3";
    break;
    case 4: setColor(LIGHTRED);
            return"FUEGO ROJO #4";
    break;
    case 5: setColor(LIGHTRED);
            return"FUEGO ROJO #5";
    break;
    case 6: setColor(YELLOW);
            return"FUEGO AMARILLO #1";
    break;
    case 7: setColor(YELLOW);
            return "FUEGO AMARILLO #2";
    break;
    case 8: setColor(YELLOW);
            return "FUEGO AMARILLO #3";
    break;
    case 9: setColor(YELLOW);
            return "FUEGO AMARILLO #4";
    break;
    case 10: setColor(YELLOW);
            return "FUEGO AMARILLO #5";
    break;
    case 11: setColor(LIGHTGREEN);
            return "FUEGO VERDE #1";
    break;
    case 12: setColor(LIGHTGREEN);
            return "FUEGO VERDE #2";
    break;
    case 13: setColor(LIGHTGREEN);
            return "FUEGO VERDE #3";
    break;
    case 14: setColor(LIGHTGREEN);
            return "FUEGO VERDE #4";
    break;
    case 15: setColor(LIGHTGREEN);
            return "FUEGO VERDE #5";
    break;
    case 16: setColor(LIGHTBLUE);
            return "FUEGO AZUL #1";
    break;
    case 17: setColor(LIGHTBLUE);
            return "FUEGO AZUL #2";
    break;
    case 18: setColor(LIGHTBLUE);
            return "FUEGO AZUL #3";
    break;
    case 19: setColor(LIGHTBLUE);
            return "FUEGO AZUL #4";
    break;
    case 20: setColor(LIGHTBLUE);
            return "FUEGO AZUL #5";
    break;
    case 21: setColor(LIGHTRED);
            return "NIEVE ROJO #1";
    break;
    case 22: setColor(LIGHTRED);
            return "NIEVE ROJO #2";
    break;
    case 23: setColor(LIGHTRED);
            return "NIEVE ROJO #3";
    break;
    case 24: setColor(LIGHTRED);
            return "NIEVE ROJO #4";
    break;
    case 25: setColor(LIGHTRED);
            return "NIEVE ROJO #5";
    break;
    case 26: setColor(YELLOW);
            return "NIEVE AMARILLO #1";
    break;
    case 27: setColor(YELLOW);
            return "NIEVE AMARILLO #2";
    break;
    case 28: setColor(YELLOW);
            return "NIEVE AMARILLO #3";
    break;
    case 29: setColor(YELLOW);
            return "NIEVE AMARILLO #4";
    break;
    case 30: setColor(YELLOW);
            return "NIEVE AMARILLO #5";
    break;
    case 31: setColor(LIGHTGREEN);
            return "NIEVE VERDE #1";
    break;
    case 32: setColor(LIGHTGREEN);
            return "NIEVE VERDE #2";
    break;
    case 33: setColor(LIGHTGREEN);
            return "NIEVE VERDE #3";
    break;
    case 34: setColor(LIGHTGREEN);
            return "NIEVE VERDE #4";
    break;
    case 35: setColor(LIGHTGREEN);
            return "NIEVE VERDE #5";
    break;
    case 36: setColor(LIGHTBLUE);
            return "NIEVE AZUL #1";
    break;
    case 37: setColor(LIGHTBLUE);
            return "NIEVE AZUL #2";
    break;
    case 38: setColor(LIGHTBLUE);
            return "NIEVE AZUL #3";
    break;
    case 39: setColor(LIGHTBLUE);
            return "NIEVE AZUL #4";
    break;
    case 40: setColor(LIGHTBLUE);
            return "NIEVE AZUL #5";
    break;
    case 41: setColor(LIGHTRED);
            return "AGUA ROJO #1";
    break;
    case 42: setColor(LIGHTRED);
            return "AGUA ROJO #2";
    break;
    case 43: setColor(LIGHTRED);
            return "AGUA ROJO #3";
    break;
    case 44: setColor(LIGHTRED);
            return "AGUA ROJO #4";
    break;
    case 45: setColor(LIGHTRED);
            return "AGUA ROJO #5";
    break;
    case 46: setColor(YELLOW);
            return "AGUA AMARILLO #1";
    break;
    case 47: setColor(YELLOW);
            return "AGUA AMARILLO #2";
    break;
    case 48: setColor(YELLOW);
            return "AGUA AMARILLO #3";
    break;
    case 49: setColor(YELLOW);
            return "AGUA AMARILLO #4";
    break;
    case 50: setColor(YELLOW);
            return "AGUA AMARILLO #5";
    break;
    case 51: setColor(LIGHTGREEN);
            return "AGUA VERDE #1";
    break;
    case 52: setColor(LIGHTGREEN);
            return "AGUA VERDE #2";
    break;
    case 53: setColor(LIGHTGREEN);
            return "AGUA VERDE #3";
    break;
    case 54: setColor(LIGHTGREEN);
            return "AGUA VERDE #4";
    break;
    case 55: setColor(LIGHTGREEN);
            return "AGUA VERDE #5";
    break;
    case 56: setColor(LIGHTBLUE);
            return "AGUA AZUL #1";
    break;
    case 57: setColor(LIGHTBLUE);
            return "AGUA AZUL #2";
    break;
    case 58: setColor(LIGHTBLUE);
            return "AGUA AZUL #3";
    break;
    case 59: setColor(LIGHTBLUE);
            return "AGUA AZUL #4";
    break;
    case 60: setColor(LIGHTBLUE);
            return "AGUA AZUL #5";
    break;
    }

}

void cualesSonMisCartas(int mazoHumano[]){
    //FUNCIÓN QUE LE DICE AL USUARIO CUÁLES SON SUS CARTAS UTILIZANDO TAMBIÉN OTRA FUNCIÓN
    //USAMOS UNA FUNCIÓN ANIDADA (DESCRIPCIÓNCARTA) PARA MOSTRAR QUÉ CARTAS TIENE EN REALIDAD
    int x;
    cout<<"Tus cartas actuales son:"<<endl;
    for(x=0;x<60;x++){
        if(mazoHumano[x]!=0){
            cout<<descripcionCarta(mazoHumano[x]);
            cout<<endl;
        }
    }
}

int robarCartaPilaHumano(int mazoHumano[],bool queCartasSalieron[]){
    //FUNCIÓN QUE TAPA UN ÍNDICE DEL VECTOR BOOLEANO CUANDO SALE UNA CARTA
    //AL SACAR UNA CARTA QUE ESTÉ EN FALSE (NUNCA SALIÓ) SE LA PASAMOS AL MAZO HUMANO
    int x,cartaRobada;
    cartaRobada=rand()%60+1;
    for(x=0;x<60;x++){
        if(queCartasSalieron[cartaRobada-1]==false){
            queCartasSalieron[cartaRobada-1]=true;
            x=60;
        }else {cartaRobada=rand()%60+1;
        x=0;}
    }
    for(x=0;x<60;x++){
        if(mazoHumano[x]==0){
            mazoHumano[x]=cartaRobada;
            x=60;
        }
    }
    return cartaRobada;

}

int robarCartaPilaCPU(int mazoCPU[], bool queCartasSalieron[]){
    //LO MISMO QUE LA FUNCIÓN PARA HUMANO PERO PARA CPU
 int x,cartaRobada;
    cartaRobada=rand()%60+1;
    for(x=0;x<60;x++){
        if(queCartasSalieron[cartaRobada-1]==false){
            queCartasSalieron[cartaRobada-1]=true;
            x=60;
        }else {cartaRobada=rand()%60+1;
        x=0;}
    }
    for(x=0;x<60;x++){
        if(mazoCPU[x]==0){
            mazoCPU[x]=cartaRobada;
            x=60;}
    }
      return cartaRobada;
}

int tirarCartaHumano(int mazoHumano[]){
    //FUNCIÓN QUE LE MUESTRA AL HUMANO QUÉ CARTAS TIENE DISPONIBLE PARA TIRAR
    int x,cartaElegidaHumano,cartaHumano;
    cout<<"Selecciona la carta que deseas tirar"<<endl;
    cout<<"------------------------------------"<<endl;
    //MOSTRAMOS LAS CARTAS QUE TIENE EL HUMANO
    for(x=0;x<60;x++){
        if(mazoHumano[x]!=0){
            resetColor();
            cout<<"["<<x+1<<"]"<<descripcionCarta(mazoHumano[x])<<endl;
        }
    }
    resetColor();
    cout<<"------------------------------------"<<endl;
    cout<<"Numero de carta a tirar: ";
    cin>>cartaElegidaHumano;
    for(x=0;x<60;x++){
        if(mazoHumano[x]==mazoHumano[cartaElegidaHumano-1]){
            cartaHumano=mazoHumano[x];
            x=60;
            return cartaHumano;
        }
   }
}

int tirarCartaCPU(int mazoCPU[]){
    //FUNCIÓN QUE UTILIZA UN EL RAND PARA DETERMINAR QUÉ CARTA TIRA LA CPU
    //LA CARTA ELEGIDA POR LA CPU, OBVIAMENTE, DEBE ESTAR EN SU MAZO.
    //LA CPU JAMÁS TIRARÁ UNA CARTA QUE NO CONTENGA, YA QUE EL RAND ESTÁ CONFIGURADO DE ESA MANERA
    //CUANDO EL RAND DETECTA QUE SALIÓ UN NÚMERO QUE CORRESPONDE A UNA CARTA QUE TIENE EN SU MAZO, LA TIRA
    int x,cartaElegidaCPU;
    bool laCartaEsta=false;

    while(laCartaEsta!=true){
        cartaElegidaCPU=rand()%60+1;
        for(x=0;x<60;x++){
        if(mazoCPU[x]==cartaElegidaCPU){
            laCartaEsta=true;
            x=60;
            }
        }
    }
    return cartaElegidaCPU;

}


int mostrarMazoDeElementos(int vec[]){
    //FUNCIÓN INCLUIDA EN EL SWITCH INTERNO DEL JUEGO, QUE MUESTRA QUÉ CARTAS TIENE EL USUARIO
    int x;
    for(x=0;x<60;x++){
        if(vec[x]!=0){
            cout<<descripcionCarta(vec[x])<<endl;
        }
    }
}
