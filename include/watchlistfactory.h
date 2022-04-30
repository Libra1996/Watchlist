#pragma once

#include "entrydata.h"
#include "songlist.h"
#include "tvshow.h"

class Watchlistfactory
{
    static EntryData* list_type;

    public:
        static EntryData *watchlist_type(string s);
        static EntryData* get_list_type()
        {
            return list_type->clone();
        }
};
