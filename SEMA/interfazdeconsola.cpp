#include "interfazdeconsola.h"

InterfazDeConsola::InterfazDeConsola(QApplication* p_app)
{
    ptr_app=p_app;
    paso_por_opcion_1=false;
    cargo_estudios_de_un_paciente=false;
}

void InterfazDeConsola::mostrarMenu()
{
        cout<<"Opcion 1: Cargar en memoria datos de pacientes a partir de archivo de texto."<<endl;
        cout<<"Opcion 2: Mostrar pacientes cargados."<<endl;
        cout<<"Opcion 3: Agregar un nuevo paciente."<<endl;
        cout<<"Opcion 4: Modificar un paciente."<<endl;
        cout<<"Opcion 5: Cargar estudios de un paciente."<<endl;
        cout<<"Opcion 6: Realizar grafica de desempenio del paciente cargado."<<endl;
        cout<<"Opcion 7: Realizar y guardar un test al paciente cargado."<<endl;
        cout<<"Opcion 0: Salir"<<endl;
}



///
/// \brief InterfazDeConsola::prepararVector
/// \param tipoDeTest
/// \param estudios
/// \return
///
vector<Estudio> InterfazDeConsola::prepararVector(char tipoDeTest, vector<Estudio> estudios)
{
    vector<Estudio> estudiosDepurados;
    for (int i=0; i<(int)estudios.size(); i++)
        if (estudios[i].tipoDeTest==tipoDeTest)
            estudiosDepurados.push_back(estudios[i]);
    map<string, Estudio> indiceFechaYHora;
    for(int i=0; i<(int)estudiosDepurados.size(); i++)
        indiceFechaYHora[estudiosDepurados[i].fecha+estudiosDepurados[i].hora]=estudiosDepurados[i];
    estudiosDepurados.clear();
    map<string, Estudio>::iterator it=indiceFechaYHora.begin();
    for(int i=0; i<(int)indiceFechaYHora.size(); i++){
        estudiosDepurados.push_back(it->second);
        it++;
    }
    return estudiosDepurados;
}

void InterfazDeConsola::graficarDesempenio(char tipoDeTest, int  nivelElegido, bool interpolacion)
{
    vector<Estudio> vectorDepurado=prepararVector(tipoDeTest, estudiosMemoria);
    vector<Estudio>::iterator it=vectorDepurado.begin();
    while (it!=vectorDepurado.end()){
        if (it->nivel!=nivelElegido)
            it=vectorDepurado.erase(it);
        else
            it++;
    }
    float x[vectorDepurado.size()];
    float y[vectorDepurado.size()];
    for (unsigned int i=0; i<vectorDepurado.size(); i++){
        y[i]=vectorDepurado[i].tiempo;
        x[i]=i+1;
    }
    //MUESTRO EL VECTOR QUE SE VA A GRAFICAR
    for (unsigned int i=0; i<vectorDepurado.size(); i++){
        cout<<"Fecha: "<<acomodarFecha(vectorDepurado[i].fecha)<<
              " Hora: "<<acomodarHora(vectorDepurado[i].hora)<<
              " Tipo de test: "<<acomodarTipoDeTest(vectorDepurado[i].tipoDeTest)<<
              " Nivel: "<<vectorDepurado[i].nivel<<
              " Tiempo: "<<vectorDepurado[i].tiempo<<endl;
    }
    if(interpolacion)
        mostrarEcuacion(vectorDepurado.size(), x, y, 1);
    ptr_graf=new GraficadorDesempenio(vectorDepurado);
    ptr_graf->setGraficar_interpolacion(interpolacion);
    ptr_graf->resize(400, 400);
    ptr_graf->show();
    ptr_app->exec();
}

void InterfazDeConsola::setNombreTexto(const string &value)
{
    nombreTexto = value;
}

void InterfazDeConsola::setNombreBinario(const string &value)
{
    nombreBinario = value;
}

void InterfazDeConsola::setIndiceTexto()
{
    if(archi_txt.setNombre(nombreTexto)){
    archi_txt.cargar(indiceDni, indiceApellido);
    paso_por_opcion_1=true;
    }
    else
        cout<<"No se pudo abrir el archivo."<<endl;
}

void InterfazDeConsola::setEstudiosMemoria(int dni)
{
    archi_bin=new ArchivoBinario;
    if(archi_bin->setNombre(nombreBinario)){
    estudiosMemoria=archi_bin->cargarEstudios(dni);
    cargo_estudios_de_un_paciente=true;
    }
    else
        cout<<"No se pudo abrir el archivo."<<endl;
    delete(archi_bin);
}

void InterfazDeConsola::listarEstudios()
{
    cout<<"Cantidad de estudios: "<<estudiosMemoria.size()<<endl;
    cout<<">"<<dni_estudios_cargados<<endl;
    cout<<">"<<indiceDni[dni_estudios_cargados].apellido<<", "<<
          indiceDni[dni_estudios_cargados].nombre<<", "<<
          indiceDni[dni_estudios_cargados].edad<<endl;
    for (unsigned int i=0; i<estudiosMemoria.size(); i++){
        cout<<">Test: "<<acomodarTipoDeTest(estudiosMemoria[i].tipoDeTest)<<" - "
            <<"Fecha: "<<acomodarFecha(estudiosMemoria[i].fecha)
            <<" Hora: "<<acomodarHora(estudiosMemoria[i].hora)<<" hs - "
            <<"Nivel: "<<estudiosMemoria[i].nivel<<" - "
            <<estudiosMemoria[i].tiempo<<" segundos."<<endl;;
    }
}

void InterfazDeConsola::Opcion(int opcion_ingresada)
{
    switch (opcion_ingresada){
    case 1: {
        cout<<"Ingrese el nombre del archivo de texto: ";
        cin>>nombreTexto;
        //nombreTexto="DatosDePacientes_SEMA_v1.txt";
        cout<<endl;
        setIndiceTexto();
        break;
    }
    case 2: {
        if(paso_por_opcion_1){
        map<string, Paciente>::iterator it=indiceApellido.begin();
        for (int i=0; i<(int)indiceDni.size(); i++){
            cout<<it->second.dni<<"  "<<it->second.apellido<<", "<<it->second.nombre<<", "<<it->second.edad<<endl;
            it++;
        }}
        else
            cout<<"Necesita primero cargar los datos con la opcion 1."<<endl;
        break;
    }
    case 3: {
        if (paso_por_opcion_1){
        Paciente auxiliar;
        cout<<"Ingrese los datos del paciente: "<<endl;
        cout<<"DNI: "; cin>>auxiliar.dni;
        cout<<"Apellido: "; cin.ignore(); getline(cin, auxiliar.apellido);
        cout<<"Nombre: "; getline(cin, auxiliar.nombre);
        cout<<"Edad: "; cin>>auxiliar.edad;
        indiceDni[auxiliar.dni]=auxiliar;
        indiceApellido[auxiliar.apellido]=auxiliar;
        archi_txt.guardar(indiceDni);
        }
        else
            cout<<"Necesita primero cargar los datos con la opcion 1."<<endl;
        break;
    }
    case 4: {
        if (paso_por_opcion_1){
        int uno_o_dos, dni_a_modificar;
        string apellido_a_modificar;
        Paciente auxiliar;
        map<int, Paciente>::iterator it_indiceDni=indiceDni.begin();
        map<string, Paciente>::iterator it_indiceApellido=indiceApellido.begin();
        cout<<"Ingrese 1 para modificar por DNI, 2 para modificar por apellido."<<endl;
        cin>>uno_o_dos;
        switch (uno_o_dos){
        case 1: {
            cout<<"Ingrese el DNI del paciente que desea modificar, tal como aparece en el registro: ";
            cin>>dni_a_modificar;
            it_indiceDni = indiceDni.find(dni_a_modificar);
            it_indiceApellido = indiceApellido.find(it_indiceDni->second.apellido);
            indiceDni.erase(it_indiceDni);
            indiceApellido.erase(it_indiceApellido);
            cout<<"Ingrese ahora los datos del paciente:"<<endl;
            cout<<"DNI: "; cin>>auxiliar.dni;
            cout<<"Apellido: "; cin.ignore(); getline(cin, auxiliar.apellido);
            cout<<"Nombre: "; getline(cin, auxiliar.nombre);
            cout<<"Edad: "; cin>>auxiliar.edad;
            indiceDni[auxiliar.dni]=auxiliar;
            indiceApellido[auxiliar.apellido]=auxiliar;
            cout<<"Datos modificados."<<endl;
            archi_txt.guardar(indiceDni);
        }
            break;

        case 2: {
            cout<<"Ingrese el apellido del paciente que desea modificar, tal como aparece en el registro: ";
            cin.ignore(); getline(cin, apellido_a_modificar);
            it_indiceApellido = indiceApellido.find(apellido_a_modificar);
            it_indiceDni = indiceDni.find(it_indiceApellido->second.dni);
            indiceApellido.erase(it_indiceApellido);
            indiceDni.erase(it_indiceDni);
            cout<<"Ingrese ahora los datos del paciente:"<<endl;
            cout<<"DNI: "; cin>>auxiliar.dni;
            cout<<"Apellido: "; cin.ignore(); getline(cin, auxiliar.apellido);
            cout<<"Nombre: "; getline(cin, auxiliar.nombre);
            cout<<"Edad: "; cin>>auxiliar.edad;
            indiceDni[auxiliar.dni]=auxiliar;
            indiceApellido[auxiliar.apellido]=auxiliar;
            cout<<"Datos modificados."<<endl;
            archi_txt.guardar(indiceDni);
            break;
        }
        }
        }
        else
            cout<<"Necesita primero cargar los datos con la opcion 1."<<endl;

        break;
    }
    case 5: {
        if (paso_por_opcion_1){
        cargo_estudios_de_un_paciente=false;
        int uno_o_dos;
        cout<<"Ingrese el nombre del archivo binario: ";
        cin>>nombreBinario;
        //nombreBinario="EstudiosDePacientes_SEMA_V1.dat";
        cout<<endl;
        cout<<"Ingrese 1 para cargar por DNI, 2 para cargar por apellido: ";
        cin>>uno_o_dos;
        switch (uno_o_dos){
        case 1: {
            cout<<"Ingrese el DNI: ";
            cin>>dni_estudios_cargados;
            if(indiceDni.find(dni_estudios_cargados)!=indiceDni.end()){
            apellido_estudios_cargados=indiceDni[dni_estudios_cargados].apellido;
            setEstudiosMemoria(dni_estudios_cargados);
            if(cargo_estudios_de_un_paciente==true)
                listarEstudios();
            }
            else
                cout<<"El DNI ingresado no es valido."<<endl;
            break;
        }
        case 2: {
            cout<<"Ingrese apellido: ";
            cin.ignore(); getline(cin, apellido_estudios_cargados);
            if(indiceApellido.find(apellido_estudios_cargados)!=indiceApellido.end()){
            dni_estudios_cargados=indiceApellido[apellido_estudios_cargados].dni;
            setEstudiosMemoria(dni_estudios_cargados);
            if(cargo_estudios_de_un_paciente==true)
                listarEstudios();
            }
            else
                cout<<"El apellido ingresado no es valido."<<endl;
            break;
        }
        }        
        }
        else
            cout<<"Necesita primero cargar los datos con la opcion 1."<<endl;
        break;
    }
    case 6: {
        if (paso_por_opcion_1 and cargo_estudios_de_un_paciente){
        char tipo_test_elegido;
        int nivel_elegido, ver_interpolacion;
        cout<<"Ingrese tipo de test: 'M' para juego de la memoria, 'S' para salto del caballo"<<endl;
        cin>>tipo_test_elegido;
        cout<<"Ingrese nivel: ";
        cin>>nivel_elegido;
        cout<<"Ingrese 1 si desea ver la funcion interpolada o 2 para no hacerlo: ";
        cin>>ver_interpolacion;
        if(ver_interpolacion==1){
            graficarDesempenio(tipo_test_elegido, nivel_elegido, true);
        }
        else
            graficarDesempenio(tipo_test_elegido, nivel_elegido, false);
}
        else
            cout<<"Necesita primero cargar la lista de pacientes con la opcion 1, y seleccionar un paciente con la opcion 5."<<endl;
        break;
    }
    case 7: {
        if (paso_por_opcion_1 and cargo_estudios_de_un_paciente){
        char juego_seleccionado;
        cout<<"Ingrese tipo de test: 'M' para juego de la memoria, 'S' para salto del caballo: ";
        cin>>juego_seleccionado;
        switch (juego_seleccionado){
        case 'M': {
            int nivel_inicial, inician_dadas_vuelta, tiempo_dadas_vuelta, tiempo_dadas_vuelta_al_inicio=1, tiempo_del_test, nivel_maximo_completado;
            cout<<"Ingrese nivel inicial: ";
            cin>>nivel_inicial;
            cout<<"Ingrese 1 para determinar si inician dadas vuelta, 2 en caso negativo: ";
            cin>>inician_dadas_vuelta;
            if(inician_dadas_vuelta){
                cout<<"Ingrese el tiempo que estan visibles al inicio, en milisegundos: ";
                cin>>tiempo_dadas_vuelta_al_inicio;
            }
            cout<<"Ingrese el tiempo en milisegundos que se mantienen visibles las cartas, si son distintas: ";
            cin>>tiempo_dadas_vuelta;

            memory = new JuegoDeLaMemoria(ptr_app);
            Pixel color_de_fondo(0.5f,0.6f,0.5f);
            memory->setColorDeFondo(color_de_fondo);
            if(inician_dadas_vuelta==1)
                memory->setInicianDadasVuelta(true);
            else
                memory->setInicianDadasVuelta(false);
            memory->setTiempoDadasVueltaAlInicio(tiempo_dadas_vuelta_al_inicio);
            memory->setTiempoDadasVueltaSiSonDiferentes(tiempo_dadas_vuelta);
            memory->setNivel(nivel_inicial);
            memory->iniciar();
            tiempo_del_test=memory->getTiempoFinDelJuego();
            nivel_maximo_completado=memory->getNivel()-1;
            //guardo en el archivo binario
            Estudio auxiliar;
            cout<<"Vamos a guardar el estudio. Ingrese los siguientes datos:"<<endl;
            cout<<"Fecha con formato AAAAMMDD: ";
            cin>>auxiliar.fecha;
            cout<<"Hora con formato HHMM: ";
            cin>>auxiliar.hora;
            auxiliar.tiempo=tiempo_del_test;
            auxiliar.tipoDeTest=juego_seleccionado;
            auxiliar.nivel=nivel_maximo_completado;
            archi_bin = new ArchivoBinario;
            archi_bin->setNombre(nombreBinario);
            archi_bin->guardarEstudio(auxiliar, dni_estudios_cargados);
            delete(archi_bin);
            setEstudiosMemoria(dni_estudios_cargados);
            cout<<"Estudio cargado. Lista actualizada: "<<endl;
            listarEstudios();
            break;
        }
        case 'S': {
            int nivel_inicial, tiempo_del_test;
            Estudio auxiliar;
            juego_salto = new Juego_SC(ptr_app);
            cout<<"Ingrese nivel inicial: ";
            cin>>nivel_inicial;
            juego_salto->setNivelInicio(nivel_inicial);
            auxiliar.nivel=juego_salto->getNivel()-1;
            tiempo_del_test=juego_salto->getTiempoDeFin();
            //cout<<juego_salto->getTiempoDeFin()<<endl;
            delete(juego_salto);
            //cout<<"Presione una tecla para continuar..."<<endl;
            system("pause");
            cout<<"Vamos a guardar el estudio. Ingrese los siguientes datos:"<<endl;
            cout<<"Fecha con formato AAAAMMDD: ";
            cin>>auxiliar.fecha;
            cout<<"Hora con formato HHMM: ";
            cin>>auxiliar.hora;
            auxiliar.tipoDeTest=juego_seleccionado;
            auxiliar.tiempo=tiempo_del_test;
            archi_bin = new ArchivoBinario;
            archi_bin->setNombre(nombreBinario);
            archi_bin->guardarEstudio(auxiliar, dni_estudios_cargados);
            delete(archi_bin);
            setEstudiosMemoria(dni_estudios_cargados);
            cout<<"Estudio cargado. Lista actualizada: "<<endl;
            listarEstudios();
            break;
        }
        }
        }
        else
            cout<<"Necesita primero cargar la lista de pacientes con la opcion 1, y seleccionar un paciente con la opcion 5."<<endl;
        break;
    }
    case 0: {
        cout<<"Gracias por utilizar nuestros servicios."<<endl;
        break;
    }
    }
}

void InterfazDeConsola::mostrarEcuacion(int n, float *x, float *y, float xi)
{
    float b[n][n];
    float xt;
    float yi;
    string polinomios, ecuacion;
    string aux;
    ecuacion="y=";
    //inicializo tabla de diferencias
    for (int i=0; i<n; i++)
        b[i][0]=y[i];

    //calculo la tabla de diferencias
    for(int j=1; j<n; j++)
        for(int i=0; i<n-j; i++)
        b[i][j]=(b[i+1][j-1]-b[i][j-1])/(x[i+j]-x[i]);
    //interpolo con el polinomio
    xt=1;
    yi=b[0][0];
    ecuacion+=to_string((int)yi);
    for(int j=0; j<n-1; j++){
        xt=xt*(xi-x[j]);
        if (x[j]<0)
            polinomios+="(x"+to_string((int)x[j])+")";
        else
            polinomios+="(x-"+to_string((int)x[j])+")";
        yi=yi+b[0][j+1]*xt;
        aux=to_string(b[0][j+1]);
        bool salir=false;
        while (!salir){
            if(aux[aux.size()-1]=='0' or aux[aux.size()-1]=='.')
                aux.pop_back();
        else
                salir=true;
        }
        if (b[0][j+1]==0)
            ecuacion+="+(0)*";
        else{
                if (b[0][j+1]>=0)
            ecuacion+="+("+aux+')'+"*"+polinomios;
        else
            ecuacion+='('+aux+')'+"*"+polinomios;
        }
    }
    cout<<"La ecuacion es: "<<endl<<ecuacion<<endl;
}


string InterfazDeConsola::acomodarFecha(string in)
{
    string out;
    out.clear();
    out.push_back(in[0]);
    out.push_back(in[1]);
    out.push_back(in[2]);
    out.push_back(in[3]);
    out.push_back('/');
    out.push_back(in[4]);
    out.push_back(in[5]);
    out.push_back('/');
    out.push_back(in[6]);
    out.push_back(in[7]);
    return out;
}

string InterfazDeConsola::acomodarHora(string in)
{
    string out;
    out.clear();
    out.push_back(in[0]);
    out.push_back(in[1]);
    out.push_back(':');
    out.push_back(in[2]);
    out.push_back(in[3]);

    return out;
}

string InterfazDeConsola::acomodarTipoDeTest(char caracter)
{
    string out="M ";
    if (caracter=='S')
        out="SC";
    return out;
}
