#pragma once

#include <wx/wx.h>
#include <wx/numdlg.h> 
#include "ButtonPanel.h"

using namespace std;



class MainWindow: public wxFrame
{
public:
    MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
    ~MainWindow();
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnStartGame(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
private:
    ButtonPanel *button_panel;
};
