#include "random_ai.h"

Choice RandomAi::DecideMove(Choice user_move)
{
	Choice ai_move;
    int moveInt = rand() % 3;
    switch (moveInt)
    {
    case 0:
        ai_move = ROCK;
        break;
    case 1:
        ai_move = PAPER;
        break;
    case 2:
        ai_move = SCISSORS;
        break;
    default:
        ai_move = NONE;
    }
  return ai_move;
}

Choice RandomAi::GetPredictedMove(Choice user_move)
{
  return NONE;
}
