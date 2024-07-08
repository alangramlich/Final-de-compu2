#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
///
/// \brief The Estudio class. Esta clase almacena informacion. No necesita metodos privados.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Estudio
{
public:
    Estudio() {};
    string fecha;
    string hora;
    char tipoDeTest;
    int nivel;
    unsigned int tiempo;
};
///
/// \brief The Paciente class. Esta clase almacena informacion. No necesita metodos privados.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Paciente
{
public:
    Paciente();
    int dni;
    string apellido;
    string nombre;
    int edad;
    bool estudiosCargados;
    vector<Estudio> estudios;
};

#endif // PACIENTE_H
