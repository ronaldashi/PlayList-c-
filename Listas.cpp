#include <iostream>
#include <vector>
#include <string>
#include "Listas.h"

using namespace std;

Listas::Listas() {
	listName = "none";
}

Listas::Listas(string playlistName) {
	listName = playlistName;
}

void Listas::PrintList() {

	cout << listName;
}

void Listas::AddCanciones(Canciones* newCanciones) {

	songsPtr.push_back(newCanciones);
}


void Listas::PlayCancionesInList() {
	
	for (int i = 0; i < songsPtr.size(); ++i) {
		songsPtr.at(i)->PlayCanciones();
	}
}

void Listas::DeleteSongListas() {

	int pickSongIndex = 0;

	for (int i = 0; i < songsPtr.size(); ++i) {
		cout << i << ": ";
		songsPtr.at(i)->PrintTitle();
		cout << endl;
	}

	cout << "Ingresa el indice de la cancion que deseas borrar: ";
	cin >> pickSongIndex;
	cout << endl;


	songsPtr.erase(songsPtr.begin() + pickSongIndex);
}

void Listas::DelteSongInList(string eraseSong) {

	for (int i = 0; i < songsPtr.size(); ++i) {
		if (eraseSong == songsPtr.at(i)->SongTitle()) {
			songsPtr.erase(songsPtr.begin() + i);
		}
		else {

		}
	}
}

void Listas::AddPlayCount() {
	vector<Canciones*> tempPtr;
	int numPlayCount = 0;
	int addPlayCount = 0;

	tempPtr = songsPtr;

	for (int i = 0; i < tempPtr.size(); ++i) {
		for (int j = i + 1; j < tempPtr.size(); ++j) {
			if (tempPtr.at(i)->SongTitle() == tempPtr.at(j)->SongTitle()) {
				numPlayCount = tempPtr.at(i)->PlayCount();
				addPlayCount = tempPtr.at(j)->PlayCount();

				numPlayCount = numPlayCount + addPlayCount;
				tempPtr.erase(tempPtr.begin() + j); 
				--j;

			}
		}
	}
}

