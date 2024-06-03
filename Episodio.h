/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
- ¿Qué aprendí en el desarrollo de esta clase?
Esta clase es la hermana de otra clase, tambien directamente creada de la clase base, me gusto como se volvieron a colocar
los mismos argumentos que en la clase base pero para otros usos distintos.
*/

#ifndef Episodio_h
#define Episodio_h
#include <stdio.h>
#include "Video.h"
#include <string>
using namespace std;

class Episodio{
    private:
    string titulo;
    int temporada;
    int calificacion;

    public:
    // Constructor default vacio
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    //Metodos Modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    //Metodos de acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    std::string str();

};

#endif