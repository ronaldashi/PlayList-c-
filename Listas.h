#ifndef PLAYLIST_H
#define PLAYLIST_H

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Canciones.h"

using namespace std;


class Listas {
public:

	Listas();
	Listas(string listName);

	void PrintList();
	void AddCanciones(Canciones* songsPtr);
	void PlayCancionesInList();
	void DeleteSongListas();
	void DelteSongInList(string songsPtr);
	void DeleteDupCanciones();
	
	void AddPlayCount();
	string PrintListName();

private:
	string listName;
	string songTitle;
	string tags;
	vector<Canciones*> songsPtr;
};
#endif	// PLAYLIST_H

