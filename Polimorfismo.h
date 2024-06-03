//
// Polimorfismo.h
// Tarea3
//
// Created by Ma. Guadalupe Roque Díaz de León on 23/05/24.
//
/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
- ¿Qué aprendí en el desarrollo de esta clase?
La implementacion de polimorfismo para realizar todos los procesos facilitando la escritura del main reduciendo en gran medida
el tamaño del main 
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>
using namespace std;

const int MAX_VIDEOS = 100;

class Polimorfismo{
    private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

    public:
    // Constructor default
    Polimorfismo();
    void leerArchivo(string nombre);

    //Metodos Modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    //Metodos Modificadores
    Video *getPtrVideo(int index);
    int getCantidad();

    //Otros Metodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif