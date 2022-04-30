
#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/stopwatch.h>

#include <string>
#include <vector>
#include <unordered_set>

#include <fstream>
#include <filesystem>

#include "itemdata.h"
#include "simplevirtuallistcontrol.h"
#include "virtualShowListControl.h"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnStartGame(wxCommandEvent& event);

private:
    virtualShowListControl *virtualListView;
    wxListCtrl *plainListView;

    std::string mode;

    wxButton *AddButton;
    wxButton *SearchButton;
    wxButton *EditButton;
    wxButton *DeleteButton;

    std::vector<ItemData> readItemsFromCsv();
    std::vector<ItemData> items;

    void populateVirtualListView();
    void populatePlainListView();
    void setupLayout();
    void addPlainList();
    void addVirtualList();
    

    bool useVirtual;
};
