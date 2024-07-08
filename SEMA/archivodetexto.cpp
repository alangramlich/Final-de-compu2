#include "archivodetexto.h"

ArchivoDeTexto::ArchivoDeTexto()
{

}

void ArchivoDeTexto::cargar(map<int, Paciente> &MAP_DNI, map<string, Paciente> &MAP_APELLIDO)
{
    ifstream in(nombre);
    Paciente auxiliar;
    string linea, dato;
    char* p_char = new char[50];
    int primer_espacio, primera_coma;
    while(getline (in, linea)){
        primer_espacio=linea.find(' ');
        primera_coma=linea.find(',');
        linea.copy(p_char, primer_espacio);
        for (int i=0; i<=primer_espacio; i++)
            dato+=p_char[i];
        auxiliar.dni=stoi(dato);
        dato.erase();
        //cout<<auxiliar.dni;
        linea.copy(p_char, primera_coma-primer_espacio, primer_espacio);
        for (int i=1; i<(primera_coma-primer_espacio); i++)
            dato+=p_char[i];
        auxiliar.apellido=dato;
        dato.erase();
        linea.copy(p_char, linea.size()-2-primera_coma-3, primera_coma+2);
        for(unsigned long long i=0; i<linea.size()-2-primera_coma-3; i++)
            dato+=p_char[i];
        auxiliar.nombre=dato;
        dato.erase();
        linea.copy(p_char, 2, linea.size()-2);
        for(int i=0; i<2; i++)
            dato+=p_char[i];
        auxiliar.edad=stoi(dato);
        dato.erase();
        MAP_DNI[auxiliar.dni]=auxiliar;
        MAP_APELLIDO[auxiliar.apellido]=auxiliar;
        //cout<<auxiliar.dni<<auxiliar.nombre<<auxiliar.apellido<<auxiliar.edad<<endl;
    }
    in.close();
}

void ArchivoDeTexto::guardar(map<int, Paciente> indice)
{
    ofstream on(nombre);
    map<int, Paciente>::iterator it=indice.begin();
    for(unsigned int i=0; i<indice.size(); i++){
        on<<it->second.dni<<" "
         <<it->second.apellido<<", "
        <<it->second.nombre<<" "
        <<it->second.edad<<endl;
        it++;
    }

}

bool ArchivoDeTexto::setNombre(const string &value)
{
    nombre = value;
    ifstream in(nombre);
    return in.is_open();
}
