/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
*/

#include "Episodio.h"
#include "Serie.h"

// Constructor default vacio
Episodio::Episodio(){
    titulo = "9 Hazbin Hotel";
    temporada = 0;
    calificacion = 0;
}
Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

//Metodos Modificadores
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

//Metodos de acceso
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}
//Metodo Str
std::string Episodio::str(){
    return titulo + ' ' + std::to_string(temporada) + ' ' + std::to_string(calificacion);
}