#include <iostream>
#include <vector>
#include <string>
#include "Canciones.h"


using namespace std;


//metodo para ingresar el titulo de la cancion y la primera linea de la cancion y la etiqueta
Canciones::Canciones() {
	songTitle = "none";
	firstLine = "none";
	tag = "none";
}

//constructor de la clase songs con las variables inizializables
Canciones::Canciones(string title, string songFirstLine, string songTag) {
	songTitle = title;
	firstLine = songFirstLine;
	tag = songTag;
}

//metodo para modificar la primera linea de una cancion
void Canciones::SetFirstLine(string songFirstLine) {
	firstLine = songFirstLine;
}

//metodo para imprimir la playlist con sus correspondientes datos
void Canciones::PrintList() {

	cout << songTitle << ": " << "\"" << firstLine << "\", " << countPlay << " play(s).";
	cout << endl;
	cout << "Tags: " << tag;
}

//metodo para imprimir el titulo de la cancion
void Canciones::PrintTitle() {
	cout << songTitle;
}

//metodo para inizializar las canciones
void Canciones::PlayCanciones() {
	++countPlay;
	cout << firstLine << endl;
}

//metodo para llamar el titulo de la cancion
string Canciones::SongTitle() {
	return songTitle;
}

string Canciones::getName() 
{
    return songTitle;
}

//metodo para llamar la etiqueta de la cancion
string Canciones::SongTag() {
	return tag;
}

//metodo para reproducir la lista correpondiente
int Canciones::PlayCount() {
	return countPlay;
}
// metodo para agregar contador de canciones
void Canciones::AddPlayCount(int playCount) {
	countPlay = countPlay + playCount;
}


