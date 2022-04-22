#pragma once

#include "Choice.h"
#include <string>
#include "aifactory.h"

class Game
{
public:
//constructor
    Game();
//Getter functions
    int return_round_count();
    string return_winner_name();
    int return_human_win_count();
    int return_computer_win_count();
    int return_ties_count();
    int return_round_ui();
    Choice return_user_move();
    Choice return_computer_move();
    Choice return_computer_prediction();
//Functions for handling buttons
    void on_user_choice_selection(Choice move); //returns button choice to user_move
	void setting_update(string s);
	void reset_game();
	void reset_same_mode();
	void create_aifactory(string s);
	string get_mode();
	Choice get_user_move();
	string get_usermove();
	void set_round_count(int input);
    void set_game_mode(string mode);
    void set_ai_move(Choice user_move, string game_mode);
    void determineWinner();
    void set_winner_name(string winner_name);
    void update_ties_count();
    void update_round_ui();
    void predicted_human_choice(Choice c);

private:
    Ai *ai;

    //setting
    string game_mode;
    //rounds
    int round_count;
    int round_ui;
    //Winner name
    string winner_name;
    //# of human wins
    int human_win_count;
    //#  of computer wins
    int computer_win_count;
    //# of ties
    int ties_count;
    //current usr move
    Choice user_move;
    //current computer move
    Choice computer_move;
    //next computer move if ml mode on
    Choice computer_prediction;
};
