#pragma once

#include "ai.h"

class RandomAi : public Ai
{
public:
  Choice DecideMove(Choice user_move);
  Choice GetPredictedMove(Choice user_move);
};
