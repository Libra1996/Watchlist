#include "MainWindow.h"

using namespace std;


//event table
BEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(wxID_EXIT, MainWindow::OnQuit)
    EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
END_EVENT_TABLE()

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size):
    wxFrame(NULL, wxID_ANY, title, pos, wxSize(450,600)), button_panel(new ButtonPanel(this))
{
    // MENU BAR
    wxMenuBar *menuBar = new wxMenuBar;
    wxMenu *appMenu = new wxMenu;
    menuBar->Append(appMenu, "&Application"); // "&" is shortcut for "Alt" key. & is an acclerator thus if you press "Alt+a" u can see the menu.

    //seperator
    appMenu->AppendSeparator();

    //about wxmenuitem
    wxMenuItem *aboutitem = new wxMenuItem(appMenu, wxID_ABOUT, "&About\tCtrl-A");
    appMenu->Append(aboutitem);

    //start wxmenuitem
    wxMenuItem *startitem = new wxMenuItem(appMenu, wxID_ANY, "&Start Game\tCtrl-N");
    appMenu->Append(startitem);
    Bind(wxEVT_MENU, &MainWindow::OnStartGame, this, startitem->GetId());

    //create wxmenuitem example
    wxMenuItem *quitItem = new wxMenuItem(appMenu, wxID_EXIT);
    appMenu->Append(quitItem);


    Bind(wxEVT_MENU, &MainWindow::OnQuit, this, wxID_EXIT);

    SetMenuBar(menuBar);
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnQuit(wxCommandEvent& event)
{
    Close(true);
}

void MainWindow::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a Rock Paper Scissors game\n""Designed by CMPE135 - Loopy\n", "About RPS", wxOK | wxICON_INFORMATION);
}

void MainWindow::OnStartGame(wxCommandEvent& event)
{
    int rcount = wxGetNumberFromUser( wxT("Set Number of Rounds\n"), wxT("Rounds: "),  wxT("RPS"), 20, 0, 100);
    if(rcount != -1) {
    	this->button_panel->input_round_count (rcount);
   	int dialog_return_value = wxNO; // initialize to a sane default value
    wxMessageDialog* dial = new wxMessageDialog(NULL, _("Use Machine Learning AI"), _("Mode Selection"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    dialog_return_value = dial->ShowModal();
    // You do not have cancel button so only check wxYES and wxNO
    //cout << dialog_return_value << endl;
    switch(dialog_return_value) // Use switch, scales to more buttons later
    {
        case 5103 : //yes
            //cout << "ML" << endl;
            this->button_panel->input_game_mode("AI");
            this->button_panel->update_setting_choice_text("ML AI");
        break;
        case 5104 : //no
            //cout << "RANDOM" << endl;
            this->button_panel->input_game_mode("RAND");
            this->button_panel->update_setting_choice_text("RANDOM AI");
        break;
        default : /* do nothing */ ;
    };
    }
}

