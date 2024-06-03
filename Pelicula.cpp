/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
*/

#include "Pelicula.h"

// Constructores: Vacio y con parametros
Pelicula::Pelicula():Video(){
    oscares = 100;
}
Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion)
{
    oscares = _oscares;
}
//Modificadores
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}
//Acceso
int Pelicula::getOscares(){
    return oscares;
}

std::string Pelicula::str(){
    //Tenemos acceso directo a los atributos de la clase padre por que son protected
    return  iD + ' ' + titulo + ' ' + std::to_string(duracion) + ' ' + genero + ' ' + std::to_string(calificacion) + ' ' + std::to_string(oscares);
}
