#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string mostrarEcuacion(int n, float *x, float *y, float xi){
    float b[n][n];
    float xt;
    float yi;
    string polinomios, ecuacion;
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
    ecuacion+=to_string(yi);
    for(int j=0; j<n-1; j++){
        xt=xt*(xi-x[j]);
        polinomios+="(x-"+to_string(x[j])+")";
        yi=yi+b[0][j+1]*xt;
        ecuacion+="*"+polinomios;
    }
    cout<<ecuacion;
    return ecuacion;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    float y[]={5, 8, 4, 2};
    float x[]={-3, -2, 0, 4};
    float xi=2;
    float yi;
    int n=4;
    yi=newton(n,x,y,xi);
    cout<<"Valor interpolado: "<<yi;

    return a.exec();
}


