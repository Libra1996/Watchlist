#pragma once

#include "ai.h"
#include "random_ai.h"
#include "ml_ai.h"

class aifactory
{
public:
	static Ai *chooser(string s);
};
