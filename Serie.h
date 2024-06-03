/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
- ¿Qué aprendí en el desarrollo de esta clase?
Como una clase puede ser derivada de dos clases previamente creadas, solamente agregando algunos nuevos argumentos
y usando los que ya existian en las otras clases.
*/

#ifndef Serie_h
#define Serie_h
//Para Herencia
#include "Video.h"
//Para composicion
#include "Episodio.h"
#include <string>
using namespace std;

class Serie : public Video{
    private: 
    Episodio episodios[5];
    int cantidad;

    public:
    //Constructor
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    void calculaDuracion();
    //Modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);
    //acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();
    double calculaPromedio();
    std::string str();
    void agregaEpisodio(Episodio episodio);
};

#endif