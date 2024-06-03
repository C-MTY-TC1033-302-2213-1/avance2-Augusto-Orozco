/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
*/

#include "Video.h"

//Constructor Default con parametros
Video::Video(){
    iD = "0000";
    titulo = "Augusto Orozco";
    duracion = 100; //En minutos
    genero = "Computacion";
    calificacion = 100;
}
Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}
//Metodos Modificadores
void Video::setId(string _iD){
    iD = _iD;
}
void Video::setTitulo(string _titulo){
    titulo = _titulo;
}
void Video::setDuracion(int _duracion){
    duracion = _duracion;
}
void Video::setGenero(string _genero){
    genero = _genero;
}
void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}
//Metodos de acceso
string Video::getId(){
    return iD;
}
string Video::getTitulo(){
    return titulo;
}
int Video::getDuracion(){
    return duracion;
}
string Video::getGenero(){
    return genero;
}
double Video::getCalificacion(){
    return calificacion;
}
std::string Video::str(){
    return iD + ' ' + titulo + ' ' + std::to_string(duracion) + ' ' + genero + ' ' + std::to_string(calificacion);
}