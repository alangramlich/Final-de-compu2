#ifndef JUEGO_SC_H
#define JUEGO_SC_H
#include "../SaltoDelCaballo_OpenGL/tablero.h"
#include "../SaltoDelCaballo_OpenGL/solversaltocaballo.h"
#include <QApplication>
#include <QOpenGLWidget>
#include <deque>
#include "dibujo.h"
///
/// \brief The Juego_SC class. Esta clase se encarga de realizar los test del salto del caballo.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
using namespace std;
class Juego_SC : public QOpenGLWidget
{
public:
    Juego_SC(QApplication* pApp);
    ///
    /// \brief Setea el nivel inicial y comienza el juego.
    /// \param value
    ///
    void setNivelInicio(int value);
    ///
    /// \brief Retorna el tiempo que se tardo en completar correctamente el ultimo nivel.
    /// \return
    ///
    int getTiempoDeFin() const;
    ///
    /// \brief Retorna el maximo nivel completado correctamente.
    /// \return
    ///
    int getNivel() const;
    ///
    /// \brief Se utiliza en caso de querer mostrar el caso 3.
    /// \param value
    ///
    void setCASO_3(bool value);
    ///
    /// \brief Se utiliza en caso de querer mostrar el caso 4.
    /// \param value
    ///
    void setCASO_4(bool value);

protected:
    void mousePressEvent(QMouseEvent *event);
private:
    ///
    /// \brief Setea y da inicio al nivel correspondiente. Se utiliza al hacer la transicion de niveles.
    /// \param nivel
    ///
    void setearNivel(int nivel);
    ///
    /// \brief Carga un dibujo para dibujarse en el orden establecido.
    /// \param pPtr_dib
    ///
    void cargarDibujo( Dibujo* pPtr_dib );
    ///
    /// \brief Elimina los dibujos previamente cargados.
    ///
    void limpiarDibujos();
    ///
    /// \brief Recibe la respuesta del paciente al nivel que se esta jugando.
    /// \return
    ///
    bool getEleccion() const;
    ///
    /// \brief Analiza la decision del paciente para empezar el nivel siguiente o dar un resumen del juego.
    ///
    void resumenDelNivel();
    void mostrar(int w, int h);

    QApplication* ptr_App;
    bool juegoTerminado;
    Tablero dib_tablero, dib_tablero2;
    SolverSaltoCaballo *solver, *solver2;
    Solucion sol, sol2;
    int tiempoDeInicio, tiempoDeFin;
    int nivel;
    bool inicio, borrar;
    bool CASO_4, CASO_3;
    deque<Dibujo*> ptrs_dib; // Dibujos que se han de "dibujar"
    //Juegodelcaballo* ptr_juego;
    double minX, maxX, minY, maxY;
    bool eleccion;
    // Métodos auxiliares
    void determinarDimensiones();
    // Métodos a redefinir
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    QApplication* ptr_app; // Permite controlar la aplicación.
};

#endif // JUEGO_SC_H

