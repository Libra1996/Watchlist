#pragma once

#include "entrydata.h"

#include <string>

#include <iostream>

using namespace std;

class Songlist : public EntryData
{
    private:
        string artist;
    public:
        string get_artist();
        void set_artist(string s);

        Songlist() {
            cout << "Songlist created.\n";
            name = "Song name";
            genre = "Song genre";
        }

        EntryData* clone() {
            return new Songlist();
        }
};