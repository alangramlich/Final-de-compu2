#include "graficadordesempenio.h"

GraficadorDesempenio::GraficadorDesempenio(vector<Estudio> p_estudios)
{
    estudios=p_estudios;
}

void GraficadorDesempenio::setEstudios(const vector<Estudio> &value)
{
    estudios = value;
    vector<int> tiempos;
    for(int i=0; i<(int)estudios.size(); i++)
        tiempos.push_back(estudios[i].tiempo);
    int max=tiempos[0];
    for(int i=1; i<(int)tiempos.size(); i++)
        if (max<tiempos[i])
            max=tiempos[i];
    maximoX=tiempos.size();
    maximoY=max;
    unidad_Y=1.0/((float)(maximoY)+3);
    unidad_X=1.0/((float)(maximoX)+1);
}

void GraficadorDesempenio::dibujarCuadriculas()
{
    vector<int> tiempos;
    for(int i=0; i<(int)estudios.size(); i++)
        tiempos.push_back(estudios[i].tiempo);
    int max=tiempos[0];
    for(int i=1; i<(int)tiempos.size(); i++)
        if (max<tiempos[i])
            max=tiempos[i];
    maximoX=tiempos.size();
    maximoY=max;

    unidad_Y=1.0/((float)(maximoY)+3);
    unidad_X=1.0/((float)(maximoX)+1);
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for (float i=0; i<tiempos.size()+3; i++){
        glVertex3f(unidad_X*(i+1), 0.0, 0.0);
        glVertex3f(unidad_X*(i+1), 1.0, 0.0);
    }
    for(float j=0; j<max+3; j++){
        glVertex3f(0.0, unidad_Y*(j+1), 0.0);
        glVertex3f(1.0, unidad_Y*(j+1), 0.0);
    }
    glEnd();
    glPopMatrix();
}

void GraficadorDesempenio::dibujarEjes()
{
    vector<int> tiempos;
    for(int i=0; i<(int)estudios.size(); i++)
        tiempos.push_back(estudios[i].tiempo);
    int max=tiempos[0];
    for(int i=1; i<(int)tiempos.size(); i++)
        if (max<tiempos[i])
            max=tiempos[i];
    maximoX=tiempos.size();
    maximoY=max;

    float unidad_Y=1.0/((float)(maximoY)+3);
    float unidad_X=1.0/((float)(maximoX)+1);
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    {
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
    }
    glEnd();
    glBegin(GL_TRIANGLES);
    {
        glVertex3f(0.0, 1.03, 0.0);
        glVertex3f(-0.03, 1.03-unidad_Y, 0.0);
        glVertex3f(0.03, 1.03-unidad_Y, 0.0);

        glVertex3f(1.03, 0.0, 0.0);
        glVertex3f(1.03-unidad_X, -0.03, 0.0);
        glVertex3f(1.03-unidad_X, 0.03, 0.0);
    }
    glEnd();
    glPopMatrix();
}

void GraficadorDesempenio::dibujarMaximo(vector<int> tiempos)
{
    vector<int>::iterator it=max_element(tiempos.begin(), tiempos.end());
    glPushMatrix();
    glLineWidth(5.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, *it*unidad_Y);
    glVertex2f(1.0, *it*unidad_Y);
    glEnd();
    glPopMatrix();
}

void GraficadorDesempenio::dibujarMinimo(vector<int> tiempos)
{
    vector<int>::iterator it=min_element(tiempos.begin(), tiempos.end());
    glPushMatrix();
    glLineWidth(5.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, *it*unidad_Y);
    glVertex2f(1.0, *it*unidad_Y);
    glEnd();
    glPopMatrix();
}

void GraficadorDesempenio::dibujarMedio(vector<int> tiempos)
{
    int suma=0;
    for (unsigned int i=0; i<tiempos.size(); i++)
        suma+=tiempos[i];
    float promedio=(float)((float)suma/(float)tiempos.size());
    glPushMatrix();
    glLineWidth(5.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, promedio*unidad_Y);
    glVertex2f(1.0, promedio*unidad_Y);
    glEnd();
    glPopMatrix();
    //cout<<promedio;
}

void GraficadorDesempenio::dibujarGrafica(vector<int> tiempos, float unidad_X, float unidad_Y)
{
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for(unsigned int i=0; i<tiempos.size(); i++)
        glVertex2f((i+1)*unidad_X, tiempos[i]*unidad_Y);
    glEnd();
    glPopMatrix();

}

void GraficadorDesempenio::dibujarInterpolacion(vector<int> tiempos, float unidad_X, float unidad_Y)
{

    float x[tiempos.size()];
    for (unsigned int i=0; i<tiempos.size(); i++)
        x[i]=i+1;
    float y[tiempos.size()];
    for (unsigned int i=0; i<tiempos.size(); i++)
        y[i]=tiempos[i];
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    float xi=1;
    float incremento_X=(float)(((float)(tiempos.size()))/(float)100);
    /*for(unsigned int i=0; i<9*tiempos.size(); i++){
        glVertex2f((xi*unidad_X), newton(tiempos.size(), x, y, xi)*unidad_Y);
        xi+=incremento_X;
    }*/
    while (xi<=tiempos.size()+0.1){
        glVertex2f((xi*unidad_X), newton(tiempos.size(), x, y, xi)*unidad_Y);
        xi+=incremento_X;
    }
    glEnd();
    glPopMatrix();
}

float GraficadorDesempenio::newton(int n, float *x, float *y, float xi)
{
    float b[n][n];
    float xt;
    float yi;

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
    for(int j=0; j<n-1; j++){
        xt=xt*(xi-x[j]);
        yi=yi+b[0][j+1]*xt;
    }

    return yi;
}

void GraficadorDesempenio::resizeGL(int w, int h)
{
    if (w>h)
        glViewport(0,0,h,h);
    if (w<h)
        glViewport(0,0,w,w);
    if(w==h)
        glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0-0.03,1.0+0.03,0.0-0.03,1.0+0.03,-1.0,1.0);
}

void GraficadorDesempenio::setGraficar_interpolacion(bool value)
{
    graficar_interpolacion = value;
}

void GraficadorDesempenio::dibujarPunto(float desp_x, float desp_y, float unidad_X, float unidad_Y)
{
    glPushMatrix();
    glTranslatef(desp_x, desp_y, 0.0);
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    {
        for (float i=0; i<2*3.1415; i+=0.05){
            glVertex3f(cos(i)*unidad_X/5, sin(i)*unidad_Y/5, 0.0);
        }
    }
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    {
        for (float i=0; i<2*3.1415; i+=0.05){
            glVertex3f(cos(i)*unidad_X/5, sin(i)*unidad_Y/5, 0.0);
        }
    }
    glEnd();

    glPopMatrix();
}

void GraficadorDesempenio::dibujarFondo()
{
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glPopMatrix();
}

void GraficadorDesempenio::paintGL()
{
    resizeGL(width(), height());
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //ACA VAN LOS DIBUJITOS
    glLoadIdentity();
    dibujarFondo();
    dibujarCuadriculas();
    dibujarEjes();

    vector<int> tiempos;
    for(int i=0; i<(int)estudios.size(); i++)
        tiempos.push_back(estudios[i].tiempo);
    dibujarMaximo(tiempos);
    dibujarMinimo(tiempos);
    dibujarMedio(tiempos);
    dibujarGrafica(tiempos, unidad_X, unidad_Y);
    for(unsigned int i=0; i<tiempos.size(); i++)
    dibujarPunto((float)(i+1)*unidad_X, (float)tiempos[i]*unidad_Y, unidad_X, unidad_Y);
    if (graficar_interpolacion)
        dibujarInterpolacion(tiempos, unidad_X, unidad_Y);
}

void GraficadorDesempenio::initializeGL()
{
    initializeOpenGLFunctions();
    //glClearColor(0.1,0.5,0.5,0.1);
    glClearColor(1.0,1.0,1.0,0.1);
}
