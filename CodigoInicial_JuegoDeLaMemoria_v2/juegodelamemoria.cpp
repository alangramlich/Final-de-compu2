#include "juegodelamemoria.h"
#include "iostream"
#include <QOpenGLFunctions>
#include <QMouseEvent>

JuegoDeLaMemoria::JuegoDeLaMemoria(QApplication *pptrApp)
{
    ptrApp = pptrApp;
    srand(time(NULL));
    cambioDeMazo=false;
    margen = 0.1;
    angulo=0;
    guardarDadasVuelta=false;
    cartasSeleccionadas[0] = nullptr;
    cartasSeleccionadas[1] = nullptr;
    nivel=1;
    primerCarta=true;
    connect(&cronometro, SIGNAL(timeout()), this, SLOT(voltearCartas()));
    connect(&cronometro_animacion, SIGNAL(timeout()), this, SLOT(Animacion()));
    connect(&cronometro_animacion_doble, SIGNAL(timeout()), this, SLOT(AnimacionDoble()));
    CASO_TRES=false;

}

JuegoDeLaMemoria::~JuegoDeLaMemoria()
{
    for (unsigned int i=0; i<masoDeCartas.size(); ++i)
        if(masoDeCartas[i] != nullptr)
            delete masoDeCartas[i];
}

void JuegoDeLaMemoria::seleccionaMazo()
{
    masoDeCartas.push_back(new Carta(1, FIG_ESPIRAL, {1.0,0.0,0.0}));
    masoDeCartas.push_back(new Carta(1, FIG_ESPIRAL, {1.0,0.0,0.0}));
    masoDeCartas.push_back(new Carta(2, FIG_TRIANGULO, {1.0,0.0,0.0}));
    masoDeCartas.push_back(new Carta(2, FIG_TRIANGULO, {1.0,0.0,0.0}));
    masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
    masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
    masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
    masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
    masoDeCartas.push_back(new Carta(5, FIG_CIRCULO, {0.0,1.0,0.0}));
    masoDeCartas.push_back(new Carta(5, FIG_CIRCULO, {0.0,1.0,0.0}));
    masoDeCartas.push_back(new Carta(6, FIG_ESTRELLA, {0.0,1.0,0.0}));
    masoDeCartas.push_back(new Carta(6, FIG_ESTRELLA, {0.0,1.0,0.0}));
    masoDeCartas.push_back(new Carta(7, FIG_CUADRADO, {1.0,0.0,0.0}));
    masoDeCartas.push_back(new Carta(7, FIG_CUADRADO, {1.0,0.0,0.0}));
    masoDeCartas.push_back(new Carta(8, FIG_ONDA, {0.0,0.0,1.0}));
    masoDeCartas.push_back(new Carta(8, FIG_ONDA, {0.0,0.0,1.0}));
}

void JuegoDeLaMemoria::seleccionaMazo(int nivel)
{
    if(CASO_TRES==false){
    switch (nivel){
    case 1:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_ESPIRAL, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_ESPIRAL, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_ESTRELLA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_ESTRELLA, {1.0,0.0,0.0}));
        mesaConCartas.repartirCartas(2,2,masoDeCartas);
        break;
    case 2:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
        mesaConCartas.repartirCartas(2,3,masoDeCartas);
        break;
    case 3:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(4, FIG_CIRCULO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_CIRCULO, {0.0,0.0,1.0}));
        mesaConCartas.repartirCartas(2,4,masoDeCartas);
        break;
    case 4:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        mesaConCartas.repartirCartas(2,4,masoDeCartas);
        break;
    case 5:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(5, FIG_CIRCULO, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(5, FIG_CIRCULO, {0.0,1.0,0.0}));
        mesaConCartas.repartirCartas(2,5,masoDeCartas);
        break;
    case 6:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CIRCULO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(5, FIG_ESTRELLA, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(5, FIG_ESTRELLA, {0.0,1.0,0.0}));
        mesaConCartas.repartirCartas(2,5,masoDeCartas);
        break;
    case 7:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_ESTRELLA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_ESTRELLA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(5, FIG_ANILLO, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(5, FIG_ANILLO, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(6, FIG_FLECHA, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(6, FIG_FLECHA, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(7, FIG_FLECHA, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(7, FIG_FLECHA, {0.0,1.0,0.0}));
        mesaConCartas.repartirCartas(2,7,masoDeCartas);
        break;
    case 8:
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(1, FIG_FLECHA, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(2, FIG_CRUZ, {1.0,0.0,0.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(3, FIG_CRUZ, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(4, FIG_ANILLO, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(5, FIG_ANILLO, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(5, FIG_ANILLO, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(6, FIG_FLECHA, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(6, FIG_FLECHA, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(7, FIG_FLECHA, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(7, FIG_FLECHA, {0.0,1.0,0.0}));
        masoDeCartas.push_back(new Carta(8, FIG_ONDA, {0.0,0.0,1.0}));
        masoDeCartas.push_back(new Carta(8, FIG_ONDA, {0.0,0.0,1.0}));
        mesaConCartas.repartirCartas(4,4,masoDeCartas);
        break;
    case 9:
        cout<<"Felicidades!! juego terminado."<<endl;
    }}
    else {
        masoDeCartas.clear();
        masoDeCartas.push_back(new Carta(1, rand()%9+1, {((float)(rand()%101)/100),((float)(rand()%101)/100),((float)(rand()%101)/100)}));
        masoDeCartas.push_back(new Carta(1, rand()%9+1, {((float)(rand()%101)/100),((float)(rand()%101)/100),((float)(rand()%101)/100)}));
        masoDeCartas.push_back(new Carta(2, rand()%9+1, {((float)(rand()%101)/100),((float)(rand()%101)/100),((float)(rand()%101)/100)}));
        masoDeCartas.push_back(new Carta(2, rand()%9+1, {((float)(rand()%101)/100),((float)(rand()%101)/100),((float)(rand()%101)/100)}));
        mesaConCartas.repartirCartas(2,2,masoDeCartas);
    }
}

void JuegoDeLaMemoria::repartirCartas()
{
    mesaConCartas.repartirCartas(4,4,masoDeCartas);

}

void JuegoDeLaMemoria::iniciar()
{
    seleccionaMazo(nivel);
    resize(500,500);
    show();

    ptrApp->exec();
}


void JuegoDeLaMemoria::initializeGL()
{
    //glClearColor(0.5f,0.6f,0.5f,0.0f);
    glClearColor(colorDeFondo.rojo,colorDeFondo.verde,colorDeFondo.azul,0.0f);
}

void JuegoDeLaMemoria::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Se define espacio de graficación
    anchoMesaConCartas = mesaConCartas.getCantColumnas() + (mesaConCartas.getCantColumnas() - 1) * 0.1 + 2 * margen;
    altoMesaConCartas = mesaConCartas.getCantFilas() + (mesaConCartas.getCantFilas() -1) * 0.1 + 2 * margen;
    glOrtho(0, anchoMesaConCartas, 0, altoMesaConCartas, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void JuegoDeLaMemoria::paintGL()
{       
    resizeGL(width(), height());
    glClear(GL_COLOR_BUFFER_BIT);
    if (inicianDadasVuelta==true){
        for (int i=0; i<(int)masoDeCartas.size(); i++)
            masoDeCartas[i]->setVisible(true);
        glPushMatrix();{
            glTranslated(margen,margen,0);
            mesaConCartas.dibujar();
        }glPopMatrix();
        connect(&cronometro2, SIGNAL(timeout()), this, SLOT(InicianDadasVuelta()));
        cronometro2.start(tiempoDadasVueltaAlInicio);
    }
    else {
        glPushMatrix();{
            glTranslated(margen,margen,0);
            mesaConCartas.dibujar();
        }glPopMatrix();
    }
}

void JuegoDeLaMemoria::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && cartasSeleccionadas[1] == nullptr)
    {
        if (primerCarta==true){
            tiempoDeInicio=time(0);
            primerCarta=false;
        }
        double posX = event->x() * anchoMesaConCartas / width() - margen;
        double posY = (height() - event->y()) * altoMesaConCartas / height() - margen;
        cx = coordenadaAPosicionCuantizada(posX, anchoMesaConCartas);
        cy = coordenadaAPosicionCuantizada(posY, altoMesaConCartas);
        if (CASO_TRES==false){
        if (cx>=0 && cy>=0
                && !mesaConCartas(unsigned(cy),unsigned(cx))->getEstaEmparejada()
                && !mesaConCartas(unsigned(cy),unsigned(cx))->getVisible()) {
            if (cartasSeleccionadas[0] == nullptr) {
                cartasSeleccionadas[0] = mesaConCartas(unsigned(cy),unsigned(cx));
            } else {
                cartasSeleccionadas[1] = mesaConCartas(unsigned(cy),unsigned(cx));
                // Verificar si son iguales
                if (cartasSeleccionadas[0]->getId() == cartasSeleccionadas[1]->getId()) {
                    // Marcamos que las encontramos
                    cartasSeleccionadas[0]->setEstaEmparejada(true);
                    cartasSeleccionadas[1]->setEstaEmparejada(true);
                    // Ya no estan seleccionadas
                    cartasSeleccionadas[0] = nullptr;
                    cartasSeleccionadas[1] = nullptr;
                    // Verifico si termino el juego
                    bool terminoElJuego=false;
                    if(nivel==8){
                        terminoElJuego=true;
                        for (int i=0; i<(int)masoDeCartas.size(); i++)
                            terminoElJuego= terminoElJuego && masoDeCartas[i]->getEstaEmparejada();
                        if(terminoElJuego==true){
                            tiempoFinDelJuego=time(0)-tiempoDeInicio;
                            nivel++;
                            seleccionaMazo(nivel);
                            //std::cout<<"El tiempo fue: "<<tiempoFinDelJuego-tiempoDeInicio<<" segundos"<<endl;
                        }
                    }
                    // Verifico si termino el nivel
                    bool terminoElNivel=true;
                    for (int i=0; i<(int)masoDeCartas.size(); i++)
                        terminoElNivel= terminoElNivel && masoDeCartas[i]->getEstaEmparejada();
                    if(terminoElNivel==true && nivel!=8 && terminoElJuego==false){
                        tiempoFinDelJuego=time(0)-tiempoDeInicio;
                        tiempoDeInicio=time(0);
                        nivel++;
                        cambioDeMazo=true;
                        seleccionaMazo(nivel);
                        if (guardarDadasVuelta)
                            inicianDadasVuelta=true;
                        update();
                    }
                } else {
                    // Activar timer
                    cronometro_animacion_doble.start(tiempoDadasVueltaSiSonDiferentes);
                    //cronometro.start(tiempoDadasVueltaSiSonDiferentes);
                }
            }
            if (cambioDeMazo)
                cambioDeMazo=false;
            else{
                cronometro_animacion.start(1);
            }
            update();
        }
    }
        else {
            cronometro_animacion.start();
        }
    }}

void JuegoDeLaMemoria::setCASO_TRES(bool value)
{
    CASO_TRES = value;
}

int JuegoDeLaMemoria::getNivel() const
{
    return nivel;
}

void JuegoDeLaMemoria::setNivel(int value)
{
    nivel = value;
}


void JuegoDeLaMemoria::setInicianDadasVuelta(bool value)
{
    inicianDadasVuelta = value;
    guardarDadasVuelta= value;
}

void JuegoDeLaMemoria::setColorDeFondo(const Pixel &value)
{
    colorDeFondo = value;
}

int JuegoDeLaMemoria::coordenadaAPosicionCuantizada(double pCoord, double limite)
{
    int posicion = -1;
    if (pCoord > 0 && pCoord < limite - margen){
        int c = static_cast<int>(pCoord / 1.1);
        double d = pCoord - c * 1.1;
        if (d < 1) posicion = c;
    }
    return posicion;
}

int JuegoDeLaMemoria::getTiempoFinDelJuego() const
{
    return tiempoFinDelJuego;
}

void JuegoDeLaMemoria::setTiempoDadasVueltaAlInicio(int value)
{
    tiempoDadasVueltaAlInicio = value;
}

void JuegoDeLaMemoria::setTiempoDadasVueltaSiSonDiferentes(int value)
{
    tiempoDadasVueltaSiSonDiferentes = value;
}

void JuegoDeLaMemoria::voltearCartas()
{
    cronometro.stop();
    // Se dan vuelta las cartas
    cartasSeleccionadas[0]->setVisible(false);
    cartasSeleccionadas[1]->setVisible(false);
    // Ya no estan seleccionadas
    cartasSeleccionadas[0] = nullptr;
    cartasSeleccionadas[1] = nullptr;
    update();
}

void JuegoDeLaMemoria::InicianDadasVuelta()
{
    cronometro2.stop();
    inicianDadasVuelta=false;
    for (int i=0; i<(int)masoDeCartas.size(); i++)
        masoDeCartas[i]->setVisible(false);
    glPushMatrix();{
        glTranslated(margen,margen,0);
        mesaConCartas.dibujar();
    }glPopMatrix();
    update();
}

void JuegoDeLaMemoria::Animacion()
{
    cronometro_animacion.stop();
    angulo+=15;
    mesaConCartas(unsigned(cy),unsigned(cx))->setAngulo(angulo);
    if(angulo==90){
        if(mesaConCartas(unsigned(cy),unsigned(cx))->getVisible())
            mesaConCartas(unsigned(cy),unsigned(cx))->setVisible(false);
        else
            mesaConCartas(unsigned(cy),unsigned(cx))->setVisible(true);
        mesaConCartas(unsigned(cy),unsigned(cx))->setAngulo(91);
    }
    if(angulo==180){
        angulo=0;
    }
    else
        cronometro_animacion.start(1);
    update();
}

void JuegoDeLaMemoria::AnimacionDoble()
{
    cronometro_animacion_doble.stop();
    angulo+=15;
    cartasSeleccionadas[0]->setAngulo(angulo);
    cartasSeleccionadas[1]->setAngulo(angulo);
    if(angulo==90){
        if(mesaConCartas(unsigned(cy),unsigned(cx))->getVisible()){
            cartasSeleccionadas[0]->setVisible(false);
            cartasSeleccionadas[1]->setVisible(false);
        }
        else {
            cartasSeleccionadas[0]->setVisible(true);
            cartasSeleccionadas[1]->setVisible(true);
        }
        cartasSeleccionadas[0]->setAngulo(91);
        cartasSeleccionadas[1]->setAngulo(91);
    }
    if(angulo==180){
        angulo=0;
        cartasSeleccionadas[0] = nullptr;
        cartasSeleccionadas[1] = nullptr;
    }
    else
        cronometro_animacion_doble.start(1);
    update();
}

