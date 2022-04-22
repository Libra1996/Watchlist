#include "aifactory.h"

Ai *aifactory::chooser(string s) {
	if(s == "RAND") {
		return new RandomAi();
	} else {
		return new MachineAi();
	}
}
