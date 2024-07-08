#ifndef GRAFICADORDESEMPENIO_H
#define GRAFICADORDESEMPENIO_H
#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <vector>
#include <paciente.h>
#include <algorithm>
#include <math.h>
#define _USE_MATH_DEFINES
///
/// \brief The GraficadorDesempenio class. Esta clase dibuja la grafica de desempeño del paciente. Tambien calcula y dibuja la ecuacion para interpolar los puntos.
/// \brief
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class GraficadorDesempenio : public QOpenGLWindow, protected QOpenGLFunctions
{
public:
    GraficadorDesempenio() {}
    GraficadorDesempenio(vector<Estudio> );
    ///
    /// \brief Setea los estudios sobre los cuales se quiere conocer el desempeño.
    /// \param value
    ///
    void setEstudios(const vector<Estudio> &value);
    ///
    /// \brief Setea si se desea o no realizar la grafica de interpolacion de los puntos.
    /// \param value
    ///
    void setGraficar_interpolacion(bool value);

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);
private:
    bool graficar_interpolacion;
    vector<Estudio> estudios;
    int maximoX, maximoY;
    float unidad_X, unidad_Y;
    ///
    /// \brief Dibuja los puntos correspondientes al estudio del paciente.
    ///
    void dibujarPunto(float, float, float, float);
    ///
    /// \brief Dibuja el fondo de la grafica.
    ///
    void dibujarFondo();
    ///
    /// \brief Dibuja las cuadriculas de la grafica.
    ///
    void dibujarCuadriculas();
    ///
    /// \brief Dibuja los ejes de la grafica.
    ///
    void dibujarEjes();
    ///
    /// \brief Dibuja una constante correspondiente al peor desempeño.
    /// \param tiempos
    ///
    void dibujarMaximo(vector<int> tiempos);
    ///
    /// \brief Dibuja una constante correspondiente al mejor desempeño.
    /// \param tiempos
    ///
    void dibujarMinimo(vector<int> tiempos);
    ///
    /// \brief Dibuja una constante correspondiente al resultado medio.
    /// \param tiempos
    ///
    void dibujarMedio(vector<int> tiempos);
    ///
    /// \brief Dibuja la grafica de desempeño uniendo los puntos correspondientes a cada test.
    /// \param tiempos
    /// \param unidad_X
    /// \param unidad_Y
    ///
    void dibujarGrafica(vector<int> tiempos, float unidad_X, float unidad_Y);
    ///
    /// \brief Dibuja la grafica de interpolacion de los puntos.
    /// \param tiempos
    /// \param unidad_X
    /// \param unidad_Y
    ///
    void dibujarInterpolacion(vector<int> tiempos, float unidad_X, float unidad_Y);
    ///
    /// \brief Calcula el valor de y correspondiente al valor pedido de xi, usando una ecuacion de interpolacion de Newton.
    /// \param n Numero de puntos.
    /// \param x Valores de x.
    /// \param y Valores de y.
    /// \param xi Valor de x sobre el que se desea calcular su correspondiente yi.
    /// \return Retorna yi.
    ///
    float newton(int n, float *x, float *y, float xi);
};

#endif // GRAFICADORDESEMPENIO_H
