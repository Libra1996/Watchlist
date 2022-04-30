#pragma once

#include "entrydata.h"
#include <string>

#include <iostream>

using namespace std;

class TVShow : public EntryData
{
    private:
        string status;
    public:
        string get_status();
        void set_status(string s);

        TVShow() {
            cout << "TVShow created.\n";
            name = "TV name";
            genre = "TV genre";
        }

        EntryData* clone() {
            return new TVShow();
        }
};