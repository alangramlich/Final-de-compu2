#ifndef JUEGODELAMEMORIA_H
#define JUEGODELAMEMORIA_H
#include <windows.h>
#include <thread>
#include <chrono>
#include <QApplication>
#include <QOpenGLWidget>
#include <QTimer>
#include<stdio.h>
#include<stdlib.h>
#include "carta.h"
#include "mesa.h"
///
/// \brief The JuegoDeLaMemoria class. Esta clase se encarga de realizar el test de la memoria.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class JuegoDeLaMemoria: public QOpenGLWidget
{
    // Necesario para definir slot/signal
    Q_OBJECT
public:
    ///
    /// \brief JuegoDeLaMemoria
    /// \param pptrApp
    ///
    JuegoDeLaMemoria(QApplication* pptrApp = nullptr);

    ~JuegoDeLaMemoria();
    ///
    /// \brief Selecciona el mazo predeterminado.
    ///
    void seleccionaMazo();
    ///
    /// \brief Seleciona el mazo correspondiente al parametro nivel.
    /// \param nivel
    ///
    void seleccionaMazo(int nivel);
    ///
    /// \brief Reparte las cartas
    ///
    void repartirCartas();
    ///
    /// \brief Inicia la partida con los parametros seteados con anterioridad.
    ///
    void iniciar();
    ///
    /// \brief Setea el tiempo que tardan las cartas en darse vuelta si son diferentes.
    /// \param value
    ///
    void setTiempoDadasVueltaSiSonDiferentes(int value);
    ///
    /// \brief Setea el color de fondo.
    /// \param value
    ///
    void setColorDeFondo(const Pixel &value);
    ///
    /// \brief Setea un booleano para indicar si inician o no dadas vuelta.
    /// \param value
    ///
    void setInicianDadasVuelta(bool value);
    ///
    /// \brief Setea el tiempo que las cartas estan dadas vuelta al inicio.
    /// \param value
    ///
    void setTiempoDadasVueltaAlInicio(int value);
    ///
    /// \brief Setea el nivel inicial.
    /// \param value
    ///
    void setNivel(int value);
    ///
    /// \brief Retorna el mayor nivel completado con exito.
    /// \return
    ///
    int getNivel() const;
    ///
    /// \brief Retorna el tiempo del ultimo nivel completado con exito.
    /// \return
    ///
    int getTiempoFinDelJuego() const;
    ///
    /// \brief Setea un booleano que indica si debe ejecutarse el caso 3.
    /// \param value
    ///
    void setCASO_TRES(bool value);

protected:

    virtual void initializeGL();

    virtual void resizeGL(int w, int h);

    virtual void paintGL();

    void mousePressEvent(QMouseEvent *event);

private:
    ///
    /// \brief Procesa las coordenadas del clic para poder utilizarlas.
    /// \param pCoord
    /// \param limite
    /// \return
    ///
    int coordenadaAPosicionCuantizada(double pCoord, double limite);

    QApplication* ptrApp;

    // Mazo de cartas

    vector<Carta*> masoDeCartas;

    // Cartas seleccionadas por el paciente

    Carta* cartasSeleccionadas[2];

    bool primerCarta;

    bool CASO_TRES;
    // Tablero de cartas

    Mesa mesaConCartas;

    Pixel colorDeFondo;

    bool inicianDadasVuelta;

    bool guardarDadasVuelta;

    int nivel;

    bool cambioDeMazo;
    // Espacio de graficación

    double margen;

    double anchoMesaConCartas;

    double altoMesaConCartas;

    // Temporizador

    QTimer cronometro;

    QTimer cronometro2;

    QTimer cronometro_animacion;

    QTimer cronometro_animacion_doble;

    float angulo;

    int tiempoDadasVueltaSiSonDiferentes;

    int tiempoDadasVueltaAlInicio;

    int inicioDelay;

    int finDelay;

    int tiempoDeInicio;

    int tiempoFinDelJuego;

    int tiempoInicioNivel;

    int cx;

    int cy;

private slots:
    // Da vuelta las cartas
    ///
    /// \brief Inicia la animacion de voltear las cartas.
    ///
    void voltearCartas();
    ///
    /// \brief Voltea todas las cartas al inicio de la partida.
    ///
    void InicianDadasVuelta();
    ///
    /// \brief Da vuelta una sola carta.
    ///
    void Animacion();
    ///
    /// \brief Da vuelta dos cartas. Se usa en el caso de que las cartas seleccionadas sean diferentes.
    ///
    void AnimacionDoble();
};

#endif // JUEGODELAMEMORIA_H
