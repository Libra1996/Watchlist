#include "watchlistfactory.h"

#include <string>

EntryData *Watchlistfactory::watchlist_type(string s) {
	if(s == "SONG") {
		list_type = new Songlist();
	} else if (s == "SHOW") {
		list_type = new TVShow();
	}
}
