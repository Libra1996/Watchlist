#include "Choice.h"


wxString choice_to_wxString(Choice choice)
{
    switch (choice)
    {
        case ROCK:     return "Rock    ";
        case PAPER:    return "Paper   ";
        case SCISSORS: return "Scissors";
        default:       return "none    ";
    }
}

string choice_to_string(Choice choice) {
	if(choice == ROCK) {
		return "rock";
	} else if(choice == PAPER) {
		return "paper";
	} else if(choice == SCISSORS) {
		return "scissors";
	}
	
	return "";
}

