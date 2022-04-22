#ifndef CHOICE_H_
#define CHOICE_H_

#include "wx/wx.h"

using namespace std;

// Choice represented by int.
typedef int Choice;

// Which object a player chooses each round.
enum { ROCK, PAPER, SCISSORS, NONE };

/**
 * Convert a chosen object to a wxString.
 * @param choice the object to convert.
 * @return the wxString.
 */
wxString choice_to_wxString(Choice choice);

int choice_to_int(Choice choice);
string choice_to_string(Choice choice);

#endif /* CHOICE_H_ */
