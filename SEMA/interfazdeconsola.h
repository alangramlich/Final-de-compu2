#ifndef INTERFAZDECONSOLA_H
#define INTERFAZDECONSOLA_H
#include "archivobinario.h"
#include "archivodetexto.h"
#include <QApplication>
#include "graficadordesempenio.h"
#include <stdlib.h>
#include "../CodigoInicial_JuegoDeLaMemoria_v2/juegodelamemoria.h"
#include "../Graficador2D/Juego_SC.h"
///
/// \brief The InterfazDeConsola class. Esta clase ofrece un menu con opciones que el profesional puede realizar.
/// \brief
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class InterfazDeConsola
{
public:
    InterfazDeConsola(QApplication*);
    ///
    /// \brief Muestra el menu de opciones.
    ///
    void mostrarMenu();
    ///
    /// \brief Recibe y ejecuta la opcion elegida por el profesional.
    ///
    void Opcion(int);

private:
    ///
    /// \brief Depura y ordena los estudios para poder realizar la grafica de desempeño.
    /// \param tipoDeTest
    /// \param estudios
    /// \return
    ///
    vector<Estudio> prepararVector(char tipoDeTest, vector<Estudio> estudios);
    ///
    /// \brief Le ordena al graficador de desempeño que realice la grafica.
    ///
    void graficarDesempenio(char, int, bool);
    ///
    /// \brief Se comunica con el archivo de texto para setear un nombre.
    /// \param value
    ///
    void setNombreTexto(const string &value);
    ///
    /// \brief Se comunica con el archivo binario para setear un nombre.
    /// \param value
    ///
    void setNombreBinario(const string &value);
    ///
    /// \brief Carga los datos de los pacientes para mostrarlos por consola.
    ///
    void setIndiceTexto();
    ///
    /// \brief Carga los estudios del paciente seleccionado.
    ///
    void setEstudiosMemoria(int);
    ///
    /// \brief Muestra los estudios cargados en consola.
    ///
    void listarEstudios();
    ///
    /// \brief Muestra la ecuacion de interpolacion.
    /// \param n
    /// \param x
    /// \param y
    /// \param xi
    ///
    void mostrarEcuacion(int n, float *x, float *y, float xi);
    ///
    /// \brief Funcion auxiliar para mostrar la fecha en un formato mas facil de comprender.
    /// \return
    ///
    string acomodarFecha(string);
    ///
    /// \brief Funcion auxiliar para mostrar la hora en un formato mas facil de comprender.
    /// \return
    ///
    string acomodarHora(string);
    ///
    /// \brief Funcion auxiliar para mostrar el tipo de test realizado en un formato mas facil de comprender.
    /// \return
    ///
    string acomodarTipoDeTest(char);
    JuegoDeLaMemoria* memory;
    bool paso_por_opcion_1, cargo_estudios_de_un_paciente;
    Juego_SC* juego_salto;
    int dni_estudios_cargados;
    string apellido_estudios_cargados;
    map<int, Paciente> indiceDni;
    map<string, Paciente> indiceApellido;
    ArchivoBinario* archi_bin;
    ArchivoDeTexto archi_txt;
    QApplication* ptr_app;
    GraficadorDesempenio* ptr_graf;
    string nombreBinario;
    string nombreTexto;
    vector<Estudio> estudiosMemoria;
};

#endif // INTERFAZDECONSOLA_H
