#include "archivobinario.h"

ArchivoBinario::ArchivoBinario()
{

}

vector<Estudio> ArchivoBinario::cargarEstudios(int dni_buscado)
{
    int contador=0;
    ifstream in;
    vector<Estudio> estudios;
    Estudio estudio_auxiliar;
    int dni;
    char nivel;
    char fecha[8], hora[4];
    char tipoDeTest;
    unsigned int tiempo;
    in.open(nombre, ios::binary | ios::in);
    if (in.is_open()){
        while(in.read( (char*)&dni, sizeof(dni))){
            //std::cout << "Abrio." << std::endl;

            for (int i=0; i<=7; i++)
                in.read( (char*)&fecha[i], sizeof(char));
            for (int i=0; i<=3; i++)
                in.read( (char*)&hora[i], sizeof(char));
            in.read( (char*)&tipoDeTest, sizeof(char));
            in.read( (char*)&nivel, 1);
            in.read( (char*)&tiempo, sizeof(tiempo));
            /*cout<<dni<<" ";
            cout<<fecha[0]<<fecha[1]<<fecha[2]<<fecha[3]<<fecha[4]<<fecha[5]<<fecha[6]<<fecha[7]<<" ";
            cout<<hora[0]<<hora[1]<<hora[2]<<hora[3]<<" ";
            cout<<tipoDeTest<<" ";
            cout<<nivel<<" ";
            cout<<tiempo<<endl;*/
            if(dni==dni_buscado){
                estudio_auxiliar.fecha.erase();
                for(int i=0; i<=7; i++)
                    estudio_auxiliar.fecha+=fecha[i];
                //cout<<estudio_auxiliar.fecha<<" ";
                estudio_auxiliar.hora.erase();
                for (int i=0; i<=3; i++)
                    estudio_auxiliar.hora+=hora[i];
                //cout<<estudio_auxiliar.hora<<" ";
                estudio_auxiliar.tipoDeTest=tipoDeTest;
                //cout<<estudio_auxiliar.tipoDeTest<<" ";
                estudio_auxiliar.nivel=nivel;
                //cout<<estudio_auxiliar.nivel<<" ";
                estudio_auxiliar.tiempo=tiempo;
                //cout<<estudio_auxiliar.tiempo<<endl;
                estudios.push_back(estudio_auxiliar);
                contador++;
            }
            //contador;
        }
        //cout<<"Cantidad de estudios: "<<contador<<endl;
        //cout<<"Tamanio del vector: "<<estudios.size()<<endl;
    }
    return estudios;
}

bool ArchivoBinario::setNombre(const string &value)
{
    nombre = value;
    ifstream in;
    in.open(nombre, ios::binary | ios::in);
    return in.is_open();
}

void ArchivoBinario::guardarEstudio(Estudio estudio, int dni)
{
    fstream off;
    off.open(nombre, ios::binary | ios::out | ios::in);
    off.seekp(0, ios::end);
    off.write( (char*)&dni, sizeof(dni));
    for (int i=0; i<=7; i++)
        off.write( (char*)&estudio.fecha[i], sizeof(char));
    for (int i=0; i<=3; i++)
        off.write( (char*)&estudio.hora[i], sizeof(char));
    off.write( (char*)&estudio.tipoDeTest, sizeof(char));
    off.write( (char*)&estudio.nivel, sizeof(char));
    off.write( (char*)&estudio.tiempo, sizeof(estudio.tiempo));
    off.close();
}
