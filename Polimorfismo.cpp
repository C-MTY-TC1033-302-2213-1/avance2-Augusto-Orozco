/*
Nombre: José Augusto Orozco Blas
Matricula: A00839579
Carrera: ITC
Fecha: 02-Junio-2024
- ¿Qué aprendí en el desarrollo de esta clase?
El desarrollo de los metodos declarados en el .h fue interesante por que es algo relativamente "sensillo" y facil de
entender, por lo que fue instintivo el desarrollo de estos metodos para que el codigo funcionara.
*/

#include "Polimorfismo.h"

// Constructor default vacio
Polimorfismo::Polimorfismo(){
    for(int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }
    //Inicializar la cantidad de videos en 0
    cantidad = 0;
}

//Modificadores
void Polimorfismo::setPtrVideo(int index, Video *video){
    //validar index - >=0 && < cantidad
    if (index >= 0 && index < cantidad){
    //cambiar el apuntador
    arrPtrVideos[index] = video;
    }
}
//cambia el valor del atributo cantidadal nuevo calor recibido como parametro de entrada
//Debe estar entre 0 y MaxVideos-1
void Polimorfismo::setCantidad(int _cantidad){
    if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
        cantidad = _cantidad;
    }

}

//Metodos acceso
Video* Polimorfismo::getPtrVideo(int index){
    //VALIDAR QUE EXISTA EL INDEX
    if(index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }
    //si no existe
    return nullptr;
}

int Polimorfismo::getCantidad(){
    return cantidad;
}

// Otros Metodos
void Polimorfismo::reporteInventario(){
    //declaracion de contadores
    int cantidadPelis;
    int cantidadSeries;

    // inicializar
    cantidadPelis = 0;
    cantidadSeries= 0;

    //Recorrer todo el arreglo de ptr usando un for
    for (int index = 0; index < cantidad; index++){

        //* indireccion (ptr) genera el objeto
        if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cantidadPelis++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cantidadSeries++;
        }
        cout << arrPtrVideos[index]->str() << endl;
    }
    //Fuera del for desplegamos los totales
    cout << "Peliculas = " << cantidadPelis << endl;
    cout << "Series = " << cantidadSeries << endl;
}
void Polimorfismo::reporteCalificacion(double _calificacion){
    //contador total
    int total;
    //inicializar el contador antes del ciclo
    total = 0;

    for(int index = 0; index < cantidad; index++){
        //verificar si tienen la calificacion == _calificacion
        //si es un apuntador ->
        if(arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    //Desplegar el total fuera del for :D
    cout << "Total = " << total << endl;
}
void Polimorfismo::reporteGenero(string _genero){
    //Se declara el contador
    int total;
    // Inicializar contador
    total = 0;
    for(int index = 0; index < cantidad; index++){
        if(arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;
}
void Polimorfismo::reportePeliculas(){
    //Se declara el contador
    int pelicounter;
    // Inicializar contador
    pelicounter = 0;

    // Mediante un for se recorre todo el arreglo de Ptr
    for(int index = 0; index < cantidad; index++){

        // * Indireccion (ptr) genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index] -> str() << endl;
            pelicounter++;
        }
    }

    //Fuera del for - desplegar el total de peliculas si es que hay.
    if(pelicounter > 0){
        cout << "Total Peliculas = " << pelicounter << endl;
    }
    else{
        cout << "No peliculas" << endl;
    }
}
void Polimorfismo::reporteSeries(){
    //Se declara el contador
    int seriescounter;
    // Inicializar contador
    seriescounter = 0;

    // Mediante un for se recorre todo el arreglo de Ptr
    for(int index = 0; index < cantidad; index++){

        // * Indireccion (ptr) genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index] -> str() << endl;
            seriescounter++;
        }
    }

    //Fuera del for - desplegar el total de peliculas si es que hay
    if(seriescounter > 0){
        cout << "Total Series = " << seriescounter << endl;
    }
    else{
        cout << "No series" << endl;
    }
}
void Polimorfismo::leerArchivo(string nombre) {
    Serie* arrPtrSeries[50];
    Pelicula* arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in); // abre el archivo de entrada

    while (getline(entrada, line)) {
        stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        if (row[0] == "P") {
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        } else if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        } else if (row[0] == "E") {
            index = stoi(row[1]) - 500;
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
        }
    }

    for (int index = 0; index < cantidadSeries; index++) {
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrSeries[index]->calculaDuracion();
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    for (int index = 0; index < cantidadPeliculas; index++) {
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    /*
    for (int index = 0; index < cantidadVideos; index++) {
        cout << index << " " << arrPtrVideos[index]->str() << endl;
    }*/

    entrada.close();
}
