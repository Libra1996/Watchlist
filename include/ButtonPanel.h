#pragma once

#include "Choice.h"
#include <string>
#include "game.h"
using namespace std;

/**
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:
    /**
     * Constructor.
     * @param parent the parent frame.
     */
    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }
	
	void setButtonPanel(wxPanel *p);
	void setPredictionPanel(wxPanel *p);
	void SetOptionsVisibility(wxPanel *panel, bool is_shown);
	void SetPredictionVisibility(wxPanel *panel, bool is_shown);
    /**
     * Event handler for the rock button.
     * @param event the button click event.
     */
    void on_rock(wxCommandEvent& event);

    /**
     * Event handler for the paper button.
     * @param event the button click event.
     */
    void on_paper(wxCommandEvent& event);

    /**
     * Event handler for the scissors button.
     * @param event the button click event.
     */
    void on_scissors(wxCommandEvent& event);

    void input_round_count(int input);

    void input_game_mode(string mode);
    void update_round_num_choice_text(const int round_num);
    void update_setting_choice_text(const string setting);
	void update_button_choice_text(const Choice choice);
    void update_ai_button_choice_text(const Choice choice);
    void update_ai_predicted_button_choice_text(const Choice choice);
    void update_winner_name(const string name);
    void update_human_win_count(const int count);
    void update_computer_win_count(const int count);
    void update_tie_count(const int count);
private:
    Game *game_instance;
    int round_count;
    bool mode_ml;
	
	wxPanel *panel_button;
	wxPanel *panel_prediction;
	
    wxStaticText *chosen_button_name;
    wxStaticText *ai_chosen_button_name;
    wxStaticText *current_settings_button_name;
    wxStaticText *ai_predicted_chosen_button_name;
    wxStaticText *winner_name;
    wxStaticText *human_win_count;
    wxStaticText *computer_win_count;
    wxStaticText *tie_count;
	wxStaticText *round_num_name;
    /**
     * Initialize the panel contents.
     */
    void init();
};

