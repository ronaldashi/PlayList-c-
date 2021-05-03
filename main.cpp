
#include <string>
#include <sstream>
#include "Listas.h"
#include "Canciones.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include<string.h>

using namespace std;

int main() {

    vector<Listas*> vectPlayList;
    vector<Canciones*> vectCanciones;


    string tituloCancion;
    string primeraLinea;
    string NombrePlayList;
    string Etiqueta;
   

    int playlistIndex = 0;
    int songIndex = 0;
    string vector[40];
    string tempo[20];

    int userInput = 0;
    do {
        cout << "PLAYLIST UPTC SISTEMAS 2021" << endl;

        cout << "\n1.----> Agregar canciones.<-------" << endl;
        cout << "2.---->Muestra todas las canciones.<-------" << endl;
        cout << "3.---->Agrega una Listas<-------" << endl;
        cout << "4.---->Agrega una cancion a una Listas<-------" << endl;
        cout << "5.---->Muestra todas las Listas.<-------" << endl;
        cout << "6.---->Reproduce una Listas.<-------" << endl;
        cout << "7.---->Elimina una Listas<-------" << endl;
        cout << "8.---->Eliminar una cancion de una Listas<-------" << endl;
        cout << "9---->Elimina una cancion de la biblioteca <-------" << endl;
        cout << "10.---->Salir del programa<------- \n" << endl;





        cout << "Ingrese su seleccion : ";
        cin >> (userInput);

        switch (userInput) {
            case 1:

                cout << "Nombre de la cancion: ";
                cin>>tituloCancion;
                cout << "Primera linea de la cancion: ";
                cin>>primeraLinea;
                cout << "Etiqueta: ";
                cin>>Etiqueta;

                vectCanciones.push_back(new Canciones(tituloCancion, primeraLinea, Etiqueta));

                break;

            case 2:
                for (int i = 0; i < vectCanciones.size(); ++i) {
                    vector[i] = vectCanciones.at(i)->getName();
                }
                int i, j;
                for (int i = 0; i < vectCanciones.size(); i++) {
                    for (int j = 0; j < vectCanciones.size() - 1; j++) {
                        if (vector[j] > vector[j + 1]) {
                            tempo[j] = vector[j];
                            vector[j] = vector[j + 1];
                            vector[j + 1] = tempo[j];
                        }
                    }
                }
                int opc;
                cout << "Listado de canciones : \n";
                cout << "1.---->  De manera ascendente <-------\n\n";
                cout << "2.---->  De manera descendente <-------\n\n";
                cout << "Seleccione...\n ";
                cin >> opc;

                switch (opc) {
                    case 1:
                        for (int j = 0; j < vectCanciones.size(); j++) {
                            cout << "Cancion de la playlist con nombre : " << vector[j] << "\n";
                        }
                        break;

                    case 2:
                        for (int j = vectCanciones.size(); j >= 0; j--) {
                            cout << "Cancion de la playlist con nombre : " << vector[j] << "\n";
                        }
                        break;
                }


                break;

            case 3:
                cout << "Nombre de la Listas: ";
                cin >> (NombrePlayList);
                 vectPlayList.push_back(new Listas(NombrePlayList));

                break;

            case 4:

                for (int i = 0; i < vectPlayList.size(); ++i) {
                    cout << i << ": ";
                    vectPlayList.at(i)->PrintList();
                    cout << endl;
                }

                cout << "Elija un numero de indice de lista de reproduccion: ";
                cin >> playlistIndex;
                cout << endl;

                for (int i = 0; i < vectCanciones.size(); ++i) {
                    cout << i << ": ";
                    vectCanciones.at(i)->PrintTitle();
                    cout << endl;
                }

                cout << "Elija un numero de indice de cancion: ";
                cin >> songIndex;
                cout << endl;

                vectPlayList.at(playlistIndex)->AddCanciones(vectCanciones.at(songIndex));

                cin.ignore();
                break;

            case 5:

                for (int i = 0; i < vectPlayList.size(); ++i) {
                    cout << i << ": ";
                    vectPlayList.at(i)->PrintList();
                    cout << endl;
                }
                break;

            case 6:

                for (int i = 0; i < vectPlayList.size(); ++i) {
                    cout << i << ": ";
                    vectPlayList.at(i)->PrintList();
                    cout << endl;
                }
                cout << endl;

                cout << "Elija un numero de indice de cancion: ";
                cin >> playlistIndex;
                cout << endl;

                cout << "Reproduciendo las primeras lineas de la Listas:";
                vectPlayList.at(playlistIndex)->PrintList();
                cout << endl;

                vectPlayList.at(playlistIndex)->PlayCancionesInList();

                cin.ignore();
                break;

            case 7:
                for (int i = 0; i < vectPlayList.size(); ++i) {
                    cout << i << ": ";
                    vectPlayList.at(i)->PrintList();
                    cout << endl;
                }

                cout << "Elija un numero de indice de la Listas para eliminar: ";
                cout << endl;
                cin >> playlistIndex;

                delete vectPlayList.at(playlistIndex);
                vectPlayList.erase(vectPlayList.begin() + playlistIndex);

                cin.ignore();
                break;

            case 8:
                for (int i = 0; i < vectPlayList.size(); ++i) {
                    cout << i << ": ";
                    vectPlayList.at(i)->PrintList();
                    cout << endl;
                }

                cout << "Elija un numero de indice de la Listas: ";
                cin >> playlistIndex;
                cout << endl;

                vectPlayList.at(playlistIndex)->DeleteSongListas();

                cin.ignore();
                break;

            case 9:
                for (int i = 0; i < vectCanciones.size(); ++i) {
                    cout << i << ": ";
                    vectCanciones.at(i)->PrintTitle();
                    cout << endl;
                }

                cout << "Elija un numero de indice de cancion: ";
                cin >> songIndex;
                cout << endl;

                for (int i = 0; i < vectPlayList.size(); ++i) {
                    vectPlayList.at(i)->DelteSongInList(vectCanciones.at(songIndex)->SongTitle());
                }

                delete vectCanciones.at(songIndex);
                vectCanciones.erase(vectCanciones.begin() + songIndex);


                cin.ignore();
                break;

            
            case 10:

                cout << "Que tenga buen dia";
                exit(0);
                break;

        }

    } while (userInput != 10);
}

