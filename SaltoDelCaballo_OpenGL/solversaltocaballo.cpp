#include "solversaltocaballo.h"

#include <sstream>

using namespace std;

SolverSaltoCaballo::SolverSaltoCaballo()
{
    volcarSolucionEnConsola=false;
    resaltarPosicionesIncorrectas = false;
    generar_solucion_incorrecta=false;

    cantFil=8;
    cantCol=8;
    dfila[0] = -1; dcol[0] = -2;
    dfila[1] = -2; dcol[1] = -1;
    dfila[2] = -1; dcol[2] = 2;
    dfila[3] = -2; dcol[3] = 1;
    dfila[4] = 1; dcol[4] = -2;
    dfila[5] = 2; dcol[5] = -1;
    dfila[6] = 1; dcol[6] = 2;
    dfila[7] = 2; dcol[7] = 1;

    // Variables auxiliares de algoritmo recursivo
    salir = false;
    tablero = nullptr;

    finalizar_por_tiempo = true;
    tiempo_limite = 5; // En segundos
    max_profundidad = cantFil*cantCol;

    colorCabInicial.resize(3);
    colorCabFinal.resize(3);
    setColorCaballoInicial();
    setColorCaballoFinal();
}

void SolverSaltoCaballo::setFinalizarPorTiempo(bool pBandera)
{
    finalizar_por_tiempo = pBandera;
}

void SolverSaltoCaballo::setImprimirSolucion(bool pBandera)
{
    volcarSolucionEnConsola = pBandera;
}

void SolverSaltoCaballo::setMostrarPosicionesIncorrectas(bool pBandera)
{
    resaltarPosicionesIncorrectas = pBandera;
    if(resaltarPosicionesIncorrectas){
        for(unsigned int i=0; i<sol.posiciones_correctas.size(); ++i)
            if(!sol.posiciones_correctas[i])
                sol.texto_posiciones[i].setColor(0,0,1);
            else
                sol.texto_posiciones[i].setColor(1,0,0);
    }
}

void SolverSaltoCaballo::setProfundidadMaxima(unsigned pMaxProfundidad)
{
    max_profundidad = (int)(pMaxProfundidad);
}

void SolverSaltoCaballo::setLimiteDeTiempo(unsigned int segundos)
{
    tiempo_limite = segundos;
}

void SolverSaltoCaballo::setColorCaballoInicial(float pR, float pG, float pB)
{
    colorCabInicial[0]=pR;
    colorCabInicial[1]=pG;
    colorCabInicial[2]=pB;
}

void SolverSaltoCaballo::setColorCaballoFinal(float pR, float pG, float pB)
{
    colorCabFinal[0]=pR;
    colorCabFinal[1]=pG;
    colorCabFinal[2]=pB;
}

Solucion SolverSaltoCaballo::generarUnaSolucionDesde(int pF, int pC, int pCantFil, int pCantCol)
{
    cantFil = pCantFil;
    cantCol = pCantCol;
    int cantCasillas = cantFil * cantCol;
    bool sol_valida = true;
    if(pF<0||pF>=pCantFil || pC<0||pC>=pCantCol){ pF=0; pC=0; sol_valida = false; }
    sol = Solucion(pF, pC);
    sol.caballo_inicial.setColor(colorCabInicial[0], colorCabInicial[1], colorCabInicial[2]);
    // Se inicializa tablero en arreglo estático para mayor velocidad
    if(tablero != nullptr) delete [] tablero;
    tablero = new int[ cantCasillas ];
    for (int i=0; i<cantCasillas; ++i) tablero[i]=0;
    tablero[pF*pCantCol+pC]=1;
    // Se limpia solución anterior
    sol.texto_posiciones.clear();
    sol.tablero.clear();
    if(sol_valida)
        salta(pF,pC);
    return sol;
}

void SolverSaltoCaballo::salta(int finic, int cinic)
{
    int c_inicial = clock();
    int intento = 0;
    int pos_mas_profunda = 0;
    unsigned cantCasilleros = (unsigned)(cantFil*cantCol);
    unsigned upos;
    vector<int> sol_mas_profunda(cantCasilleros);
    upos = static_cast<unsigned>(finic*cantCol+cinic);
    sol_mas_profunda[upos] = 1;
    salta_recursivo(finic, cinic, 1, sol_mas_profunda, intento, c_inicial, pos_mas_profunda);
    if (generar_solucion_incorrecta==false)
    salir = false; // Para poder buscar otra solución
    sol.tablero = sol_mas_profunda;
    // Si no es correcta, se completan ceros con los números restantes
    vector<unsigned> pos_ceros;
    if(volcarSolucionEnConsola){
        cout << "Intento: " << intento
             << " - Tiempo: " << (clock()-c_inicial)/CLOCKS_PER_SEC
             << " segundos" <<endl;
        imprimirSolucion();
    }
    if( pos_mas_profunda==(cantFil*cantCol) ){
        sol.correcta = true;
    }
    else{ // nsalto < (cantFil*cantCol)
        sol.correcta = false;
        sol.posiciones_correctas = vector<bool>(sol.tablero.size(),true);
        unsigned max = unsigned(*max_element(sol.tablero.begin(), sol.tablero.begin()+cantCasilleros));
        pos_ceros.resize(unsigned(cantCasilleros-max));
        vector<int>::iterator it = sol.tablero.begin();
        for(unsigned i=0; i<pos_ceros.size(); ++i){
            it = find(it, sol.tablero.end(), 0);
            pos_ceros[i] = unsigned(it - sol.tablero.begin());
            ++it;
        }
        random_shuffle(pos_ceros.begin(),pos_ceros.end());
        for(unsigned i=0;i<pos_ceros.size();++i){
            sol.tablero[pos_ceros[i]] = int(i + max + 1);
            sol.posiciones_correctas[pos_ceros[i]] = false; // guardar saltos incorrectos
        }
    }
    int f,c,pos;
    for(f=0; f<cantFil; ++f){
        for(c=0; c<cantCol; ++c){
            pos = f*cantCol+c;
            upos = unsigned(pos);
            sol.texto_posiciones.push_back(Texto(to_string(sol.tablero[upos]),c,f));
            if((unsigned)(sol.tablero[upos]) == cantCasilleros)
                sol.caballo_final.setPosicion(c,f);
        }
    }
    setMostrarPosicionesIncorrectas(resaltarPosicionesIncorrectas);
    sol.caballo_final.setColor(colorCabFinal[0], colorCabFinal[1], colorCabFinal[2]);
}

void SolverSaltoCaballo::salta_recursivo(int finic, int cinic, int nsalto, vector<int> &sol_mas_profunda,
                                         int& intento, int &c_inicial, int &pos_mas_profunda)
{
    if (generar_solucion_incorrecta==false){
    ++intento;
    if(intento%100000000==0 && volcarSolucionEnConsola && !salir ){
        cout << "Intento: " << intento
             << " - Tiempo: " << (clock()-c_inicial)/CLOCKS_PER_SEC
             << " segundos" <<endl;
    }
    if( finalizar_por_tiempo && !salir ){
        if( unsigned((clock()-c_inicial)/CLOCKS_PER_SEC) >= tiempo_limite )
            salir = true;
    }
    if ( nsalto==(cantFil*cantCol) || nsalto >= max_profundidad ){
        salir = true;
    }
    if( !salir ){
        int nuevax, nuevay;
        int indexSuffle[8] = {0,1,2,3,4,5,6,7}; // mapeo
        if(intento<=5)
            random_shuffle(indexSuffle, indexSuffle+8); // suffle de mapeo
        for (int i=0;(i<8) ;i++){
            nuevax=cinic+dcol[indexSuffle[i]];
            nuevay=finic+dfila[indexSuffle[i]];
            if ((nuevax>=0) && (nuevay>=0)
                    && (nuevax<cantCol) && (nuevay<cantFil)
                    &&(tablero[nuevay*cantCol+nuevax]==0)){
                nsalto=nsalto+1;
                tablero[nuevay*cantCol+nuevax]=nsalto;
                if(pos_mas_profunda < nsalto){
                    copy(tablero,tablero+cantFil*cantCol,sol_mas_profunda.begin());
                    pos_mas_profunda = nsalto;
                }
                salta_recursivo(nuevay, nuevax, nsalto,
                                sol_mas_profunda, intento, c_inicial,
                                pos_mas_profunda);
                nsalto=nsalto-1;
                tablero[nuevay*cantCol+nuevax]=0;
            }
        }
    }}
}

SolverSaltoCaballo::~SolverSaltoCaballo()
{
    delete [] tablero;
}

void SolverSaltoCaballo::setGenerar_solucion_incorrecta(bool value)
{
    generar_solucion_incorrecta = value;
}

Solucion SolverSaltoCaballo::getSol() const
{
    return sol;
}

void SolverSaltoCaballo::imprimirSolucion()
{
    ostringstream out;
    out << "SOLUCION \'" << (sol.correcta?"CORRECTA":"INCORRECTA")
        <<"\' PARA EL PROBLEMA DE SALTO DEL CABALLO: " << endl;
    int f,c;
    for (f=cantFil-1; f>=0; --f){
        for (c=0; c<cantCol; ++c)
            out << setw(4) << sol.tablero[f*cantCol+c];
        out << endl;
    }
    cout << out.str();
}
