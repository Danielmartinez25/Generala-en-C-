#include <iostream>
#include<cstdlib>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>


using namespace std;

#include "funciones.h"
#include "rlutil.h"

int main(){
    int opc, puntajeHistorico=0,lanzamiento1=0, lanzamiento2=0, lanzamientoHistorico=0;
    char nombreJug1[20], nombreJug2[20], nombreHistorico[20]="------";

rlutil::setBackgroundColor(rlutil:: GREY);
rlutil::setColor(rlutil::BLACK);




    while (true){
    gotoxy(60,11);
    cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
    rectanguloDobleLinea(60,12,110,25);
    gotoxy(83,13);
    cout<<"MENU"<<endl;
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(62,16);
    cout<<"1- UN JUGADOR"<<endl;
    gotoxy(62,17);
    cout<<"2- DOS JUGADORES"<<endl;
    gotoxy(62,18);
    cout<<"3- REGLAS DEL JUEGO"<<endl;
    gotoxy(62,19);
    cout<<"4- COMBINACIONES GANADORAS"<<endl;
    gotoxy(62,20);
    cout<<"5- PUNTUACION MAS ALTA DEL JUEGO"<<endl;
    gotoxy(62,21);
    cout<<"0- SALIR"<<endl;
    gotoxy(61,23);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(81,24);
    cout<<"OPCION: ";
    cin>>opc;
    cout<<endl;

    system("cls");

    switch (opc){
        case 1: unJugador(nombreJug1, nombreJug2, nombreHistorico, &puntajeHistorico, lanzamiento1, lanzamiento2, lanzamientoHistorico);
        break;
        case 2: dosJugadores(nombreJug1, nombreJug2, nombreHistorico, &puntajeHistorico, lanzamiento1, lanzamiento2, lanzamientoHistorico);
        break;
        case 3:
        menuReglas();
        break;
        case 4:
        menuCombinacionesGanadoras();
        break;
        case 5: rectanguloDobleLinea(60,12,110,20);
                gotoxy(76,13);
                cout<<"JUGADOR HISTORICO"<<endl;
                gotoxy(61,14);
                cout<<"-------------------------------------------------"<<endl;
                gotoxy(81,15);
                cout<<nombreHistorico<<endl;
                gotoxy(77,17);
                cout<<"PUNTAJE TOTAL: "<<puntajeHistorico<<endl;
                gotoxy(77,18);
                cout<<"LANZAMIENTOS:  "<<lanzamientoHistorico<<endl;
                gotoxy(67,25);
                system("pause");
                system("cls");
        break;
        case 998: unJugadorManual(nombreJug1, nombreJug2, nombreHistorico, &puntajeHistorico, lanzamiento1, lanzamiento2, lanzamientoHistorico);                /// Prueba un solo jugador con opción de lanzar dados maualmente.
        break;
        case 999: dosJugadoresManual(nombreJug1, nombreJug2, nombreHistorico, &puntajeHistorico, lanzamiento1, lanzamiento2, lanzamientoHistorico);
        break;
        case 0: rectanguloDobleLinea(59,12,110,18);
                gotoxy(78,15);
                cout<<"FIN DEL JUEGO"<<endl;
                gotoxy(78,20);
                return 0;
        break;

        default:gotoxy(78,15);
                rectanguloDobleLinea(59,12,110,18);
                rlutil::setColor(rlutil::RED);
                gotoxy(76,15);
                cout<<"INGRESO INVALIDO"<<endl<<endl;
                rlutil::setColor(rlutil::BLACK);
                gotoxy(66,25);
                system("pause");
                system("cls");
        break;

    }

    }

return 0;
}
