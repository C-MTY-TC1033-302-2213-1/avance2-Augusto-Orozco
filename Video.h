/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
- ¿Qué aprendí en el desarrollo de esta clase?
Aprendi como crear una clase, al ser esta la principal solo debia seguir la sintaxis de una clase para crearla.
*/

#ifndef Video_h
#define Video_h
#include <stdio.h>
#include <string>
using namespace std;

class Video {
    protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

    public:
    // Constructor default
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    //Metodos Modificadores
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    //Metodos de acceso
    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    virtual string str();

};

#endif