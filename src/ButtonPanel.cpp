#include "ButtonPanel.h"

using namespace std;

void ButtonPanel::init()
{
    game_instance = new Game();//initialize game instance

    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);
    
	// Round number UI
	wxPanel *round_num_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_num_panel_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *round_num_label =
            new wxStaticText(round_num_panel, wxID_ANY, "Round:");
    round_num_label->SetFont(round_num_label->GetFont().Scale(1.5).Bold());
    round_num_name = new wxStaticText(round_num_panel, wxID_ANY, "");
    round_num_name->SetFont(round_num_name->GetFont().Scale(1.5).Bold());

    round_num_panel_sizer->Add(round_num_label, 0, wxALIGN_RIGHT, 0);
    round_num_panel_sizer->Add(round_num_name, 0, 0, 0);
    round_num_panel->SetSizer(round_num_panel_sizer);
    
    // Human
	wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_panel_sizer = new wxGridSizer(0, 0, 5);

    wxStaticText *human_label =
            new wxStaticText(human_panel, wxID_ANY, "Human");
    human_label->SetFont(human_label->GetFont().Larger().Bold());
    human_panel_sizer->Add(human_label, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    human_panel->SetSizer(human_panel_sizer);

    // Button panel
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 wxT("Choose:"));
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(ROCK));
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(SCISSORS));

    rock_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);
   	
   	setButtonPanel(button_panel);
   	SetOptionsVisibility(panel_button, false); 

    // Choice panel
    wxPanel *choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *choice_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_object_label =
            new wxStaticText(choice_panel, wxID_ANY, "User Chosen object:");
    chosen_button_name = new wxStaticText(choice_panel, wxID_ANY, "");
    chosen_button_name->SetFont(chosen_button_name->GetFont().Larger());

    choice_sizer->Add(chosen_object_label, 0, wxALIGN_RIGHT, 0);
    choice_sizer->Add(chosen_button_name, 0, 0, 0);
    choice_panel->SetSizer(choice_sizer);
    
    // Computer
	wxPanel *computer_panel = new wxPanel(this, wxID_ANY);
    wxSizer *computer_panel_sizer = new wxGridSizer(0, 0, 5);

    wxStaticText *computer_label =
            new wxStaticText(computer_panel, wxID_ANY, "Computer");
    computer_label->SetFont(computer_label->GetFont().Larger().Bold());
    computer_panel_sizer->Add(computer_label, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    computer_panel->SetSizer(computer_panel_sizer);

    //ai choice panel panel
    wxPanel *ai_choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *ai_choice_panel_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *ai_chosen_object_label =
            new wxStaticText(ai_choice_panel, wxID_ANY, "AI Chosen Object:");
    ai_chosen_button_name = new wxStaticText(ai_choice_panel, wxID_ANY, "");
    ai_chosen_button_name->SetFont(ai_chosen_button_name->GetFont().Larger());

    ai_choice_panel_sizer->Add(ai_chosen_object_label, 0, wxALIGN_RIGHT, 0);
    ai_choice_panel_sizer->Add(ai_chosen_button_name, 0, 0, 0);
    ai_choice_panel->SetSizer(ai_choice_panel_sizer);

	//ai predicted choice panel panel
    wxPanel *ai_predicted_choice_panel = new wxPanel(this, wxID_ANY);
	wxSizer *ai_predicted_choice_panel_sizer = new wxGridSizer(2, 0, 5);

	wxStaticText *ai_predicted_chosen_object_label =
	        new wxStaticText(ai_predicted_choice_panel, wxID_ANY, "AI Predicted human's choice:");
	ai_predicted_chosen_button_name = new wxStaticText(ai_predicted_choice_panel, wxID_ANY, "");
	ai_predicted_chosen_button_name->SetFont(ai_predicted_chosen_button_name->GetFont().Larger());

	ai_predicted_choice_panel_sizer->Add(ai_predicted_chosen_object_label, 0, wxALIGN_RIGHT, 0);
	ai_predicted_choice_panel_sizer->Add(ai_predicted_chosen_button_name, 0, 0, 0);
	ai_predicted_choice_panel->SetSizer(ai_predicted_choice_panel_sizer);
	
	setPredictionPanel(ai_predicted_choice_panel);
	
    // Statistics
	wxPanel *statistics_panel = new wxPanel(this, wxID_ANY);
    wxSizer *statistics_panel_sizer = new wxGridSizer(0, 0, 5);

    wxStaticText *statistics_label =
            new wxStaticText(statistics_panel, wxID_ANY, "Statistics");
    statistics_label->SetFont(statistics_label->GetFont().Larger().Bold());
    statistics_panel_sizer->Add(statistics_label, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    statistics_panel->SetSizer(statistics_panel_sizer);
    
    //Winner panel
    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_panel_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *winner_label =
            new wxStaticText(winner_panel, wxID_ANY, "Round Winner:");
    winner_label->SetFont(winner_label->GetFont().Larger().Bold());
    winner_name = new wxStaticText(winner_panel, wxID_ANY, "");
    winner_name->SetFont(winner_name->GetFont().Larger());

    winner_panel_sizer->Add(winner_label, 0, wxALIGN_RIGHT, 0);
    winner_panel_sizer->Add(winner_name, 0, 0, 0);
    winner_panel->SetSizer(winner_panel_sizer);

    //human wins panel
    wxPanel *human_win_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_win_panel_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *human_win_label =
            new wxStaticText(human_win_panel, wxID_ANY, "Human_Wins: ");
    human_win_count = new wxStaticText(human_win_panel, wxID_ANY, "");
    human_win_count->SetFont(human_win_count->GetFont().Larger());

    human_win_panel_sizer->Add(human_win_label, 0, wxALIGN_RIGHT, 0);
    human_win_panel_sizer->Add(human_win_count, 0, 0, 0);
    human_win_panel->SetSizer(human_win_panel_sizer);

    //computer wins panel
    wxPanel *computer_win_panel = new wxPanel(this, wxID_ANY);
    wxSizer *computer_win_panel_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *computer_win_label =
            new wxStaticText(computer_win_panel, wxID_ANY, "Computer_Wins: ");
    computer_win_count = new wxStaticText(computer_win_panel, wxID_ANY, "");
    computer_win_count->SetFont(computer_win_count->GetFont().Larger());

    computer_win_panel_sizer->Add(computer_win_label, 0, wxALIGN_RIGHT, 0);
    computer_win_panel_sizer->Add(computer_win_count, 0, 0, 0);
    computer_win_panel->SetSizer(computer_win_panel_sizer);

    //tie count panel
    wxPanel *tie_count_panel = new wxPanel(this, wxID_ANY);
    wxSizer *tie_count_panel_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *tie_count_label =
            new wxStaticText(tie_count_panel, wxID_ANY, "Ties: ");
    tie_count = new wxStaticText(tie_count_panel, wxID_ANY, "");
    tie_count->SetFont(tie_count->GetFont().Larger());

    tie_count_panel_sizer->Add(tie_count_label, 0, wxALIGN_RIGHT, 0);
    tie_count_panel_sizer->Add(tie_count, 0, 0, 0);
    tie_count_panel->SetSizer(tie_count_panel_sizer);

    //current settings panel
    wxPanel *current_settings_panel = new wxPanel(this, wxID_ANY);
    wxSizer *current_settings_panel_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *current_settings_text = new wxStaticText(current_settings_panel, wxID_ANY, "Current AI Mode:");
    current_settings_button_name = new wxStaticText(current_settings_panel, wxID_ANY, "");
    current_settings_button_name->SetFont(current_settings_button_name->GetFont().Larger());

    current_settings_panel_sizer->Add(current_settings_text, 0, wxALIGN_RIGHT, 0);
    current_settings_panel_sizer->Add(current_settings_button_name, 0, 0, 0);
    current_settings_panel->SetSizer(current_settings_panel_sizer);

    // Main panel
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(round_num_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);
    main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(computer_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);
    main_panel_sizer->Add(ai_choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
	main_panel_sizer->Add(ai_predicted_choice_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(statistics_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);
    main_panel_sizer->Add(human_win_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(computer_win_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(tie_count_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(current_settings_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);

    SetSizer(main_panel_sizer);
}

void ButtonPanel::setButtonPanel(wxPanel *p) {
	panel_button = p;
}

void ButtonPanel::setPredictionPanel(wxPanel *p) {
	panel_prediction = p;
}

void ButtonPanel::SetOptionsVisibility(wxPanel *panel, bool is_shown) {
	is_shown ? panel->Enable() : panel->Disable();
	panel->Layout();
}

void ButtonPanel::SetPredictionVisibility(wxPanel *panel, bool is_shown) {
	is_shown ? panel->Enable() : panel->Disable();
	panel->Layout();
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    game_instance->on_user_choice_selection(ROCK);
    game_instance->determineWinner();
    update_round_num_choice_text(game_instance->return_round_ui());
    update_button_choice_text(ROCK);
    update_ai_button_choice_text(game_instance->return_computer_move());
    update_ai_predicted_button_choice_text(game_instance->return_computer_prediction());
    update_winner_name(game_instance->return_winner_name());
    update_human_win_count(game_instance->return_human_win_count());
    update_computer_win_count(game_instance->return_computer_win_count());
    update_tie_count(game_instance->return_ties_count());
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    game_instance->on_user_choice_selection(PAPER);
    game_instance->determineWinner();
    update_round_num_choice_text(game_instance->return_round_ui());
    update_button_choice_text(PAPER);
    update_ai_button_choice_text(game_instance->return_computer_move());
    update_ai_predicted_button_choice_text(game_instance->return_computer_prediction());
    update_winner_name(game_instance->return_winner_name());
    update_human_win_count(game_instance->return_human_win_count());
    update_computer_win_count(game_instance->return_computer_win_count());
    update_tie_count(game_instance->return_ties_count());
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    game_instance->on_user_choice_selection(SCISSORS);
    game_instance->determineWinner();
    update_round_num_choice_text(game_instance->return_round_ui());
    update_button_choice_text(SCISSORS);
    update_ai_button_choice_text(game_instance->return_computer_move());
    update_ai_predicted_button_choice_text(game_instance->return_computer_prediction());
    update_winner_name(game_instance->return_winner_name());
    update_human_win_count(game_instance->return_human_win_count());
    update_computer_win_count(game_instance->return_computer_win_count());
	update_tie_count(game_instance->return_ties_count());
}

void ButtonPanel::update_round_num_choice_text(const int round_num)
{
    round_num_name->SetLabelText(to_string(round_num));
}

void ButtonPanel::update_setting_choice_text(const string setting)
{
    current_settings_button_name->SetLabelText(setting);
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    chosen_button_name->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_ai_button_choice_text(const Choice choice)
{
    ai_chosen_button_name->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_ai_predicted_button_choice_text(const Choice choice)
{
    ai_predicted_chosen_button_name->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_winner_name(const string name)
{
    winner_name->SetLabelText(name);
}

void ButtonPanel::update_human_win_count(const int count)
{
    human_win_count->SetLabelText(to_string(count));
}

void ButtonPanel::update_computer_win_count(const int count)
{
    computer_win_count->SetLabelText(to_string(count));
}

void ButtonPanel::update_tie_count(const int count)
{
    tie_count->SetLabelText(to_string(count));
}

void ButtonPanel::input_round_count(int input)
{
	game_instance->reset_game();
    game_instance->set_round_count(input);
    update_button_choice_text(NONE);
    update_ai_button_choice_text(game_instance->return_computer_move());
    update_ai_predicted_button_choice_text(game_instance->return_computer_prediction());
    update_winner_name(game_instance->return_winner_name());
    update_human_win_count(game_instance->return_human_win_count());
    update_computer_win_count(game_instance->return_computer_win_count());
	update_tie_count(game_instance->return_ties_count());
}

void ButtonPanel::input_game_mode(string mode)
{
	SetOptionsVisibility(panel_button, true);
	if(mode == "RAND") {
		SetPredictionVisibility(panel_prediction, false);
	} else if(mode == "AI") {
		SetPredictionVisibility(panel_prediction, true);
	}
    game_instance->set_game_mode(mode);
    update_button_choice_text(NONE);
    update_ai_button_choice_text(game_instance->return_computer_move());
    update_ai_predicted_button_choice_text(game_instance->return_computer_prediction());
    update_winner_name(game_instance->return_winner_name());
    update_human_win_count(game_instance->return_human_win_count());
    update_computer_win_count(game_instance->return_computer_win_count());
	update_tie_count(game_instance->return_ties_count());
    game_instance->create_aifactory(mode);
}
