#ifndef SONG_H
#define SONG_H

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Canciones {
public:

    Canciones();
    Canciones(string songTitle, string firstLine, string tag);
    void SetFirstLine(string firstLine);
    void PrintList();
    void PrintTitle();
    void PlayCanciones();
    string SongTitle();
    string SongTag();
    string getName();
    int PlayCount();
    void Ordenar(vector<Canciones*> song, int cantidad);
    void AddPlayCount(int countPlay);



private:
    string songTitle;
    string firstLine;
    string tag;
    int countPlay = 0;
};
#endif // SONG_H

