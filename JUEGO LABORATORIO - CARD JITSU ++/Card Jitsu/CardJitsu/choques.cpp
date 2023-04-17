#include <iostream>
#include "mazo.h"
#include "colores.h"
using namespace std;
using namespace rlutil;

int evaluarChoqueElementos(int cartaHumano, int cartaCPU, int mazoHumano[],int mazoCPU[]){
    //FUNCIÓN QUE, COMO DICE SU NOMBRE, EVALÚA LOS ELEMENTOS DE LAS CARTAS A TIRAR
    //SI EL RETURN ES 7, SIGNIFICA QUE LOS ELEMENTOS ESTÁN EMPATADOS
    //SI ES DEL 1 AL 3, SIGNIFICA QUE EL HUMANO GANÓ
    //DEL 4 AL 6, LA CPU GANÓ
    int x;
    int vFuego[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int vNieve[20]={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
    int vAgua[20]={41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
    string cartaClonHumano,cartaClonCPU;

    //ASIGNACION DE ELEMENTOS
    for(x=0;x<20;x++){
        if(vFuego[x]==cartaHumano){
            cartaClonHumano="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaHumano){
        cartaClonHumano="NIEVE";
        x=20;}else if(vAgua[x]==cartaHumano){
        cartaClonHumano="AGUA";
        x=20;}
    }
    for(x=0;x<20;x++){
        if(vFuego[x]==cartaCPU){
            cartaClonCPU="FUEGO";
            x=20;
        }else if(vNieve[x]==cartaCPU){
        cartaClonCPU="NIEVE";
        x=20;}else if(vAgua[x]==cartaCPU){
        cartaClonCPU="AGUA";
        x=20;}
    }

    //MATCHEO. RETURN 7 ES EMPATE DE ELEMENTOS
    if(cartaClonHumano=="FUEGO"&&cartaClonCPU=="FUEGO"||cartaClonHumano=="NIEVE"&&cartaClonCPU=="NIEVE"||cartaClonHumano=="AGUA"&&cartaClonCPU=="AGUA"){
        cout<<"Las cartas comparten elemento ya que ambas son de tipo "<<cartaClonHumano<<endl;
        return 7;
    }
    //FUEGO HUMANO GANA A NIEVE CPU
    if(cartaClonHumano=="FUEGO"&&cartaClonCPU=="NIEVE"){
            for(x=0;x<60;x++){
                if(mazoCPU[x]==cartaCPU){
                    mazoCPU[x]=0;
                    x=60;
                }
            }
            for(x=0;x<60;x++){
                if(mazoHumano[x]==0){
                    mazoHumano[x]=cartaCPU;
                    x=60;
                }
            }
        return 1;
    }
    //NIEVE HUMANO GANA A AGUA CPU
    if(cartaClonHumano=="NIEVE"&&cartaClonCPU=="AGUA"){
             for(x=0;x<60;x++){
                if(mazoCPU[x]==cartaCPU){
                    mazoCPU[x]=0;
                    x=60;
                }
            }
            for(x=0;x<60;x++){
                if(mazoHumano[x]==0){
                    mazoHumano[x]=cartaCPU;
                    x=60;
                }
            }
        return 2;
    }
    //AGUA HUMANO GANA A FUEGO CPU
    if(cartaClonHumano=="AGUA"&&cartaClonCPU=="FUEGO"){
         for(x=0;x<60;x++){
                if(mazoCPU[x]==cartaCPU){
                    mazoCPU[x]=0;
                    x=60;
                }
            }
            for(x=0;x<60;x++){
                if(mazoHumano[x]==0){
                    mazoHumano[x]=cartaCPU;
                    x=60;
                }
            }
        return 3;
    }
    //FUEGO CPU GANA A NIEVE HUMANO
    if(cartaClonHumano=="NIEVE"&&cartaClonCPU=="FUEGO"){
         for(x=0;x<60;x++){
                if(mazoHumano[x]==cartaHumano){
                    mazoHumano[x]=0;
                    x=60;
                }
            }
            for(x=0;x<60;x++){
                if(mazoCPU[x]==0){
                    mazoCPU[x]=cartaHumano;
                    x=60;
                }
            }
        return 4;
    }
    //NIEVE CPU GANA A AGUA HUMANO
    if(cartaClonHumano=="AGUA"&&cartaClonCPU=="NIEVE"){
        for(x=0;x<60;x++){
                if(mazoHumano[x]==cartaHumano){
                    mazoHumano[x]=0;
                    x=60;
                }
            }
            for(x=0;x<60;x++){
                if(mazoCPU[x]==0){
                    mazoCPU[x]=cartaHumano;
                    x=60;
                }
            }
        return 5;
    }
    //AGUA CPU GANA A FUEGO HUMANO
    if(cartaClonHumano=="FUEGO"&&cartaClonCPU=="AGUA"){
        for(x=0;x<60;x++){
                if(mazoHumano[x]==cartaHumano){
                    mazoHumano[x]=0;
                    x=60;
                }
            }
            for(x=0;x<60;x++){
                if(mazoCPU[x]==0){
                    mazoCPU[x]=cartaHumano;
                    x=60;
                }
            }
        return 6;
    }

}

int evaluarChoqueNumeros(int cartaHumano, int cartaCPU){
    //FUNCIÓN QUE SÓLO ENTRARÁ EN JUEGO SI EVALUARCHOQUEDEELEMENTOS RETORNÓ UN 7
    //SI RETORNÓ 7 SIGNIFICA QUE LOS ELEMENTOS FUERON IGUALES, POR LO CUAL ENTRA EN JUEGO ESTA FUNCIÓN
    //ACÁ EVALUAMOS QUÉ CARTA ES DE MAYOR NÚMERO
    //SI LA CARTA DEL HUMANO ES DE MAYOR NÚMERO, RETORNARÁ 2
    //SI LA CARTA DE LA CPU ES MAYOR, RETORNARÁ 3
    //SI LAS CARTAS COMPARTEN NÚMERO, RETORNARÁ 1 Y ENTRARÁ EN JUEGO LA FUNCIÓN QUIENESMANO
    int Vuno[12]={1,6,11,16,21,26,31,36,41,46,51,56};
    int Vdos[12]={2,7,12,17,22,27,32,37,42,47,52,57};
    int Vtres[12]={3,8,13,18,23,28,33,38,43,48,53,58};
    int Vcuatro[12]={4,9,14,19,24,29,34,39,44,49,54,59};
    int Vcinco[12]={5,10,15,20,25,30,35,40,45,50,55,60};
    int x,clonCartaHumano,clonCartaCPU;
    for(x=0;x<12;x++){
        if(cartaHumano==Vuno[x]){
            clonCartaHumano=1;
            x=12;
        }else if(cartaHumano==Vdos[x]){
        clonCartaHumano=2;
        x=12;}else if(cartaHumano==Vtres[x]){
        clonCartaHumano=3;
        x=12;}else if(cartaHumano==Vcuatro[x]){
        clonCartaHumano=4;
        x=12;}else if(cartaHumano==Vcinco[x]){
        clonCartaHumano=5;
        x=12;}
    }
    for(x=0;x<12;x++){
        if(cartaCPU==Vuno[x]){
            clonCartaCPU=1;
            x=12;
        }else if(cartaCPU==Vdos[x]){
        clonCartaCPU=2;
        x=12;}else if(cartaCPU==Vtres[x]){
        clonCartaCPU=3;
        x=12;}else if(cartaCPU==Vcuatro[x]){
        clonCartaCPU=4;
        x=12;}else if(cartaCPU==Vcinco[x]){
        clonCartaCPU=5;
        x=12;}
    }
    //RETURN 1 POR CARTA CON MISMO NUMERO, RETURN 2 GANA HUMANO, RETURN 3 GANA CPU
    if(clonCartaHumano==clonCartaCPU){
        return 1;
    }else if(clonCartaHumano>clonCartaCPU){
    return 2;}else{
    return 3;}
}

void choqueNumerosGanaHumano(int cartaHumano, int cartaCPU, int mazoHumano[],int mazoCPU[]){
    //FUNCIÓN QUE ENTRA EN JUEGO SI EVALUARCHOQUEDENÚMEROS RETORNÓ 2
    //SÓLO DESCRIBE QUE GANA EL HUMANO POR TENER UNA CARTA SUPERIOR AL DE LA CPU
    int x;

    for(x=0;x<60;x++){
        if(mazoCPU[x]==cartaCPU){
            mazoCPU[x]=0;
            x=60;
        }
}
    for(x=0;x<60;x++){
        if(mazoHumano[x]==0){
            mazoHumano[x]=cartaCPU;
            x=60;
        }
    }
    cout<<"Gana HUMANO por tener una carta de mayor numero que la CPU"<<endl;

}

void choqueNumerosGanaCPU(int cartaHumano, int cartaCPU, int mazoHumano[],int mazoCPU[]){
    //IDÉNTICA A LA ANTERIOR, SÓLO QUE EN ESTE CASO GANA LA CPU
      int x;

    for(x=0;x<60;x++){
        if(mazoHumano[x]==cartaHumano){
            mazoHumano[x]=0;
            x=60;
        }
}
    for(x=0;x<60;x++){
        if(mazoCPU[x]==0){
            mazoCPU[x]=cartaHumano;
            x=60;
        }
    }
    cout<<"Gana CPU por tener una carta de mayor numero que el HUMANO"<<endl;
}




int evaluarMano (string nombreUsuario,int ronda,int cartaHumano, int cartaCPU, int mazoHumano[],int mazoCPU[]){
    //EVALUARMANO SÓLO ENTRA EN JUEGO SI EVALUARCHOQUEDENUMEROS RETORNÓ 1 Y EVALUARCHOQUEDEELEMENTOS RETORNÓ 7
    //LE PASAMOS LA VARIABLE RONDA, YA QUE ELLA DETERMINA QUIÉN GANARÁ ESTA MANO
    //SI LA RONDA ES PAR (POR EJEMPLO, SEGUNDA RONDA) GANA HUMANO PORQUE ES MANO
    //SI LA RONDA ES IMPAR (POR EJEMPLO, PRIMERA O TERCERA RONDA) GANA LA CPU PORQUE ES MANO
    //RONDA PAR = GANA HUMANO
    //RONDA IMPAR = GANA CPU
    int x;

    if(ronda%2==0){
            cout<<"Las cartas comparten también número, pero gana el jugador "<<nombreUsuario<<"  por ser mano"<<endl;
        for(x=0;x<60;x++){
           if(mazoCPU[x]==cartaCPU){
            mazoCPU[x]=0;
            x=60;
           }
        }for(x=0;x<60;x++){
        if(mazoHumano[x]==0){
            mazoHumano[x]=cartaCPU;
            x=60;
        }
    }
}else{
    cout<<"Las cartas comparten también número, pero gana la CPU por ser mano"<<endl;
    for(x=0;x<60;x++){
        if(mazoHumano[x]==cartaHumano){
            mazoHumano[x]=0;
            x=60;
        }
    }for(x=0;x<60;x++){
    if(mazoCPU[x]==0){
       mazoCPU[x]=cartaHumano;
        x=60;
            }
        }
    }
if(ronda%2==0){
    return 1;
}else if(ronda%2!=0){
return 2;}
}

void descripcionDeCartasEnChoque(int cartaHumano,int cartaCPU){
    //FUNCIÓN QUE DEVUELVE LA DESCRIPCIÓN DE LA CARTA QUE ELIGIÓ CADA JUGADOR
    saveDefaultColor();
    cout<< "La carta elegida por el jugador fue:"<<descripcionCarta(cartaHumano)<<endl;
    resetColor();
    cout<< "La carta elegida por la CPU fue:"<<descripcionCarta(cartaCPU);
    resetColor();
    cout<<endl;
}

void quePasoEnEstaMano(int resultadoChoqueDeCartas){
    //FUNCIÓN QUE MUESTRA EN PANTALLA QUÉ SUCEDIÓ EN ESTA MANO EN CASO DE QUE EL RETURN DE EVALUARCHOQUEELEMENTOS NO FUERA 7
    switch(resultadoChoqueDeCartas){
    case 1: cout<< "Gana HUMANO porque FUEGO derrota a NIEVE"<<endl;
    break;
    case 2: cout<< "Gana HUMANO porque NIEVE derrota a AGUA"<<endl;
    break;
    case 3: cout<< "Gana HUMANO porque AGUA derrota a FUEGO"<<endl;
    break;
    case 4: cout<< "Gana CPU porque FUEGO derrota a NIEVE"<<endl;
    break;
    case 5: cout<< "Gana CPU porque NIEVE derrota a AGUA"<<endl;
    break;
    case 6: cout<< "Gana CPU porque AGUA derrota a FUEGO"<<endl;
    break;
    }
}
