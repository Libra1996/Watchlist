#include "game.h"

Game::Game()
{
    round_count = 0;
    human_win_count = 0;
    computer_win_count =0;
    ties_count = 0;
    round_ui = 0;
    user_move = NONE;
    computer_move = NONE;
    computer_prediction = NONE;
    winner_name = "";
}
int Game::return_round_count()
{
    int b = round_count;
    return b;
}
int Game::return_round_ui() {
	int b = round_ui;
	return b;
}
int Game::return_human_win_count(){
    int b = human_win_count;
    return b;
}
int Game::return_computer_win_count(){
    int b = computer_win_count;
    return b;
}
int Game::return_ties_count(){
    int b = ties_count;
    return b;
}
Choice Game::return_user_move() 
{
    Choice b = user_move;
    return b;
}
Choice Game::return_computer_move(){
    Choice b = computer_move;
    return b;
}
Choice Game::return_computer_prediction(){
    Choice b = computer_prediction;
    return b;
}
string Game::return_winner_name() {
	string s = winner_name;
	return s;
}

//Functions for handling buttons
void Game::on_user_choice_selection(Choice move)
{
    user_move = move;
}

void Game::setting_update(string s) {
	game_mode = s;
}

void Game::reset_game() {
    human_win_count = 0;
    computer_win_count = 0;
    round_ui = 0;
    ties_count = 0;
    user_move = NONE;
    computer_move = NONE;
    computer_prediction = NONE;
    winner_name = "";
}

void Game::reset_same_mode() {
    round_ui = 1;
    ties_count = 0;
    human_win_count = 0;
    computer_win_count = 0;
}

string Game::get_mode() {
	string s = game_mode;
	return s;
}

Choice Game::get_user_move() {
	Choice c;
	c = user_move;
	return c;
}

string Game::get_usermove() {
	string s;
	s = choice_to_string(get_user_move());
	return s;
}

void Game::set_round_count(int input){
    round_count = input;
}

void Game::update_round_ui() {
	if (round_ui < round_count) {
		round_ui++;
	} else if (round_ui == round_count) {
		reset_same_mode();
	}
}

void Game::set_game_mode(string mode)
{
    game_mode = mode; 
}

void Game::create_aifactory(string s) {
	ai = aifactory::chooser(s);
}

void Game::set_winner_name(string s) {
	winner_name = s;
}

void Game::update_ties_count() {
	ties_count++;
}

void Game::set_ai_move(Choice user_move, string game_mode) {
	if(game_mode == "RAND") {
		computer_move = ai->DecideMove(user_move);
		computer_prediction = ai->GetPredictedMove(user_move);
	} else if(game_mode == "AI") {
		computer_move = ai->DecideMove(user_move);
		predicted_human_choice(ai->GetPredictedMove(user_move));
	}
}

void Game::predicted_human_choice(Choice c) {
	if(c == ROCK) {
		computer_prediction = SCISSORS;
	} else if(c == PAPER) {
		computer_prediction = ROCK;
	} else if(c == SCISSORS) {
		computer_prediction = PAPER;
	}
}

void Game::determineWinner()
{
	update_round_ui();
	set_ai_move(user_move, game_mode);
    // rock beat scissors, scissors beats paper, paper beats rock //0 is draw // 1 is user win // 2 is ai win
    if (user_move == computer_move) {
    	set_winner_name("DRAW");
    	update_ties_count();
    } else if (user_move == ROCK)
    {
        if (computer_move == PAPER) {
        	computer_win_count++;
        	set_winner_name("COMPUTER");
        }    
        else {
			human_win_count++;
        	set_winner_name("HUMAN");
        }
            
    } else if (user_move == PAPER)
    {
        if (computer_move == SCISSORS) {
	        set_winner_name("COMPUTER");
			computer_win_count++;
        }
        else {
            human_win_count++;
        	set_winner_name("HUMAN");
        }
    } else if (user_move == SCISSORS)
    {
        if (computer_move == ROCK) {
			computer_win_count++;
			set_winner_name("COMPUTER");
        }
        else {
            human_win_count++;
        	set_winner_name("HUMAN");
        }
    }
}
