#pragma once

#include <string>

using namespace std;

class EntryData
{
    protected:
        string name;
        string genre;
    public:
        virtual EntryData* clone() = 0;

        string get_name() { return name; }
        string get_genre() { return genre; }
};