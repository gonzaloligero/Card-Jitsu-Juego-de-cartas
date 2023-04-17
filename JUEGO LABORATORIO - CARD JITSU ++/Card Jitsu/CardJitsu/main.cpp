#include <iostream>
#include <ctime>
#include <windows.h>
#include "menu.h"
#include "mazo.h"
#include "desafios.h"
#include "choques.h"
#include "colores.h"
#include <locale.h>
using namespace rlutil;
using namespace std;

int main()
{
//PERMITE USAR Ñ, ACENTOS, SIGNOS DE INTERROGACIÓN,ETC
setlocale(LC_ALL, "Spanish");
//SEMILLA PARA EL RAND
srand(time(NULL));

//VARIABLES DE CARTAS PUNTUALES
int cartaDesafioHumano,cartaDesafioCPU,cartaHumano,cartaCPU,cartaRobadaHumano,cartaRobadaCPU;

//VECTORES DE MAZOS
int mazoHumano[60]={},mazoCPU[60]={},cartasGanadasHumanoDesafio9[60]={},cartasGanadasCPUDesafio9[60]={};
bool queCartasSalieron[60]={};

//VARIABLE QUE CUENTA LAS RONDAS
int ronda=0;

//X PARA CICLOS FOR
int x;

//VARIABLES PARA CHOQUE DE CARTAS. SE LE ASIGNEN VALORES A TRAVÉS DE LAS FUNCIONES EVALUARMANO (SI COMPARTEN ELEMENTO Y NÚMERO), EVALUAR CHOQUEDELEMENTOS Y EVALUARCHOQUEDENUMEROS
int resultadoChoquedeCartas,elementosEmpatados;

//VARIABLE PARA CONFIRMAR SALIDA DEL JUEGO
int eleccion;

//VARIABLE PARA SELECCIONAR OPCIÓN EN LOS MENÚ
int num;

//VARIABLE QUE GUARDA EL NOMBRE INGRESADO POR EL USUARIO
string nombreUsuario;

//BANDERAS PARA DETERMINAR SI SE CUMPLEN LOS OBJETIVOS DURANTE LA PARTIDA
bool objetivoHumanoGeneral=false,objetivoCPUGeneral=false;

//VARIABLES DE CARTAS DESAFIO Y COMBINACION GANADORA HUMANO
bool desafioGanarUnElementoEspecificoHumano=false,desafioDosCartasHumano=false,desafioDosCartasCPU=false,ganarDosCartasDesafio9Humano=false;
int ganarDosCartasHumano=0,ganarRondasConsecutivasHumano=0;
bool combinacionGanadoraHumano=false;
int dosRondasConsecutivasHumano=0,contadorRondasGanadasHumano=0,rondasGanadasContraMismoElementoHumano=0;

//VARIABLE QUE DETERMINA QUE HUMANO CUMPLIÓ UNA COMBINACIÓN GANADORA Y SU CARTA DESAFIO
bool vCombinacionGanadoraHumano=false,vCartaDesafioHumano=false;

//VARIABLES DE CARTA DESAFIO Y COMBINACION GANADORA CPU
bool desafioGanarUnElementoEspecificoCPU=false;
int ganarDosCartasCPU=0,ganarRondasConsecutivasCPU=0;
bool combinacionGanadoraCPU=false,ganarDosCartasDesafio9CPU=false;
int dosRondasConsecutivasCPU=0,contadorRondasGanadasCPU=0,rondasGanadasContraMismoElementoCPU=0;

//VARIABLE QUE DETERMINA QUE CPU CUMPLIÓ UNA COMBINACIÓN GANADORA Y SU CARTA DESAFIO
bool vCombinacionGanadoraCPU=false,vCartaDesafioCPU=false;

//VARIABLES QUE ACUMULAN PUNTAJE DURANTE LA PARTIDA
int acumuladorPuntajeHumano=0,acumuladorPuntajeCPU=0;

//VARIABLE BOOLEANA PARA SABER SI YA HUBO UN JUGADOR. FALSE=NADIE JUGÓ AÚN
bool BanderaRecord=false;

//VARIABLE STRING QUE GUARDA EL NOMBRE DEL JUGADOR QUE MAYOR PUNTAJE OBTUVO
string NombreRecord;

//VARIABLE ENTERA QUE GUARDA EL PUNTAJE MÁXIMO LOGRADO POR UN JUGADOR
int PDVrecord=0;

//VARIABLE QUE UTILIZAMOS PARA ASIGNARLE EL RETURN DE LA FUNCIÓN QUIÉNGANÓELJUEGO
int ganador;

bool noPerdioNingunaHumano=true;
bool noPerdioNingunaCPU=true;
int manoEvaluada;

    //MENU
    do{
            mostrarMenu();
            cin>>num;
            system("CLS");

    switch(num){

    case 1: nombreUsuario=pedirNombre(); //FUNCIÓN PEDIRNOMBRE() GUARDARÁ EL DATO INGRESADO EN VARIABLE NOMBREUSUARIO
            //RESETEAMOS TODAS LAS VARIABLES NECESARIAS PARA JUGAR DE CERO
            ganarDosCartasHumano=0;
            ganarDosCartasCPU=0;
            ganarRondasConsecutivasHumano=0;
            ganarRondasConsecutivasCPU=0;
            dosRondasConsecutivasHumano=0;
            dosRondasConsecutivasCPU=0;
            contadorRondasGanadasHumano=0;
            contadorRondasGanadasCPU=0;
            rondasGanadasContraMismoElementoHumano=0;
            rondasGanadasContraMismoElementoCPU=0;
            vCombinacionGanadoraHumano=false;
            vCombinacionGanadoraCPU=false,
            vCartaDesafioHumano=false;
            vCartaDesafioCPU=false,
            desafioGanarUnElementoEspecificoCPU=false;
            combinacionGanadoraHumano=false;
            combinacionGanadoraCPU=false,
            ganarDosCartasDesafio9Humano=false,
            ganarDosCartasDesafio9CPU=false;
            desafioGanarUnElementoEspecificoHumano=false;
            desafioDosCartasHumano=false;
            desafioDosCartasCPU=false;
            objetivoHumanoGeneral=false;
            objetivoCPUGeneral=false;
            ronda=0;
            acumuladorPuntajeHumano=0;
            acumuladorPuntajeCPU=0;
            noPerdioNingunaCPU=true;
            noPerdioNingunaHumano=true;

            for(x=0;x<60;x++){
                mazoHumano[x]=0;
                mazoCPU[x]=0;
                queCartasSalieron[x]=false;
                cartasGanadasHumanoDesafio9[x]=0;
                 cartasGanadasCPUDesafio9[x]=0;
            }
            //DETALLAMOS LA CARTA DESAFIO QUE LE TOCÓ AL HUMANO
            cartaDesafioHumano=cartaDesafio();
            cout<<"Tu carta desafio es: "<<detalleCartaDesafio(cartaDesafioHumano)<<endl;
            cartaDesafioCPU=cartaDesafio();
            //ENTREGAMOS CARTA DESAFÍO A CPU Y NOS ASEGURAMOS QUE NO SE REPITA CON EL WHILE SIGUIENTE
    while(cartaDesafioHumano==cartaDesafioCPU){
        cartaDesafioCPU=cartaDesafio();
    }
    //FUNCION QUE PASA LOS INDICES Y LOS LLENA DE 1 A 60 PARA QUE LUEGO TRABAJE LA FUNCION QUECARTASALIO
    llenarMazoElemento();
    system("PAUSE");
    system("CLS");

    //SI PRIMERA MANO ES TRUE, ES PORQUE ACABA DE EMPEZAR EL JUEGO Y REPARTIMOS TRES CARTAS PARA AMBOS JUGADORES

        repartirTresCartasHumano(mazoHumano,queCartasSalieron);
        cout<<"Tus tres primeras cartas son:"<<endl;
         saveDefaultColor();
        //MOSTRAMOS CON DESCRIPCIÓN LAS TRES PRIMERAS CARTAS QUE LE SALIERON AL HUMANO
        for(x=0;x<3;x++){
           cout<< descripcionCarta(mazoHumano[x])<<endl;
        }
        resetColor();
        system("PAUSE");
        system("CLS");

        //EL MAZO HUMANO SE COLOCÓ COMO DOBLE CHEQUEO PARA EVITAR QUE SE REPITAN CARTAS
        repartirTresCartasCPU(mazoCPU,mazoHumano,queCartasSalieron);

    //INICIA EL JUEGO
    while(objetivoHumanoGeneral!=true&&objetivoCPUGeneral!=true){
    //CONTAMOS LAS RONDAS
    ronda++;

    //VARIBLE NUM NECESARIA PARA QUE ENTRE AL MENU PARA ROBAR CARTA
        num=0;
     while(num!=3){
        setBackgroundColor(GREY);
        setColor(LIGHTRED);
        locate(45,8);
        cout<<"             RONDA NRO: "<<ronda <<"           "<<endl;
        resetColor();
        //FUNCION QUE MUESTRA EN PANTALLA EL PRIMER MENÚ LUEGO DE INICIAR EL JUEGO
        mostrarOpcionesJuegoPrevioRobarCarta();
        cin>>num;
        system("CLS");
        switch(num){
            case 1: cout<<"Tu carta desafio es: "<<detalleCartaDesafio(cartaDesafioHumano)<<endl;
            system("PAUSE");
            system("CLS");
            break;
            case 2: cualesSonMisCartas(mazoHumano);
            resetColor();
            system("PAUSE");
            system("CLS");
            break;
            case 3: cartaRobadaHumano=robarCartaPilaHumano(mazoHumano,queCartasSalieron);
                    cartaRobadaCPU=robarCartaPilaCPU(mazoCPU,queCartasSalieron);
                    cout<<"Robaste la carta: "<<descripcionCarta(cartaRobadaHumano)<<endl;
                    resetColor();
            system("PAUSE");
            system("CLS");
            break;
    }
}
    //VARIABLE NUM PARA QUE ENTRE A LA SEGUNDA PANTALLA
    num=0;
  while(num!=3){

        setBackgroundColor(GREY);
        setColor(LIGHTRED);
        locate(45,8);
        cout<<"             RONDA NRO: "<<ronda <<"           "<<endl;
        resetColor();
        //FUNCIÓN QUE MUESTRA EL MENÚ LUEGO DE ROBAR UNA CARTA
        mostrarOpcionesJuegoParaTirarCarta();
        cin>>num;
        system("CLS");
        switch(num){
            case 1: cout<<"Tu carta desafio es: "<<detalleCartaDesafio(cartaDesafioHumano)<<endl;
            system("PAUSE");
            system("CLS");
            break;
            case 2:cualesSonMisCartas(mazoHumano);
            resetColor();
            system("PAUSE");
            system("CLS");
            break;
            case 3: elementosEmpatados=0;
                    //HUMANO ELIJE LA CARTA A TIRAR
                    cartaHumano=tirarCartaHumano(mazoHumano);
                    //EL RAND ELIJE LA CARTA POR LA CPU
                    cartaCPU=tirarCartaCPU(mazoCPU);
                    //MOSTRAMOS EN PANTALLA LAS CARTAS SEGÚN ELEMENTO, NÚMERO Y COLOR
                    descripcionDeCartasEnChoque(cartaHumano,cartaCPU);
                    //FUNCIONES QUE NOS PERMITEN DETERMINAR QUIÉN GANÓ LA MANO
                    resultadoChoquedeCartas=evaluarChoqueElementos(cartaHumano,cartaCPU,mazoHumano,mazoCPU);
                    cout<<endl;
                    if(resultadoChoquedeCartas!=7){
                        quePasoEnEstaMano(resultadoChoquedeCartas);
                    }else {elementosEmpatados=evaluarChoqueNumeros(cartaHumano,cartaCPU);}

                    if(elementosEmpatados==1){
                        manoEvaluada=evaluarMano(nombreUsuario,ronda,cartaHumano,cartaCPU,mazoHumano,mazoCPU);
                    }else if(elementosEmpatados==2){
                    choqueNumerosGanaHumano(cartaHumano,cartaCPU,mazoHumano,mazoCPU);}else if(elementosEmpatados==3){
                    choqueNumerosGanaCPU(cartaHumano,cartaCPU,mazoHumano,mazoCPU);}
                    resetColor();
                   break;
                    }
                //CALCULOS PARA ESTADISTICAS
                if(resultadoChoquedeCartas==1||resultadoChoquedeCartas==2||resultadoChoquedeCartas==3){
                    contadorRondasGanadasHumano++;
                }else if(resultadoChoquedeCartas==4||resultadoChoquedeCartas==5||resultadoChoquedeCartas==6){
                contadorRondasGanadasCPU++;}

                if(elementosEmpatados==2){
                    rondasGanadasContraMismoElementoHumano+=5;
                }else if(elementosEmpatados==3){
                    rondasGanadasContraMismoElementoCPU+=5;
                }else if(elementosEmpatados==1&&ronda%2==0){
                rondasGanadasContraMismoElementoHumano+=5;}else if(elementosEmpatados==1&&ronda%2!=0){
                rondasGanadasContraMismoElementoCPU+=5;}

                //ENUNCIADO TP
                    if(resultadoChoquedeCartas==1||resultadoChoquedeCartas==2||resultadoChoquedeCartas==3||elementosEmpatados==2||manoEvaluada==1){
                        noPerdioNingunaCPU=false;
                    }

                    if(resultadoChoquedeCartas==4||resultadoChoquedeCartas==5||resultadoChoquedeCartas==6||elementosEmpatados==3||manoEvaluada==2){
                        noPerdioNingunaHumano=false;
                    }

            }
                //EVALUAR OBJETIVO HUMANO PARA VER SI TERMINA EL WHILE
                switch(cartaDesafioHumano){
                case 1: desafioGanarUnElementoEspecificoHumano=ganarCartaNieveHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                break;
                case 2: desafioGanarUnElementoEspecificoHumano=ganarCartaFuegoHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                break;
                case 3: desafioGanarUnElementoEspecificoHumano=ganarCartaAguaHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                break;
                case 4: desafioDosCartasHumano=ganarDosCartasRojasHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                        if(desafioDosCartasHumano==true){
                            ganarDosCartasHumano++;
                            desafioDosCartasHumano=false;
                        };
                break;
                case 5: desafioDosCartasHumano=ganarDosCartasAmarillasHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                        if(desafioDosCartasHumano==true){
                            ganarDosCartasHumano++;
                            desafioDosCartasHumano=false;
                        };
                break;
                case 6: desafioDosCartasHumano=ganarDosCartasVerdesHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                        if(desafioDosCartasHumano==true){
                            ganarDosCartasHumano++;
                            desafioDosCartasHumano=false;
                        };
                break;
                case 7: desafioDosCartasHumano=ganarDosCartasAzulesHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                        if(desafioDosCartasHumano==true){
                            ganarDosCartasHumano++;
                            desafioDosCartasHumano=false;
                        };
                break;
                case 8:desafioGanarUnElementoEspecificoHumano=ganarMismoElementoHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda);
                break;
                case 9:ganarDosCartasDesafio9Humano=ganarDosCartasMismoNumeroHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda, cartasGanadasHumanoDesafio9);
                break;
                case 10: if(ganarDosRondasConsecutivasHumano(cartaHumano,cartaCPU,cartaDesafioHumano,ronda)==true){
                    ganarRondasConsecutivasHumano++;
                }else{ganarRondasConsecutivasHumano=0;}
                break;
                }

                //EVALUAR OBJETIVO CPU PARA VER SI TERMINA EL WHILE
                switch(cartaDesafioCPU){
                case 1: desafioGanarUnElementoEspecificoCPU=ganarCartaNieveCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                break;
                case 2: desafioGanarUnElementoEspecificoCPU=ganarCartaFuegoCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                break;
                case 3: desafioGanarUnElementoEspecificoCPU=ganarCartaAguaCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                break;
                case 4: desafioDosCartasCPU=ganarDosCartasRojasCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                        if(desafioDosCartasCPU==true){
                            ganarDosCartasCPU++;
                            desafioDosCartasCPU=false;
                        };
                break;
                case 5: desafioDosCartasCPU=ganarDosCartasAmarillasCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                        if(desafioDosCartasCPU==true){
                            ganarDosCartasCPU++;
                            desafioDosCartasCPU=false;
                        };
                break;
                case 6: desafioDosCartasCPU=ganarDosCartasVerdesCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                        if(desafioDosCartasCPU==true){
                            ganarDosCartasCPU++;
                            desafioDosCartasCPU=false;
                        };
                break;
                case 7: desafioDosCartasCPU=ganarDosCartasAzulesCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                        if(desafioDosCartasCPU==true){
                            ganarDosCartasCPU++;
                            desafioDosCartasCPU=false;
                        };
                break;
                case 8:desafioGanarUnElementoEspecificoCPU=ganarMismoElementoCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda);
                break;
                case 9:ganarDosCartasDesafio9CPU=ganarDosCartasMismoNumeroCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda, cartasGanadasCPUDesafio9);
                break;
                case 10: if(ganarDosRondasConsecutivasCPU(cartaHumano,cartaCPU,cartaDesafioCPU,ronda)==true){
                    ganarRondasConsecutivasCPU++;
                }else{ganarRondasConsecutivasCPU=0;}
                break;
                }

    //PARA ESTADISTICAS HUMANO
    if(desafioGanarUnElementoEspecificoHumano==true||ganarDosCartasHumano==2||ganarDosCartasDesafio9Humano==true||ganarRondasConsecutivasHumano==2){
        vCartaDesafioHumano=true;
    }
    //IF QUE DECIDE SI EL HUMANO GANO LA PARTIDA O CONTINUA EL JUEGO
    if(combinacionGanadoraHumanoCumplida(mazoHumano)==true){

            vCombinacionGanadoraHumano=true;
            if(desafioGanarUnElementoEspecificoHumano==true||ganarDosCartasHumano==2||ganarDosCartasDesafio9Humano==true||ganarRondasConsecutivasHumano==2){
                objetivoHumanoGeneral=true;
                }
            }

    //PARA ESTADISTICAS CPU
    if(desafioGanarUnElementoEspecificoCPU==true||ganarDosCartasCPU==2||ganarDosCartasDesafio9CPU==true||ganarRondasConsecutivasCPU==2){
        vCartaDesafioCPU=true;
        }
    //IF QUE DECIDE SI LA CPU GANO LA PARTIDA O CONTINUA EL JUEGO
     if(combinacionGanadoraCPUCumplida(mazoCPU)==true){
            vCombinacionGanadoraCPU=true;
            if(desafioGanarUnElementoEspecificoCPU==true||ganarDosCartasCPU==2||ganarDosCartasDesafio9CPU==true||ganarRondasConsecutivasCPU==2){
                objetivoCPUGeneral=true;
                    }
                }

    resetColor();
    system("PAUSE");
    system("CLS");

    }
    //MOSTRAR ESTADISTICAS DEL JUGADOR QUE GANÓ. EN CASO DE CUMPLIR LOS OBJETIVOS LOS DOS JUGADORES, SE DETERMINA POR EL MAYOR PUNTAJE QUIEN GANA
    //SI TIENEN MISMO PUNTAJE, MOSTRAMOS QUE GANA HUMANO
    acumuladorPuntajeHumano=calcularEstadisticasHumano(noPerdioNingunaHumano,nombreUsuario,objetivoHumanoGeneral, objetivoCPUGeneral, vCombinacionGanadoraCPU,vCartaDesafioCPU, contadorRondasGanadasHumano, rondasGanadasContraMismoElementoHumano, resultadoChoquedeCartas, elementosEmpatados);
    acumuladorPuntajeCPU=calcularEstadisticasCPU(noPerdioNingunaCPU,objetivoCPUGeneral, objetivoHumanoGeneral, vCombinacionGanadoraHumano,vCartaDesafioHumano, contadorRondasGanadasCPU, rondasGanadasContraMismoElementoCPU,resultadoChoquedeCartas,elementosEmpatados);

    //FUNCIÓN QUE ENTRA LUEGO DE CALCULAR AMBOS PUNTAJES Y MUESTRA EN PANTALLA QUIÉN GANÓ
    ganador=quienGanoElJuego(nombreUsuario,acumuladorPuntajeHumano,acumuladorPuntajeCPU, objetivoHumanoGeneral,objetivoCPUGeneral);

    if(ganador==1){
        cout<<endl;
        cout<<"¡Ganador "<<nombreUsuario<<" con "<<acumuladorPuntajeHumano<<" puntos de victoria!"<<endl;
    }else if(ganador==2){
        cout<<endl;
        cout<<"¡Gana la CPU con "<<acumuladorPuntajeCPU<<" puntos de victoria!"<<endl;
    }else if(ganador==3){
        cout<<endl;
        cout<<"Ambos jugador cumplieron sus objetivos al mismo tiempo y tienen el mismo puntaje. Así que decidirá el azar"<<endl;
        if(decideElAzar()==1){
        cout<<endl;
        cout<<"¡El azar determinó que "<<nombreUsuario<<" es el ganador con "<<acumuladorPuntajeHumano<<" puntos de victoria!"<<endl;
        }else if(decideElAzar()==2){
        cout<<endl;
        cout<<"¡El azar determinó que la CPU es la ganadora con "<<acumuladorPuntajeCPU<<" puntos de victoria!"<<endl;}
    }
    system("PAUSE");
    system("CLS");
    break;
    case 2: if(ronda == 0){
                locate(45,10);
                cout << "No hay registros para mostrar. " << endl;
                cout<<endl;
                cout<<endl;
            }else if(BanderaRecord==false){
                    NombreRecord = nombreUsuario;
                    PDVrecord = acumuladorPuntajeHumano;
                    BanderaRecord = true;
                }else if(acumuladorPuntajeHumano > PDVrecord){
                        NombreRecord = nombreUsuario;
                        PDVrecord = acumuladorPuntajeHumano;
                    }
                if(PDVrecord!=0||ronda!=0){
                        locate(45,10);
                        cout << "El jugador "<< NombreRecord<<" tiene el record de " << PDVrecord << " PDV." << endl;}
            system ("PAUSE");
            system ("CLS");
    break;
    case 3: mostrarCreditos(num);
            system ("PAUSE");
            system ("CLS");
            cout<<endl;
    break;
    case 4: mostrarReglas(num);
            system("PAUSE");
            system ("CLS");
            cout<<endl;
    break;
    case 0: eleccion=confirmarSalida(num);
            if(eleccion==0){
                    system("CLS");
                   mostrarGraciasPorJugar();
                    num=0;
               return 0;}else{
                num=5;
               system("CLS");}
    break;
        }
}while(num!=0);

//FINAL DEL JUEGO
    mostrarGraciasPorJugar();
 return 0;
}

