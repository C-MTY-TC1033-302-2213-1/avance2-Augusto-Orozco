/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
- ¿Qué aprendí en el desarrollo de esta clase?
La clase hija de la primer clase creada, aprendi a como utilizar argumentos de otras clases para el funcionamiento
de una clase nueva.
*/

#ifndef Pelicula_h
#define Pelicula_h
#include <string>
using namespace std;
#include "Video.h"
#include <iostream>

// Clase pelicula es derivada de Video.
class Pelicula : public Video {
    private:
    int oscares;

    public:
    // Constructores: Vacio y con parametros
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    //Modificadores
    void setOscares(int _oscares);

    //Acceso
    int getOscares();

    std::string str();

};
#endif