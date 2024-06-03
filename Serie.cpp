/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
*/

#include "Serie.h"
using namespace std;
#include <string>
#include "Episodio.h"
#include <set>

//Constructor
Serie::Serie():Video(){
    // solo vamos a inicializar cantidad
    cantidad = 0;
}
Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}
void Serie::calculaDuracion() {
    // Declaracion de la duracion total
    int duracionTotal;

    // Inicializar
    duracionTotal = 0;

    // Ciclo for para contar los episodios totales
    for (int index = 0; index < cantidad; index++){
        duracionTotal += episodios[index].getTemporada();
    }
    duracion = duracionTotal;
}
//Modificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    //primero validar que exista ese episodio
    if (posicion >= 0 && posicion < cantidad){
        episodios[posicion] = episodio;
    }
}
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}
//acceso
Episodio Serie::getEpisodio(int posicion){
    Episodio epi;
    //Validar que exista el episodio solicidado (posicion)
    if(posicion >= 0 && posicion < cantidad){
        return episodios[posicion];
    }
    //Si no existe retorna un default
    return epi;
}
int Serie::getCantidad(){
    return cantidad;
}
double Serie::calculaPromedio(){
    double acum = 0;
    for (int index = 0; index < cantidad; index++){
        acum = acum + episodios[index].getCalificacion();
    }
    //validar que tenga episodios
    if(cantidad > 0){
        return acum / cantidad;
    }
    else{
        return 0;
    }
}
//Overriding del metodo str() de la clase base
std::string Serie::str() {
    std::string serieInfo = iD + ' ' + titulo + ' ' + std::to_string(duracion) + ' ' + genero + ' ' + std::to_string(calificacion) + ' ' + std::to_string(cantidad);
    if (cantidad > 0) {
        std::string episodiosInfo;
        for (int i = 0; i < cantidad; i++) {
            episodiosInfo =  episodiosInfo + '\n' + episodios[i].getTitulo() + ' ' + std::to_string(episodios[i].getTemporada()) + ' ' + std::to_string(episodios[i].getCalificacion());
        }
        return serieInfo + episodiosInfo + '\n';
    }
    return '\n' + serieInfo + '\n';
}
//Agregar un episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if(cantidad < 5){
        episodios[cantidad++] = episodio;
    }
}