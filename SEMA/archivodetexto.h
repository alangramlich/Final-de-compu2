#ifndef ARCHIVODETEXTO_H
#define ARCHIVODETEXTO_H
using namespace std;
#include <string>
#include <fstream>
#include <map>
#include "paciente.h"
///
/// \brief The ArchivoDeTexto class. Esta clase abre un archivo de texto para extraer o guardar informacion sobre los pacientes.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class ArchivoDeTexto
{
public:
    ArchivoDeTexto();
    ///
    /// \brief Carga en memoria dos contenedores MAP a utilizarse como indices.
    /// \param MAP_DNI Indice de dni-paciente.
    /// \param MAP_APELLIDO indice de apellido-paciente.
    ///
    void cargar(map<int, Paciente>& MAP_DNI, map<string, Paciente>& MAP_APELLIDO);
    ///
    /// \brief Sobreescribe el archivo de texto para guardar los datos de los pacientes.
    ///
    void guardar(map<int, Paciente>);
    ///
    /// \brief Setea el nombre del archivo.
    /// \param value
    /// \return Retorna "true" si se pudo abrir el archivo, "false" en otro caso.
    ///
    bool setNombre(const string &value);

private:
    string nombre;
};

#endif // ARCHIVODETEXTO_H
