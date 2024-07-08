#ifndef ARCHIVOBINARIO_H
#define ARCHIVOBINARIO_H
using namespace std;
#include <string>
#include <fstream>
#include <map>
#include "paciente.h"
///
/// \brief The ArchivoBinario class. Esta clase trabaja sobre un archivo binario tanto para lectura como escritura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class ArchivoBinario
{
public:
    ArchivoBinario();
    ///
    /// \brief Carga los estudios del paciente seleccionado.
    /// \param dni_buscado DNI del paciente seleccionado.
    /// \return Retorna la totalidad de los estudios del paciente en el archivo binario.
    ///
    vector<Estudio> cargarEstudios(int dni_buscado);
    ///
    /// \brief Setea el nombre del archivo que se desea abrir.
    /// \param value
    /// \return Retorna "true" si se pudo abrir el archivo, "false" en caso contrario.
    ///
    bool setNombre(const string &value);
    ///
    /// \brief Guarda en el archivo binario el estudio realizado.
    /// \param estudio Este parametro es el estudio realizado.
    /// \param dni DNI del paciente al que se le ha realizado el estudio.
    ///
    void guardarEstudio(Estudio estudio, int dni);

private:
    string nombre;
};

#endif // ARCHIVOBINARIO_H
