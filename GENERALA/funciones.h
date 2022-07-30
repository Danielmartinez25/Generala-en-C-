#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<string.h>
#include"rlutil.h"

using namespace std;

void informacionRonda(char n[], int puntos[10][2], int l); /// informa como va la ronda
void cortarPrograma(int num);                   ///Corta el programa
void menuReglas();                              /// Muestra el menu con las reglas
void menuCombinacionesGanadoras();              /// Muestra las combinaciones ganadoras
void mostrarDados(int v[]);
void cargarVector (int v[], int tam, int fila); /// Declaración función carga vector enteros.
void mostrarVector (int v[], int tam);          /// Declaración función muestra vector enteros.
void cargarNombre1 (char v[], int tam);         /// Declaración función carga vector nombres.
void copiarNombre1 (char v[], char v2[]);        /// Declaración función muestra vector nombre.
void mostrarNombre(char v[]);
void ceroVector (int v[10], int tam);           /// Pone en 0 vector puntos.
void menosUnoVector (int v[10][2]);             /// Pone tabla de puntos en -1.
void mostrarTabla (int v[10][2], int tam, char vecNom1[20], char vecNom2[20]);      /// Muestra los puntos de cada posición del vector.
int  numeros1A6(int v[5], int numero);          /// Suma el numero que se pase por parametro
void copiarPuntos (int v[]);
void ordenarDados(int v[]);                     /// Ordena los dados de menor a mayor
int sumarVector (int v[10][2], int jug);                /// Suma los elementos dentro del vector.
void cargarAleatorio (int v[], int tam, int limite);
void unJugador (char nombre1[20], char nombre2[20], char nombreHistorico[20], int *puntajeHistorico, int &lanzamiento1, int &lanzamiento2, int &lanzamientoHistorico);                              /// Modo 1 jugador.
void unJugadorManual (char nombre[20], char nombre2[20], char nombreHistorico[20], int *puntajeHistorico, int &lanzamiento1, int &lanzamiento2, int &LanzamientoHistorico);
void dosJugadores(char nombre1[20], char nombre2[20], char nombreHistorico[20], int *puntajeHIstorico, int &lanzamiento1, int &lanzamiento2, int &lanzamientoHistorico);         /// Modo 2 jugadores.
void dosJugadoresManual (char nombre[20], char nombre2[20], char nombreHistorico[20], int *puntajeHistorico, int &lanzamiento1, int &lanzamiento2, int &lanzamientoHistorico);
void tablaPuntos ();
void rondas (int v[10], int tam);
void tirada (int v[],int tam, int puntos[10][2],int jugador, int tam2, char vecNom1[20], char vecNom2[20], int *ronda, int *j, int puntajeTotal, int &lanzamiento1, int &lanzamiento2);
void posicionVecValidacion (int posicion);
void tiradaManual (int v[], int tam);           /// Carga manualmente los dados (para probar jugabilidad).
int  puntuacion(int v[5]);                      /// Informa la puntuacion del 1 a 6
bool escalera(int v[5]);                        /// Informa si hay escalera en el vector
bool full(int v[5]);                            /// Informa si hay full en el vector
bool poker(int v[5]);                           /// Informa si hay poker en el vector
bool generala(int v[5]);                        /// Informa si hay generala en el vector
void dados (int x, int y, int valor);
void puntosDados(int x, int y, int valor);
void rectanguloDobleLinea(int x, int y, int largo, int alto);
void ganadorUnJugador(char n[], int p, int r, int &lanzamiento1, int &lanzamiento2); /// Muestra los datos al final de la partida
void ganadorDosJugador(char n[], int p, int r, int &lanzamiento1, int &lanzamiento2);
void empate (char n1[], char n2[], int p, int &t1, int &t2);
void empateGenerala(char vecNom1[],char vecNom2[], int &lanzamiento1, int &lanzamiento2, int &puntaje1, int &puntaje2);

////--------------------------------------------------------------------------------------------------------

void menuReglas(){
system("cls");
cout<<"                              ¡Bienvenido a Generala!                             "<<endl<<endl;
cout<<"                                 Reglas generales            "<<endl<<endl;
cout<<" 1. El objetivo del juego es sacar Generala Servida,o la mayor"<<endl;
cout<<"puntuacion a lo largo de 10 rondas"<<endl<<endl;
cout<<" 2. Cada ronda esta compuesta por tres lanzamientos, cuando iniciamos una ronda se toma en cuenta"<<endl;
cout<<"que se realizo el primer lanzamiento"<<endl<<endl;
cout<<" 3. Un lanzamiento consiste en tirar los cinco dados y evaluar sus valores para determinar el puntaje. "<<endl;
cout<<"Si se considera oportuno se puede volver a tirar todos o algunos de los dados en dos oportunidades mas"<<endl<<endl;
cout<<" 4. El sistema siempre preguntara al usuario si quiere realizar otro lanzamiento y cuales son los dados "<<endl;
cout<<"que quiere elegir para volver a tirar"<<endl<<endl;
system("pause");
system("cls");
}


////----------------------------------------------------------------------------------------


void menuCombinacionesGanadoras(){
system("cls");
cout<<"                              ¡Bienvenido a Generala!                             "<<endl<<endl;
cout<<"                       Combinaciones para el calculo de puntaje                "<<endl;
cout<<endl;
cout<<" 1. GENERALA: Se obtienen 5 dados con el mismo valor. En caso de sacar generala en el "<<endl;
cout<<"primer lanzamiento de cualquier ronda, se gana el partido automaticamente.PUNTAJE: 50 puntos"<<endl;
cout<<endl;
cout<<" 2. POKER: Se obtienen 4 dados con el mismo valor. PUNTAJE: 40 puntos."<<endl;
cout<<endl;
cout<<" 3. FULL: Se obtienen 3 dados con el mismo valor y 2 dados con el mismo valor. PUNTAJE: 30 puntos."<<endl;
cout<<endl;
cout<<" 4. ESCALERA: Se obtienen 5 dados enforma creciente. Puede empezar en el numero 1 o 2. PUNTAJE: 25 puntos."<<endl;
cout<<endl;
cout<<" 5. JUEGO DE NUMEROS: En caso de no obtener ninguna combinacion antes mencionada, se tomara el "<<endl;
cout<<"puntaje del resultado de multiplicar la cantidad de dados con valor repetido por ese mismo valor."<<endl;
cout<<" Nota: Siempre que se de este resultado, se tomará el valor mas alto disponible. Si obtuve 3 dados "<<endl;
cout<<"con valor 1 y dos dados con valor 5 y 6 respectivamente, el juego tomara como valor para el "<<endl;
cout<<"calculo de punto el numero 6"<<endl<<endl;
system("pause");
system("cls");
}


///---------------------------------------------------------------------------------------------------------

/// Carga un vector con numeros.
void cargarVector (int v[], int tam, int fila){
    int i, espacio=0;
    gotoxy(76,fila);
    cout<<"CARGAR DADOS: "<<endl;
    for(i=0;i<tam;i++){
        gotoxy(91+espacio,fila);
        cin>>v[i];
        espacio=espacio+2;
    }

}

///---------------------------------------------------------------------------------------------------------

/// Muestra el vector cargado con numeros.
void mostrarVector (int v[], int tam){
    int i, columna=60, fila=8;
    for(i=0;i<tam;i++){
        columna+=15;
        dados(columna,fila,v[i]);
        gotoxy(columna+1,fila+5);
        cout<<" DADO "<<i+1;

    }

}

///---------------------------------------------------------------------------------------------------------


void mostrarNombre(char v[20]){
    int i;
    for(i=0;i<10;i++){
        cout<<v[i];
    }

}



/// Carga un vector con caracteres.
void cargarNombre1 (char *v, int tam){

    cout<<"INGRESAR NOMBRE: ";
    fflush(stdin);                          ///Evita que salte la línea.
    cin.getline (v,19);

    system("cls");

}

///---------------------------------------------------------------------------------------------------------

/// Copia el vector de puntos.
void copiarPuntos(int v[]){
    int i,v2[10];
    for(i=0;i<5;i++){
        v2[i]=v[i];
    }
    mostrarVector(v2,10);
}

///---------------------------------------------------------------------------------------------------------

/// Copia vector de caracteres.
void copiarNombre1 (char v[20], char v2[20]){

    strcpy(v2,v);
}

///---------------------------------------------------------------------------------------------------------

/// Pone en 0 vector
void ceroVector (int v[], int tam){
    int i;
    for (i=0; i<tam; i++){
            v[i]=0;
    }

}

///---------------------------------------------------------------------------------------------------------

int sumarVector (int v[10][2], int jug){

    int i, total=0;
    for(i=0;i<10;i++){
        if(v[i][jug]>0){
        total=total+v[i][jug];
        }
    }
    return total;
}

///---------------------------------------------------------------------------------------------------------

/// Pone en -1 vector de tabla de puntos.
void menosUnoVector (int v[10][2]){
    int i,j;
    for (i=0; i<10; i++){
        for (j=0; j<2; j++){
            v[i][j]=-1;

        }

    }

}

///---------------------------------------------------------------------------------------------------------

/// Muestra tabla con puntajes.
void mostrarTabla (int v[10][2], int tam, char vecNom1[20], char vecNom2[20]){
    int i;
    cout<<">>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"\t    TABLA DE PUNTAJES"<<endl;
    cout<<"------------------------------------------"<<endl;


    if (tam==1||tam==3){                                            ///Si es solo 1 jugador (tam) ingresa a VERDADERO.
    cout<<"\t\t"<<vecNom1<<endl<<endl;                            /// Muestra nombre jugador 1.
    for (i=0; i<10; i++){

        if (i<6){
            if(v[i][0]==-1){
              cout<<"JUEGO DE "<<i+1<<": \t   - "<<endl;
            }
            else{
            cout<<"JUEGO DE "<<i+1<<": \t   "<<v[i][0]<<endl;
            }
        }

            if(i==6){
                    if(v[i][0]==-1){
                    cout<<"ESCALERA  :\t   -"<<endl;
                    }
                    else{
                    cout<<"ESCALERA  :\t   "<<v[i][0]<<endl;
                    }
                    }

                        if(i==7){
                                if(v[i][0]==-1){
                                cout<<"FULL      :\t   -"<<endl;
                                }
                                else{
                                cout<<"FULL      :\t   "<<v[i][0]<<endl;
                                }
                                }

                                    if(i==8){
                                            if(v[i][0]==-1){
                                            cout<<"POKER     :\t   -"<<endl;
                                            }
                                            else{
                                            cout<<"POKER     :\t   "<<v[i][0]<<endl;
                                            }
                                            }

                                                if(i==9){
                                                        if(v[i][0]==-1){
                                                        cout<<"GENERALA  :\t   -"<<endl;
                                                        }
                                                        else{
                                                        cout<<"GENERALA  :\t   "<<v[i][0]<<endl;
                                                        }
                                                        }

    }

    cout<<endl;
}
    else {                                              /// Si tam es diferente a 1 muestra los puntajes de ambos jugadores.
    cout<<"\t        "<<vecNom1<<"\t       "<<vecNom2<<endl<<endl;
    for (i=0; i<10; i++){
    if (i<6){

            cout<<"JUEGO DE "<<i+1<<":\t ";

            if(v[i][0]==-1&&v[i][1]==-1){
              cout<<"  -"<<" \t\t  - "<<endl;
            }
            if(v[i][0]>=0&&v[i][1]==-1){
              cout<<"  "<<v[i][0]<<" \t\t  - "<<endl;
            }
            if(v[i][0]==-1&&v[i][1]>=0){
              cout<<"  -"<<" \t\t  "<<v[i][1]<<endl;
            }
            if(v[i][0]>=0&&v[i][1]>=0){
              cout<<"  "<<v[i][0]<<" \t\t  "<<v[i][1]<<endl;
            }

    }


            if(i==6){
                    if(v[i][0]==-1&&v[i][1]==-1){
                    cout<<"ESCALERA  : \t   -"<<" \t\t  - "<<endl;
                    }
                    if(v[i][0]>=0&&v[i][1]==-1){
                    cout<<"ESCALERA  :\t   "<<v[i][0]<<"\t\t  -"<<endl;
                    }
                    if(v[i][0]==-1&&v[i][1]>=0){
                    cout<<"ESCALERA  : \t   -"<<"\t\t  "<<v[i][1]<<endl;
                    }
                    if(v[i][0]>=0&&v[i][1]>=0){
                    cout<<"ESCALERA  :\t   "<<v[i][0]<<" \t\t  "<<v[i][1]<<endl;
                    }
            }
                            if(i==7){
                                if(v[i][0]==-1&&v[i][1]==-1){
                                cout<<"FULL      :\t   -"<<" \t\t  - "<<endl;
                                }
                                if(v[i][0]>=0&&v[i][1]==-1){
                                cout<<"FULL      :\t   "<<v[i][0]<<" \t\t  - "<<endl;
                                }
                                if(v[i][0]==-1&&v[i][1]>=0){
                                cout<<"FULL      :\t   -"<<" \t\t  "<<v[i][1]<<endl;
                                }
                                if(v[i][0]>=0&&v[i][1]>=0){
                                cout<<"FULL      :\t   "<<v[i][0]<<" \t\t  "<<v[i][1]<<endl;
                                }
                            }

                                        if(i==8){
                                            if(v[i][0]==-1&&v[i][1]==-1){
                                            cout<<"POKER     :\t   -"<<" \t\t  - "<<endl;
                                            }
                                            if(v[i][0]>=0&&v[i][1]==-1){
                                            cout<<"POKER     :\t   "<<v[i][0]<<" \t\t  - "<<endl;
                                            }
                                            if(v[i][0]==-1&&v[i][1]>=0){
                                            cout<<"POKER     :\t   -"<<" \t\t  "<<v[i][1]<<endl;
                                            }
                                            if(v[i][0]>=0&&v[i][1]>=0){
                                            cout<<"POKER     :\t   "<<v[i][0]<<" \t\t  "<<v[i][1]<<endl;
                                            }
                                        }


                                                    if(i==9){
                                                        if(v[i][0]==-1&&v[i][1]==-1){
                                                        cout<<"GENERALA  :\t   -"<<" \t\t  - "<<endl;
                                                        }
                                                        if(v[i][0]>=0&&v[i][1]==-1){
                                                        cout<<"GENERALA  :\t   "<<v[i][0]<<" \t\t  - "<<endl;
                                                        }
                                                        if(v[i][0]==-1&&v[i][1]>=0){
                                                        cout<<"GENERALA  :\t   -"<<" \t\t  "<<v[i][1]<<endl;
                                                        }
                                                        if(v[i][0]>=0&&v[i][1]>=0){
                                                        cout<<"GENERALA  :\t   "<<v[i][0]<<" \t\t  "<<v[i][1]<<endl;
                                                        }

                                                        }
    }
    cout<<endl;
    }
    cout<<"------------------------------------------"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<endl;
    }


///-----------------------------------------------------------------------------------------------------

/// Carga vector aleatoreamente entre 1 y 6.
void cargarAleatorio(int *v, int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}
///-----------------------------------------------------------------------------------------------------

///Variable que se inializa porque sino se pone en cero cada vez que entra en la funcion tirada

//int lanzamiento = 0;
//int lanzamiento2 = 0;

///------------------------------------------------------------------------------------------------------

/// Rondas 1 Jugador.
void unJugador (char nombre1[20], char nombre2[20], char nombreHistorico[20], int *puntajeHistorico, int &lanzamiento1, int &lanzamiento2, int &lanzamientoHistorico){
int i, j, vecDados[5], puntos[10][2],cantidadJug=1, jugador=0, rondas, totalPuntaje;


    menosUnoVector (puntos);
    rectanguloDobleLinea(60,12,110,18);
    gotoxy(80,13);
    cout<<"JUGADOR 1"<<endl;
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(73,16);
    cargarNombre1(nombre1,20);

    do{                                                                     /// Pregunta cuantas rondas se desean jugar.
    rectanguloDobleLinea(60,12,110,18);

    gotoxy(63,13);
    cout<<"CUANTAS RONDAS SE JUGARAN? (RANGO DEL 1 al 10)";

    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(80,16);
    cout<<"RONDAS: ";
    cin>>rondas;
    system("cls");
    if(rondas<0||rondas>10){                                                /// En caso de no ingresar un valor dentro del rango,
        rlutil::setColor(rlutil::RED);
        gotoxy(70,11);
        cout<<"INGRESE UN VALOR ENTRE 1 Y 10."<<endl<<endl;                 /// el programa avisa y vuelve a preguntar.
        rlutil::setColor(rlutil::BLACK);
    }
    }while(rondas>10||rondas<1);


    for(i=1;i<=rondas;i++){
        totalPuntaje=sumarVector(puntos,jugador);
        system("cls");
        gotoxy(60,11);
        cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
        rectanguloDobleLinea(60,12,110,18);
        gotoxy(80,13);
        cout<<"RONDA Nro "<<i<<endl;
        gotoxy(61,14);
        cout<<"-------------------------------------------------"<<endl;
        gotoxy(62,15);
        cout<<"PROXIMO TURNO: "<<nombre1<<endl;
        gotoxy(62,16);
        cout<<"LANZAMIENTOS: "<<lanzamiento1<<endl;
        gotoxy(62,17);
        cout<<"PUNTAJE "<<nombre1<<": "<<totalPuntaje<<endl;

        gotoxy(66,25);
        system("pause");
        system("cls");
        mostrarTabla(puntos,cantidadJug,nombre1, nombre2);                  /// Envía a función tabla el vector de puntos, la cantidad de jugadores
                                                                            /// y el nombre.
        jugador=0;
        tirada(vecDados,5,puntos,jugador,cantidadJug,nombre1, nombre2,&i, &j, totalPuntaje, lanzamiento1, lanzamiento2);     /// Le envía a función tirada el vector de dados, el tamaño de vector dados,
                                                                            /// el vector puntos, la cantidad de jugadores (en este caso 1) y el nombre.
    }
    totalPuntaje=sumarVector(puntos,jugador);
    if(totalPuntaje>*puntajeHistorico){
        *puntajeHistorico=totalPuntaje;
        copiarNombre1(nombre1,nombreHistorico);
        lanzamientoHistorico=lanzamiento1;
    }
    ganadorUnJugador(nombre1,totalPuntaje,rondas,lanzamiento1, lanzamiento2);              /// muestra los puntos al finalizar las rondas



}

///--------------------------------------------------------------------------------------------------------

/// Rondas 2 jugadores.
void dosJugadores(char nombre1[20], char nombre2[20], char nombreHistorico[20], int *puntajeHistorico, int &lanzamiento1, int &lanzamiento2, int &lanzamientoHistorico){
int i, j, vecDados[5], puntos[10][2],cantidadJug=2, jugador, rondas, puntaje1=0, puntaje2=0;

    menosUnoVector (puntos);
    rectanguloDobleLinea(60,12,110,18);
    gotoxy(80,13);
    cout<<"JUGADOR 1"<<endl;
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(73,16);
    cargarNombre1(nombre1,20);

    rectanguloDobleLinea(60,12,110,18);
    gotoxy(80,13);
    cout<<"JUGADOR 2"<<endl;
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(73,16);
    cargarNombre1(nombre2,20);

    do{                                                                     /// Pregunta cuantas rondas se desean jugar.
    rectanguloDobleLinea(60,12,110,18);

    gotoxy(63,13);
    cout<<"CUANTAS RONDAS SE JUGARAN? (RANGO DEL 1 al 10)";

    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(80,16);
    cout<<"RONDAS: ";
    cin>>rondas;
    system("cls");
    if(rondas<0||rondas>10){                                                /// En caso de no ingresar un valor dentro del rango,
        rlutil::setColor(rlutil::RED);
        gotoxy(70,11);
        cout<<"INGRESE UN VALOR ENTRE 1 Y 10."<<endl<<endl;                  /// el programa avisa y vuelve a preguntar.
        rlutil::setColor(rlutil::BLACK);
    }
    }while(rondas>10||rondas<1);



    for(i=1;i<=rondas;i++){
        for(j=0;j<2;j++){


            system("cls");
            gotoxy(60,11);
            cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
            if(j==0){
                puntaje1=sumarVector(puntos,0);
                puntaje2=sumarVector(puntos,1);
                rectanguloDobleLinea(60,12,110,20);
                gotoxy(80,13);
                cout<<"RONDA Nro "<<i<<endl;
                gotoxy(61,14);
                cout<<"-------------------------------------------------"<<endl;
                gotoxy(62,15);
                cout<<"PROXIMO TURNO: "<<nombre1<<endl;
                gotoxy(62,16);
                cout<<"LANZAMIENTOS: "<<lanzamiento1<<endl<<endl;
                gotoxy(62,18);
                cout<<"PUNTAJE "<<nombre1<<": "<<puntaje1<<endl;
                gotoxy(62,19);
                cout<<"PUNTAJE "<<nombre2<<": "<<puntaje2<<endl;
                gotoxy(66,25);
                system("pause");
                system("cls");
            }
                else{
                    puntaje2=sumarVector(puntos,1);
                    puntaje1=sumarVector(puntos,0);
                    rectanguloDobleLinea(60,12,110,20);
                    gotoxy(80,13);
                    cout<<"RONDA Nro "<<i<<endl;
                    gotoxy(61,14);
                    cout<<"-------------------------------------------------"<<endl;
                    gotoxy(62,15);
                    cout<<"PROXIMO TURNO: "<<nombre2<<endl;
                    gotoxy(62,16);
                    cout<<"LANZAMIENTOS: "<<lanzamiento2<<endl<<endl;
                    gotoxy(62,18);
                    cout<<"PUNTAJE "<<nombre1<<": "<<puntaje1<<endl;
                    gotoxy(62,19);
                    cout<<"PUNTAJE "<<nombre2<<": "<<puntaje2<<endl;
                    gotoxy(66,25);
                    system("pause");
                    system("cls");
                }
            mostrarTabla(puntos,cantidadJug,nombre1, nombre2);               /// Muestra nombre y puntaje de ambos jugadores.
            cout<<endl;
            gotoxy(75,2);
        jugador=j;
        if(jugador==0){
        tirada(vecDados,5,puntos,jugador,cantidadJug,nombre1,nombre2,&i, &j, puntaje1, lanzamiento1, lanzamiento2);
        puntaje1=sumarVector(puntos,0);
        }
            else{
                tirada(vecDados,5,puntos,jugador,cantidadJug,nombre1,nombre2,&i, &j, puntaje2, lanzamiento1, lanzamiento2);
                puntaje2=sumarVector(puntos,1);
            }
        }
    }

        if(i==21){
            puntaje1=sumarVector(puntos,0);
            puntaje2=sumarVector(puntos,1);

                if(puntos[9][0]==50&&puntos[9][1]==50){


                    if(puntaje1>*puntajeHistorico){

                        *puntajeHistorico=puntaje1;
                        copiarNombre1(nombre1,nombreHistorico);
                        lanzamientoHistorico=lanzamiento1;
                    }
                    if(puntaje2>*puntajeHistorico){

                        *puntajeHistorico=puntaje2;
                        copiarNombre1(nombre2,nombreHistorico);
                        lanzamientoHistorico=lanzamiento2;
                    }
                    empateGenerala(nombre1,nombre2, lanzamiento1, lanzamiento2, puntaje1, puntaje2);
                }
                else{
                    if(puntos[9][0]==50&&puntos[9][1]!=50){
                        if(puntaje1>*puntajeHistorico){

                            *puntajeHistorico=puntaje1;
                            copiarNombre1(nombre1,nombreHistorico);
                            lanzamientoHistorico=lanzamiento1;
                        }

                    ganadorDosJugador(nombre1,puntaje1,rondas,lanzamiento1, lanzamiento2);
                    }
                        else {

                                if(puntaje2>*puntajeHistorico){

                                *puntajeHistorico=puntaje2;
                                copiarNombre1(nombre2,nombreHistorico);
                                lanzamientoHistorico=lanzamiento2;
                                }

                                ganadorDosJugador(nombre2,puntaje2,rondas,lanzamiento1, lanzamiento2);

                        }
                }


    }


    else{
    if (puntaje1==puntaje2){
                if(puntaje1>*puntajeHistorico&&lanzamiento1<=lanzamiento2){
                    *puntajeHistorico=puntaje1;
                    copiarNombre1(nombre1,nombreHistorico);
                    lanzamientoHistorico=lanzamiento1;
                }

                    else{
                        if(puntaje2>*puntajeHistorico){
                            *puntajeHistorico=puntaje2;
                            copiarNombre1(nombre2,nombreHistorico);
                            lanzamientoHistorico=lanzamiento2;
                        }
                    }
            empate (nombre1, nombre2, puntaje1, lanzamiento1, lanzamiento2);
        }

        if(puntaje1>puntaje2){
        puntaje1=sumarVector(puntos,0);
            if(puntaje1>*puntajeHistorico){
                *puntajeHistorico=puntaje1;
                copiarNombre1(nombre1,nombreHistorico);
                lanzamientoHistorico=lanzamiento1;
                }
        ganadorDosJugador(nombre1,puntaje1,rondas,lanzamiento1, lanzamiento2);

        }
            else{
                if(puntaje1!=puntaje2){
                puntaje1=sumarVector(puntos,1);
                    if(puntaje2>*puntajeHistorico){
                        *puntajeHistorico=puntaje2;
                        copiarNombre1(nombre2,nombreHistorico);
                        lanzamientoHistorico=lanzamiento2;
                        }
                ganadorDosJugador(nombre2,puntaje2,rondas,lanzamiento2, lanzamiento1);
                }

            }
    }
}

///--------------------------------------------------------------------------------------------------------

/// Tiradas
void tirada (int v[], int tam, int puntos[10][2], int jugador, int tam2, char vecNom1[20], char vecNom2[20], int *ronda, int *o, int puntajeTotal, int &lanzamiento1, int &lanzamiento2){
    int posicionVecValidacion[10], contador, contador2, vecDados[5], validacion[10], jug, tiro, cantDados, n, i, j, opcion,opc, uno, dos, tres, cuatro, cinco, seis;
    char decision='s';
    string nombresJuegos [10][1]={"JUEGO DE 1","JUEGO DE 2","JUEGO DE 3","JUEGO DE 4","JUEGO DE 5","JUEGO DE 6","ESCALERA", "FULL", "POKER", "GENERALA"};

    contador=0;
    while (contador<3&&(decision=='s'||decision=='S')){
            contador=contador+1;
            gotoxy(75,2);
            cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
        if(jugador==0||jugador==2){
            gotoxy(90,3);
            cout<<"  TURNO DE "<<vecNom1<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
            gotoxy(90,4);
            cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento1<<endl;
            gotoxy(75,5);
            cout<<"--------------------------------------------------------------------"<<endl<<endl;
        }
        else{
                gotoxy(90,3);
                cout<<"  TURNO DE "<<vecNom2<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
                gotoxy(90,4);
                cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento2<<endl;
                gotoxy(75,5);
                cout<<"--------------------------------------------------------------------"<<endl<<endl;
        }


                if(jugador<2&&contador==1){                                 /// 2 siempre aleatorio / 4 opción modo de tirada.
                    gotoxy(100,6);
                    cout<<"SI DESEA LANZAR...";
                    gotoxy(90,7);
                    system("pause");


                    if (contador==1&&jugador==0){
                lanzamiento1++;
            }
                else{
                    if(contador==1&&jugador==1)
                    lanzamiento2++;
                }




                gotoxy(75,2);
            cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
        if(jugador==0||jugador==2){
            gotoxy(90,3);
            cout<<"  TURNO DE "<<vecNom1<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
            gotoxy(90,4);
            cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento1<<endl;
            gotoxy(75,5);
            cout<<"--------------------------------------------------------------------"<<endl<<endl;
        }
        else{
                gotoxy(90,3);
                cout<<"  TURNO DE "<<vecNom2<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
                gotoxy(90,4);
                cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento2<<endl;
                gotoxy(75,5);
                cout<<"--------------------------------------------------------------------"<<endl<<endl;
        }






                    cargarAleatorio(vecDados,5,6);            /// Hay que habilitarlo si se quiere que siempre los tiros
                                                                //  sean aleatorios.
                }
                    else{
                        if(contador==1){
                            if(jugador==2){
                                lanzamiento1++;
                            }
                                else{
                                    lanzamiento2++;
                                }
                        gotoxy(76,8);
                        cout<<"MODO TIRADA"<<endl;                  /// Hay que deshabilitarlo si se quiere que los tiros
                        gotoxy(76,9);
                        cout<<"1- MANUAL. 2- ALEATORIO"<<endl;      /// siempre sean aleatorios.
                        gotoxy(76,10);
                        cout<<"OPCION: ";
                        cin>>tiro;                                  ///
                        if (tiro!=1){                           ///
                        cargarAleatorio(vecDados,5,6);          ///
                                                                ///
                        }                                       ///
                        else {                                  ///
                            cargarVector (vecDados,5,12);          ///
                        }

                        }

                    }






    cout<<endl;
    cout<<endl;

    if (generala(vecDados)==true && contador == 1){

    if(jugador==0||jugador==2){
    system("cls");
    puntos[9][0]=50;
    puntajeTotal=sumarVector(puntos,0);
    mostrarTabla(puntos,tam2,vecNom1,vecNom2);
    gotoxy(75,2);
    cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
    gotoxy(90,3);
    cout<<"  TURNO DE "<<vecNom1<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
    gotoxy(90,4);
    cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento1<<endl;
    gotoxy(75,5);
    cout<<"--------------------------------------------------------------------"<<endl<<endl;
    mostrarVector(vecDados,5);

    gotoxy(1,18);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    gotoxy(1,19);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    rlutil::setColor(rlutil::CYAN);
    rectanguloDobleLinea(43,25,123,33);
    rlutil::setColor(rlutil::CYAN);
    rectanguloDobleLinea(45,26,121,32);
    rlutil::setColor(rlutil::GREEN);
    gotoxy(75,28);
    cout<<"GENERALA SERVIDA"<<endl;
    rlutil::setColor(rlutil::BLACK);
    gotoxy(65,30);
    system("pause");
    system("cls");


    }

    if(jugador==1||jugador==3){
    system("cls");
    puntos[9][1]=50;
    puntajeTotal=sumarVector(puntos,1);
    mostrarTabla(puntos,tam2,vecNom1,vecNom2);
    gotoxy(75,2);
    cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
    gotoxy(90,3);
    cout<<"  TURNO DE "<<vecNom2<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
    gotoxy(90,4);
    cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento2<<endl;
    gotoxy(75,5);
    cout<<"--------------------------------------------------------------------"<<endl<<endl;
    mostrarVector(vecDados,5);

    gotoxy(1,18);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    gotoxy(1,19);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    rlutil::setColor(rlutil::CYAN);
    rectanguloDobleLinea(43,25,123,33);
    rlutil::setColor(rlutil::CYAN);
    rectanguloDobleLinea(45,26,121,32);
    rlutil::setColor(rlutil::GREEN);
    gotoxy(75,28);
    cout<<"GENERALA SERVIDA"<<endl;
    rlutil::setColor(rlutil::BLACK);
    gotoxy(65,30);
    system("pause");
    system("cls");


    rectanguloDobleLinea(45,12,129,16);
    rlutil::setColor(rlutil::GREEN);
    gotoxy(53,14);
    cout<<"FELICITACIONES "<<vecNom2<<", GANASTE LA PARTIDA CON GENERALA SERVIDA!!!!"<<endl;
    rlutil::setColor(rlutil::BLACK);
    gotoxy(65,30);
    system("pause");
    system("cls");

    }

            if(tam2==2&&(jugador==0||jugador==2)){
            jugador++;
            rectanguloDobleLinea(45,12,129,16);
            gotoxy(57,14);
            cout<<vecNom2<<" TIENE UN LANZAMIENTO PARA SACAR GENERALA Y EMPATAR"<<endl;
            cout<<endl;
            gotoxy(79,24);
            cout<<"PARA LANZAR"<<endl;
            gotoxy(67,25);
            system("pause");
            system("cls");

            mostrarTabla(puntos,tam2,vecNom1,vecNom2);

            gotoxy(90,3);
            cout<<"LANZAMIENTO PARA GENERALA DE "<<vecNom2;

            if(jugador==3){
              cargarVector(vecDados,5,6);
            }
                else{
                    cargarAleatorio(vecDados,5,6);
                }
            lanzamiento2++;
            system("cls");




            if(generala(vecDados)==true){
                puntos[9][1]=50;
                puntajeTotal=sumarVector(puntos,1);
                mostrarTabla(puntos,tam2,vecNom1,vecNom2);
                gotoxy(75,2);
                cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
                gotoxy(90,3);
                cout<<"  TURNO DE "<<vecNom2<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
                gotoxy(90,4);
                cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento2<<endl;
                gotoxy(75,5);
                cout<<"--------------------------------------------------------------------"<<endl<<endl;
                mostrarVector(vecDados,5);




                gotoxy(1,18);
                cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                gotoxy(1,19);
                cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

                rlutil::setColor(rlutil::CYAN);
                rectanguloDobleLinea(43,25,123,33);
                rlutil::setColor(rlutil::CYAN);
                rectanguloDobleLinea(45,26,121,32);
                rlutil::setColor(rlutil::GREEN);
                gotoxy(53,28);
                cout<<vecNom2<<" EMPATASTE LA PARTIDA. TAMBIEN SACASTE GENERALA SERVIDA"<<endl;
                rlutil::setColor(rlutil::BLACK);
                gotoxy(65,30);
                system("pause");
                system("cls");

            }
                else{
                    puntajeTotal=sumarVector(puntos,1);
                    mostrarTabla(puntos,tam2,vecNom1,vecNom2);
                    gotoxy(90,3);
                    cout<<"LANZAMIENTO PARA GENERALA DE "<<vecNom2;
                    mostrarVector(vecDados,5);


                    gotoxy(1,18);
                    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                    gotoxy(1,19);
                    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

                    rlutil::setColor(rlutil::RED);
                    rectanguloDobleLinea(43,25,123,33);
                    rlutil::setColor(rlutil::RED);
                    rectanguloDobleLinea(45,26,121,32);
                    rlutil::setColor(rlutil::RED);
                    gotoxy(74,28);
                    cout<<"NO SACASTE GENERALA"<<endl;
                    rlutil::setColor(rlutil::BLACK);
                    gotoxy(65,30);
                    system("pause");
                    system("cls");

                    puntos[9][1]=-1;
                    rectanguloDobleLinea(45,12,129,16);
                    rlutil::setColor(rlutil::GREEN);
                    gotoxy(53,14);
                    cout<<"FELICITACIONES "<<vecNom1<<", GANASTE LA PARTIDA CON GENERALA SERVIDA!!!!"<<endl;
                    rlutil::setColor(rlutil::BLACK);
                    gotoxy(65,30);
                    system("pause");
                    system("cls");
                }

        }




    contador=4;
    *ronda=20;
    *o=30;
    }

    else{
    system("cls");
    mostrarTabla(puntos,tam2,vecNom1,vecNom2);
    if(jugador==0||jugador==2){
        gotoxy(75,2);
        cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
        gotoxy(90,3);
        cout<<"  TURNO DE "<<vecNom1<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
        gotoxy(90,4);
        cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento1<<endl;
        gotoxy(75,5);
        cout<<"--------------------------------------------------------------------"<<endl<<endl;
    }
        else{
                gotoxy(75,2);
                cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
                gotoxy(90,3);
                cout<<"  TURNO DE "<<vecNom2<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
                gotoxy(90,4);
                cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento2<<endl;
                gotoxy(75,5);
                cout<<"--------------------------------------------------------------------"<<endl<<endl;
        }
    mostrarVector(vecDados,5);
    }

    if (contador<3){
        gotoxy(76,15);                                                    /// Pregunta volver a tirar hasta segundo tiro.
        cout<<"Desea volver a lanzar? s/n"<<endl;
        gotoxy(76,16);
        cout<<"(s) Volver a lanzar"<<endl;
        gotoxy(76,17);
        cout<<"(n) Anotar o anular juego"<<endl;
        gotoxy(76,18);
        cout<<">> ",cin>>decision;
            if (decision=='s'||decision=='S'){
                if(jugador==0||jugador==2){
                lanzamiento1 ++;
                }
                    else{
                        if(jugador==1||jugador==3){
                       lanzamiento2=lanzamiento2+1;
                        }
                    }
                gotoxy(76,19);
                cout<<"Cuantos dados?: ";
                cin>>cantDados;
                    if (cantDados<5){
                        gotoxy(76,20);
                        cout<<"Cuales? (Ingrese numero de dado) >> ";
                        if(jugador>1){
                            int salto=0;
                            for(i=0;i<cantDados;i++){
                            gotoxy(76,21+(salto));                                 /// Según los dados que elija el usuario se carga aleatoreamente esa posición (n-1).
                            cout<<"Dado numero: ";
                            cin>>n;
                            gotoxy(76,22+(salto));
                            cout<<"Que numero desea cargar en dado "<<n<<"? >> ";
                            cin>>vecDados[n-1];
                            salto=salto+2;
                        }
                        }
                        else{
                        int espaciado=0; //espaciado2=0;
                        for(i=0;i<cantDados;i++){                   /// Según los dados que elija el usuario se carga aleatoreamente esa posición (n-1).
                            gotoxy(113+(espaciado),20);
                            cin>>n;
                            gotoxy(114+(espaciado),20);
                            cout<<" / ";
                            espaciado=espaciado+4;
                            srand(time(NULL));
                            vecDados[n-1]=(rand()%6)+1;             /// Carga posiciones seleccionadas aleatoreamente.


                        }
                        }

                    }

                    else{
                        if (jugador>1){
                            cargarVector(vecDados,5,20);
                        }
                        else {
                        cargarAleatorio(vecDados,5,6);
                        }
                    }

                system("cls");

                mostrarTabla(puntos,tam2,vecNom1,vecNom2);
            }

        }

    }
                    if(contador==3){
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    }




                    if(contador<4){





                    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------";



    ceroVector (validacion,10);


// Comprobación de juegos.
    uno=numeros1A6(vecDados,1);
    if(uno>0){
        validacion [0]=uno;

    }

    dos=numeros1A6(vecDados,2);
    if(dos>0){
        validacion [1]=dos;

    }

    tres=numeros1A6(vecDados,3);
    if(tres>0){
        validacion [2]=tres;

    }

    cuatro=numeros1A6(vecDados,4);
    if(cuatro>0){
        validacion [3]=cuatro;

    }

    cinco=numeros1A6(vecDados,5);
    if(cinco>0){
        validacion [4]=cinco;

    }

    seis=numeros1A6(vecDados,6);
    if(seis>0){
        validacion [5]=seis;

    }

    if(escalera(vecDados)){
        validacion[6]=25;

    }

    if(full(vecDados)){
        validacion[7]=30;

    }

    if(poker(vecDados)){
        validacion[8]=40;
    }

    if(generala(vecDados)){
        validacion[9]=50;
    }
///--------------------------------------------------------------------------------------------------------------------
    if(jugador>1){                          /// Este IF solo tiene sentido en modo prueba (998 y 999).
    jugador=jugador-2;
    }
///--------------------------------------------------------------------------------------------------------------------


    gotoxy(70,21);
    cout<<"JUEGOS DISPONIBLES"<<endl<<endl;
    opcion=0;

    ceroVector(posicionVecValidacion,10);


    contador2=-1;
    for(j=0;j<10;j++){                                                    /// FOR que muestra las opciones de puntaje disponible.
        bool corte=false;
            for(jug=jugador;jug<2;jug++){
                while(corte==false){                                      /// Evita que ingrese a chequear jugador 2 cuando solamente tiene que chequear jugador 1.
                    if (puntos[j][jug]==-1&&validacion[j]>0){             /// Entra si puntaje en tabla está en -1 y la validacion tiene puntaje (mayor a 0).
                        opcion++;
                        contador2=contador2+1;
                        gotoxy(70,22+opcion);
                        cout<<opcion<<" - "<<nombresJuegos[j][0]<<" = "<<validacion[j]<<endl; /// Muestra opción, nombre de juego disponible y valor de combinación.
                        posicionVecValidacion[contador2]=j;
                    }
                    corte=true;
                }
            }
    }
    gotoxy(64,23+opcion);
    cout<<"0 - ANULAR ALGUNA COMBINACION"<<endl;

    cout<<endl;
    gotoxy(68,25+opcion);
    cout<<"INGRESE OPCION DESEADA: ";
    cin>>opc;
    cout<<endl;
    int linea=opcion;

    if (opc==0){
        gotoxy(0,33);
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        //gotoxy(64,35);
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t\tQUE COMBINACION DESEA ANULAR?";
        opcion=0;
        contador2=-1;
        for(j=0;j<10;j++){
                bool corte=false;
                for(jug=jugador;jug<2;jug++){
                     while(corte==false){
                     if (puntos[j][jug]==-1&&validacion[j]==0){
                        opcion++;
                        linea++;
                        contador2=contador2+1;
                        gotoxy(71,30+linea);
                        cout<<opcion<<"- "<<nombresJuegos[j][0]<<endl;
                        posicionVecValidacion[contador2]=j;

                     }
                     corte=true;
                     }
    }
         }


    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t OPCION: ";
    cin>>opc;

/// Switch selección anulación combinación.
    switch(opc){
        case 1: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[0]][jug]=0;
                    jug=2;
                }
        break;
        case 2: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[1]][jug]=0;
                    jug=2;
                }
        break;
        case 3: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[2]][jug]=0;
                    jug=2;
                }
        break;
        case 4: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[3]][jug]=0;
                    jug=2;
                }
        break;
        case 5: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[4]][jug]=0;
                    jug=2;
                }
        break;
        case 6: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[5]][jug]=0;
                    jug=2;
                }
        break;
        case 7: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[6]][jug]=0;
                    jug=2;
                }
        break;
        case 8: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[7]][jug]=0;
                    jug=2;
                }
        break;
        case 9: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[8]][jug]=0;
                    jug=2;
                }
        break;
        case 10: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[9]][jug]=0;
                    jug=2;
                }
        break;

    }

    }
    else{

/// Switch selección puntos.
    switch(opc){

        case 1: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[0]][jug]=validacion[posicionVecValidacion[0]];
                    jug=2;
                }

        break;
        case 2: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[1]][jug]=validacion[posicionVecValidacion[1]];
                    jug=2;
                }

        break;
        case 3: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[2]][jug]=validacion[posicionVecValidacion[2]];
                    jug=2;
                }

        break;
        case 4: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[3]][jug]=validacion[posicionVecValidacion[3]];
                    jug=2;
                }

        break;
        case 5: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[4]][jug]=validacion[posicionVecValidacion[4]];
                    jug=2;
                }

        break;
        case 6: for(jug=jugador;jug<2;jug++){
                    puntos[posicionVecValidacion[5]][jug]=validacion[posicionVecValidacion[5]];
                    jug=2;
                }

    }
    }

    puntajeTotal=sumarVector(puntos,jugador);

    system("cls");
    mostrarTabla(puntos,tam2,vecNom1,vecNom2);

    mostrarVector(vecDados,5);
    cout<<endl;

    if(jugador==0||jugador==2){
        gotoxy(75,2);
        cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
        gotoxy(90,3);
        cout<<"  TURNO DE "<<vecNom1<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
        gotoxy(90,4);
        cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento1<<endl;
        gotoxy(75,5);
        cout<<"--------------------------------------------------------------------"<<endl<<endl;
    }
        else{
                gotoxy(75,2);
                cout<<"-------------------------- RONDA Nro "<<*ronda<<" -----------------------------"<<endl;
                gotoxy(90,3);
                cout<<"  TURNO DE "<<vecNom2<<" | "<<"PUNTAJE TOTAL: "<<puntajeTotal<<endl;
                gotoxy(90,4);
                cout<<" TIRADA Nro "<<contador<<" | "<<"TIRADAS TOTALES: "<<lanzamiento2<<endl;
                gotoxy(75,5);
                cout<<"--------------------------------------------------------------------"<<endl<<endl;
        }
    gotoxy(1,18);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    gotoxy(1,19);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;


    rectanguloDobleLinea(45,26,121,32);
    rlutil::setColor(rlutil::GREEN);
    gotoxy(67,28);
    cout<<"SE CARGO SU PUNTAJE A LA TABLA"<<endl;
    rlutil::setColor(rlutil::BLACK);
    gotoxy(65,30);
    system("pause");                                      /// Hay que habilitarlo si queremos ver el valor de "p" dentro de las opciones.
    system("cls");
    }
    }


/// ------------------------------------------------------------------------------------------------------------------

/// Determina si es verdadera la escalera dentro del vector dados.
 bool escalera(int v[5]){
    ordenarDados(v);
    if (v[0] == 1 || v[0] == 2)
    {
        for (int i = 1; i < 5; i++){
            if (v[i] != v[i - 1] + 1)
                return false;
        }
    }
    else{
        return false;
    }
    return true;
}

/// ------------------------------------------------------------------------------------------------------------------

/// Determina si es verdadero el full dentro del vector dados.
bool full(int v[5]){
    int n1, n2 = 0, count1 = 1, count2 = 0;

    n1 = v[0];
    for (int i = 1; i < 5; i++)
    {
        if (n1 == v[i])
            count1++;
        else if (n2 == 0)
        {
            n2 = v[i];
            count2++;
        }
        else if (n2 == v[i])
            count2++;
    }

    return ((count1 == 3 && count2 == 2) || (count2 == 3 && count1 == 2));
}

/// ------------------------------------------------------------------------------------------------------------------

/// Determina si es verdadero el poker dentro del vector dados.
bool poker(int v[5])
{
    ordenarDados(v);
    int n1, n2 = 0, count1 = 1, count2 = 0;

    n1 = v[0];
    for (int i = 1; i < 5; i++)
    {
        if (n1 == v[i])
            count1++;
        else if (n2 == 0)
        {
            n2 = v[i];
            count2++;
        }
        else if (n2 == v[i])
            count2++;
    }

    return (count1 == 4 || count2 == 4);
}

/// ------------------------------------------------------------------------------------------------------------------

/// Determina si es verdadera la generala dentro del vector dados.
bool generala(int v[5]){
    for (int i = 1; i < 5; i++){
        if (v[i] != v[i - 1])
            return false;
    }

    return true;
}

/// ------------------------------------------------------------------------------------------------------------------

///Ordena el vector de dados de menor a mayor.
void ordenarDados(int v[]){
    int i,j, posmin, aux;
    for(i=0;i<5;i++){
        posmin=i;
        for(j=i+1;j<5;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

/// ----------------------------------------------------------------------------------------------------------------

/// Suma los números iguales dentro del vector.
int numeros1A6(int v[5], int numero)
{
    int suma = 0;

    for (int i = 0; i < 5; i++)
    {
        if (v[i] == numero)
            suma += numero;
    }
    return suma;
}

/// ------------------------------------------------------------------------------------------------------------------

/// Un jugador manual

void unJugadorManual (char nombre1[20], char nombre2[20], char nombreHistorico[20], int *puntaje, int &lanzamiento1, int &lanzamiento2, int &lanzamientoHistorico){
int i, j, vecDados[5], puntos[10][2],cantidadJug=1, jugador=2, rondas, totalPuntaje;

    menosUnoVector (puntos);
    rectanguloDobleLinea(60,12,110,18);
    gotoxy(80,13);
    cout<<"JUGADOR 1"<<endl;
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(73,16);
    cargarNombre1(nombre1,20);

    do{                                                                     /// Pregunta cuantas rondas se desean jugar.
    rectanguloDobleLinea(60,12,110,18);
    gotoxy(63,13);
    cout<<"CUANTAS RONDAS SE JUGARAN? (RANGO DEL 1 al 10)";
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(80,16);
    cout<<"RONDAS: ";
    cin>>rondas;
    system("cls");
    if(rondas<0||rondas>10){
        rlutil::setColor(rlutil::RED);
        gotoxy(70,11);
        cout<<"INGRESE UN VALOR ENTRE 1 Y 10."<<endl<<endl;                 /// el programa avisa y vuelve a preguntar.
        rlutil::setColor(rlutil::BLACK);
    }
    }while(rondas>10||rondas<1);



    for(i=1;i<=rondas;i++){
        totalPuntaje=sumarVector(puntos,jugador-2);
        system("cls");
        gotoxy(60,11);
        cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
        rectanguloDobleLinea(60,12,110,18);
        gotoxy(80,13);
        cout<<"RONDA Nro "<<i<<endl;
        gotoxy(61,14);
        cout<<"-------------------------------------------------"<<endl;
        gotoxy(62,15);
        cout<<"PROXIMO TURNO: "<<nombre1<<endl;
        gotoxy(62,16);
        cout<<"LANZAMIENTOS: "<<lanzamiento1<<endl;
        gotoxy(62,17);
        cout<<"PUNTAJE "<<nombre1<<": "<<totalPuntaje<<endl;

        gotoxy(66,25);
        system("pause");
        system("cls");
        mostrarTabla(puntos,cantidadJug,nombre1, nombre2);                  /// Envía a función tabla el vector de puntos, la cantidad de jugadores
                                                                            /// y el nombre.

        jugador=2;
        tirada(vecDados,5,puntos,jugador,cantidadJug,nombre1, nombre2,&i, &j, totalPuntaje, lanzamiento1, lanzamiento2);     /// Le envía a función tirada el vector de dados, el tamaño de vector dados,
                                                                            /// el vector puntos, la cantidad de jugadores (en este caso 1) y el nombre.
    }
    totalPuntaje=sumarVector(puntos,jugador-2);
    if(totalPuntaje>*puntaje){
        *puntaje=totalPuntaje;
        copiarNombre1(nombre1,nombreHistorico);
        lanzamientoHistorico=lanzamiento1;
    }
    ganadorUnJugador(nombre1,totalPuntaje,rondas,lanzamiento1, lanzamiento2);

}

///---------------------------------------------------------------------------------------------------------------------

/// Rondas 2 jugadores Manual.
void dosJugadoresManual(char nombre1[20], char nombre2[20], char nombreHistorico[20], int *puntajeHistorico, int &lanzamiento1, int &lanzamiento2, int &lanzamientoHistorico){
int i, j, u, vecDados[5], puntos[10][2],cantidadJug=2, jugador, rondas, puntaje1=0, puntaje2=0;

    menosUnoVector (puntos);
    rectanguloDobleLinea(60,12,110,18);
    gotoxy(80,13);
    cout<<"JUGADOR 1"<<endl;
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(73,16);
    cargarNombre1(nombre1,20);

    rectanguloDobleLinea(60,12,110,18);
    gotoxy(80,13);
    cout<<"JUGADOR 2"<<endl;
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(73,16);
    cargarNombre1(nombre2,20);

    do{                                                                     /// Pregunta cuantas rondas se desean jugar.
    rectanguloDobleLinea(60,12,110,18);
    gotoxy(63,13);
    cout<<"CUANTAS RONDAS SE JUGARAN? (RANGO DEL 1 al 10)";
    gotoxy(61,14);
    cout<<"-------------------------------------------------"<<endl;
    gotoxy(80,16);
    cout<<"RONDAS: ";
    cin>>rondas;
    system("cls");
    if(rondas<0||rondas>10){
        rlutil::setColor(rlutil::RED);
        gotoxy(70,11);
        cout<<"INGRESE UN VALOR ENTRE 1 Y 10."<<endl<<endl;                 /// el programa avisa y vuelve a preguntar.
        rlutil::setColor(rlutil::BLACK);
    }
    }while(rondas>10||rondas<1);



    for(i=1;i<=rondas;i++){

        for(j=0;j<2;j++){
            system("cls");
            u=j;
            gotoxy(60,11);
            cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
            if(j==0){
                puntaje1=sumarVector(puntos,0);
                puntaje2=sumarVector(puntos,1);
                rectanguloDobleLinea(60,12,110,20);
                gotoxy(80,13);
                cout<<"RONDA Nro "<<i<<endl;
                gotoxy(61,14);
                cout<<"-------------------------------------------------"<<endl;
                gotoxy(62,15);
                cout<<"PROXIMO TURNO: "<<nombre1<<endl;
                gotoxy(62,16);
                cout<<"LANZAMIENTOS: "<<lanzamiento1<<endl<<endl;
                gotoxy(62,18);
                cout<<"PUNTAJE "<<nombre1<<": "<<puntaje1<<endl;
                gotoxy(62,19);
                cout<<"PUNTAJE "<<nombre2<<": "<<puntaje2<<endl;
                gotoxy(66,25);
                system("pause");
                system("cls");
            }
                else{
                    puntaje2=sumarVector(puntos,1);
                    puntaje1=sumarVector(puntos,0);
                    rectanguloDobleLinea(60,12,110,20);
                    gotoxy(80,13);
                    cout<<"RONDA Nro "<<i<<endl;
                    gotoxy(61,14);
                    cout<<"-------------------------------------------------"<<endl;
                    gotoxy(62,15);
                    cout<<"PROXIMO TURNO: "<<nombre2<<endl;
                    gotoxy(62,16);
                    cout<<"LANZAMIENTOS: "<<lanzamiento2<<endl<<endl;
                    gotoxy(62,18);
                    cout<<"PUNTAJE "<<nombre1<<": "<<puntaje1<<endl;
                    gotoxy(62,19);
                    cout<<"PUNTAJE "<<nombre2<<": "<<puntaje2<<endl;
                    gotoxy(66,25);
                    system("pause");
                    system("cls");
                }

            mostrarTabla(puntos,cantidadJug,nombre1, nombre2);               /// Muestra nombre y puntaje de ambos jugadores.
            cout<<endl;
        jugador=u+2;
        if(jugador==2){
        tirada(vecDados,5,puntos,jugador,cantidadJug,nombre1,nombre2,&i, &j, puntaje1, lanzamiento1, lanzamiento2);
        puntaje1=sumarVector(puntos,0);
        }
            else{
                tirada(vecDados,5,puntos,jugador,cantidadJug,nombre1,nombre2,&i, &j, puntaje2, lanzamiento1, lanzamiento2);
                puntaje2=sumarVector(puntos,1);
            }


        }
    }

    if(i==21){

            puntaje1=sumarVector(puntos,0);
            puntaje2=sumarVector(puntos,1);

                if(puntos[9][0]==50&&puntos[9][1]==50){


                    if(puntaje1>*puntajeHistorico){

                        *puntajeHistorico=puntaje1;
                        copiarNombre1(nombre1,nombreHistorico);
                        lanzamientoHistorico=lanzamiento1;
                    }
                    if(puntaje2>*puntajeHistorico){

                        *puntajeHistorico=puntaje2;
                        copiarNombre1(nombre2,nombreHistorico);
                        lanzamientoHistorico=lanzamiento2;
                    }
                    empateGenerala(nombre1,nombre2, lanzamiento1, lanzamiento2, puntaje1, puntaje2);
                }
                else{
                    if(puntos[9][0]==50&&puntos[9][1]!=50){
                        if(puntaje1>*puntajeHistorico){

                            *puntajeHistorico=puntaje1;
                            copiarNombre1(nombre1,nombreHistorico);
                            lanzamientoHistorico=lanzamiento1;
                        }

                    ganadorDosJugador(nombre1,puntaje1,rondas,lanzamiento1, lanzamiento2);
                    }
                        else {

                                if(puntaje2>*puntajeHistorico){

                                *puntajeHistorico=puntaje2;
                                copiarNombre1(nombre2,nombreHistorico);
                                lanzamientoHistorico=lanzamiento2;
                                }

                                ganadorDosJugador(nombre2,puntaje2,rondas,lanzamiento1, lanzamiento2);

                        }
                }


    }

    else{
    if (puntaje1==puntaje2){
                if(puntaje1>*puntajeHistorico&&lanzamiento1<=lanzamiento2){
                    *puntajeHistorico=puntaje1;
                    copiarNombre1(nombre1,nombreHistorico);
                    lanzamientoHistorico=lanzamiento1;
                }

                    else{
                        if(puntaje2>*puntajeHistorico){
                            *puntajeHistorico=puntaje2;
                            copiarNombre1(nombre2,nombreHistorico);
                            lanzamientoHistorico=lanzamiento2;
                        }
                    }
            empate (nombre1, nombre2, puntaje1, lanzamiento1, lanzamiento2);
        }

        if(puntaje1>puntaje2){
        puntaje1=sumarVector(puntos,0);
            if(puntaje1>*puntajeHistorico){
                *puntajeHistorico=puntaje1;
                copiarNombre1(nombre1,nombreHistorico);
                lanzamientoHistorico=lanzamiento1;
                }
        ganadorDosJugador(nombre1,puntaje1,rondas,lanzamiento1, lanzamiento2);

        }
            else{
                if(puntaje1!=puntaje2){
                puntaje1=sumarVector(puntos,1);
                    if(puntaje2>*puntajeHistorico){
                        *puntajeHistorico=puntaje2;
                        copiarNombre1(nombre2,nombreHistorico);
                        lanzamientoHistorico=lanzamiento2;
                        }
                ganadorDosJugador(nombre2,puntaje2,rondas,lanzamiento2, lanzamiento1);
                }

            }
    }




}


void informacionRonda(char n[], int puntos[10][2], int l){
cout<<"Jugador: "<<n<<" | "<<"Ronda n° "<<"***"<<" | "<<"Puntaje total: "<<puntos[10][2]<< endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        if (l==1){
            cout<<"Lanzamientos restantes: "<<l<<" | "<<"¡Ultimo lanzamiento!"<<endl;
        }
        else{
            if (l==0){
                cout<<"Lanzamientos restantes: "<<l<<" | "<<"¡Ya no quedan lanzamientos!"<<endl;
            }
            else{
                cout<<"Lanzamientos restantes: "<<l<<endl;
            }
        }
        cout<<"---------------------------------------------------------------------"<<endl;
}

/// Dados
void dados (int x, int y, int valor){
    puntosDados(x,y,valor);
    int columna, fila=y;
    for(columna=x;columna<x+9;columna++){
            gotoxy(columna,fila);
            printf("%c",220);
            //gotoxy(x,3);
            //printf("%c",248);
        }
        for(columna=x;columna<x+9;columna++){
            gotoxy(columna,fila+4);
            printf("%c",223);
        }
        for(fila=y;fila<y+3;fila++){
            gotoxy(x,fila+1);

            printf("%c",219);
        }
        for(fila=y;fila<y+3;fila++){
            gotoxy(x+8,fila+1);
            printf("%c",219);

        }
}

/// Puntos de los dados
void puntosDados(int x, int y, int valor){
    if(valor==1){
    gotoxy(x+4,y+2);
    printf("%c",254);
    //gotoxy(x+4,y+5);
    }
        else{
        if(valor==2){
        gotoxy(x+2,y+1);
        printf("%c",254);

        gotoxy(x+6,y+3);
        printf("%c",254);
        }
            else{
                if(valor==3){
                gotoxy(x+2,y+1);
                printf("%c",254);

                gotoxy(x+4,y+2);
                printf("%c",254);

                gotoxy(x+6,y+3);
                printf("%c",254);
                }
                    else{
                        if(valor==4){
                        gotoxy(x+2,y+1);
                        printf("%c",254);

                        gotoxy(x+2,y+3);
                        printf("%c",254);

                        gotoxy(x+6,y+1);
                        printf("%c",254);

                        gotoxy(x+6,y+3);
                        printf("%c",254);
                        }
                            else{
                            if(valor==5){
                            gotoxy(x+2,y+1);
                            printf("%c",254);

                            gotoxy(x+2,y+3);
                            printf("%c",254);

                            gotoxy(x+4,y+2);
                            printf("%c",254);

                            gotoxy(x+6,y+1);
                            printf("%c",254);

                            gotoxy(x+6,y+3);
                            printf("%c",254);
                            }
                                else{
                                    if(valor==6){
                                    gotoxy(x+2,y+1);
                                    printf("%c",254);

                                    gotoxy(x+2,y+3);
                                    printf("%c",254);

                                    gotoxy(x+2,y+2);
                                    printf("%c",254);

                                    gotoxy(x+6,y+2);
                                    printf("%c",254);

                                    gotoxy(x+6,y+1);
                                    printf("%c",254);

                                    gotoxy(x+6,y+3);
                                    printf("%c",254);
                                    }
                                }
                            }
                    }
            }
        }
}

void rectanguloDobleLinea(int x, int y, int largo, int alto){
    int i,j;
    /// Angulo superior izquierdo.
    gotoxy(x,y);
    printf("%c",201);

    /// Angulo superior derecho.
    gotoxy(largo,y);
    printf("%c",187);

    /// Angulo inferior izquierdo.
    gotoxy(x,alto);
    printf("%c",200);

    /// Angulo inferior derecho.
    gotoxy(largo,alto);
    printf("%c",188);

    /// Linea horizonatal superior.
    for(i=x+1;i<largo;i++){
            gotoxy(i,y);
            printf("%c",205);
        }

    /// Linea horizonatal inferior.
    for(i=x+1;i<largo;i++){
            gotoxy(i,alto);
            printf("%c",205);
        }

    /// Linea vertical izquierda.
        cout<<endl;
    for (i=y+1;i<alto;i++){
            gotoxy(x,i);
            printf("%c",186);
            cout<<endl;
            cout<<endl;

    }

    /// Linea vertical derecha.
    for (i=y+1;i<alto;i++){
            gotoxy(largo,i);
            printf("%c",186);
            cout<<endl;
            cout<<endl;

    }

}



void cortarPrograma(int num){
    if(num == 0){
        exit(EXIT_FAILURE);
    }
}


void ganadorUnJugador(char n[], int p, int r, int &lanzamiento1, int &lanzamiento2){

        gotoxy(60,11);
        cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
        rectanguloDobleLinea(60,12,110,20);
        gotoxy(66,13);
        cout<<"FELICITACIONES, TERMINASTE EL JUEGO!!! "<<endl;
        gotoxy(61,14);
        cout<<"-------------------------------------------------"<<endl;
        gotoxy(62,16);
        cout<<"JUGADOR: "<<n<<endl;
        gotoxy(62,17);
        cout<<"CANTIDAD TOTAL DE TIROS: "<<lanzamiento1<<endl;
        gotoxy(62,18);
        cout<<"PUNTAJE TOTAL: "<<p<<endl;
        lanzamiento1=0;
        lanzamiento2=0;
        gotoxy(66,25);
        system("pause");
        system("cls");
}

void ganadorDosJugador(char n[], int p, int r, int &lanzamiento1, int &lanzamiento2){
        gotoxy(60,11);
        cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
        rectanguloDobleLinea(60,12,110,20);

        gotoxy(77,13);
        cout<<"FELICITACIONES!!! "<<endl;
        gotoxy(61,14);
        cout<<"-------------------------------------------------"<<endl;
        gotoxy(62,16);
        cout<<"GANADOR: "<<n<<endl;
        gotoxy(62,17);
        cout<<"CANTIDAD TOTAL DE TIROS: "<<lanzamiento1<<endl;
        gotoxy(62,18);
        cout<<"PUNTAJE TOTAL: "<<p<<endl;

        lanzamiento1=0;
        lanzamiento2=0;
        gotoxy(66,25);
        system("pause");
        system("cls");
}

void empate (char n1[], char n2[], int p, int &t1, int &t2){
gotoxy(60,8);
        gotoxy(60,11);
        cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
        rectanguloDobleLinea(60,12,110,20);



        gotoxy(72,13);
        cout<<"EL JUEGO RESULTO EMPATADO "<<endl;
        gotoxy(61,14);
        cout<<"-------------------------------------------------"<<endl;
        gotoxy(62,16);
        cout<<"PUNTAJE TOTAL DE AMBOS JUGADORES: "<<p<<endl;
        gotoxy(62,17);
        cout<<"CANTIDAD TOTAL DE TIROS DE "<<n1<<": "<<t1<<endl;
        gotoxy(62,18);
        cout<<"CANTIDAD TOTAL DE TIROS DE "<<n2<<": "<<t2<<endl;
        t1=0;
        t2=0;
        gotoxy(66,25);
        system("pause");
        system("cls");


}

void empateGenerala(char vecNom1[],char vecNom2[], int &lanzamiento1, int &lanzamiento2, int &puntaje1, int &puntaje2){
        gotoxy(60,11);
        cout<<">>>>>>>>>>>>>>>>>>>> GENERALA <<<<<<<<<<<<<<<<<<<<<"<<endl;
        rectanguloDobleLinea(60,12,110,25);


        gotoxy(72,13);
        cout<<"EL JUEGO RESULTO EMPATADO "<<endl;
        gotoxy(61,14);
        cout<<"-------------------------------------------------"<<endl;
        rlutil::setColor(rlutil::GREEN);
        gotoxy(64,16);
        cout<<"AMBOS JUGADORES OBTUVIERON GENERALA SERVIDA"<<endl;
        rlutil::setColor(rlutil::BLACK);
        gotoxy(64,18);
        cout<<"PUNTAJE TOTAL "<<vecNom1<<": "<<puntaje1<<endl;
        gotoxy(64,19);
        cout<<"TOTAL LANZAMIENTOS DE "<<vecNom1<<": "<<lanzamiento1<<endl;
        gotoxy(64,21);
        cout<<"PUNTAJE TOTAL "<<vecNom2<<": "<<puntaje2<<endl;
        gotoxy(64,22);
        cout<<"TOTAL LANZAMIENTOS DE "<<vecNom2<<": "<<lanzamiento2<<endl;
        lanzamiento1=0;
        lanzamiento2=0;
        gotoxy(66,27);
        system("pause");
        system("cls");
}
#endif
