#pragma once

#include "Choice.h"

class Ai
{
public:
  virtual Choice DecideMove(Choice player_move) = 0;
  virtual Choice GetPredictedMove(Choice player_move) = 0;
};
