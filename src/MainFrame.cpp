#include "MainFrame.h"


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size), useVirtual(true), virtualListView(nullptr), plainListView(nullptr), 
    AddButton(nullptr), SearchButton(nullptr), EditButton(nullptr), DeleteButton(nullptr), mode("show")
{
    items = readItemsFromCsv();
    setupLayout();
}

std::vector<ItemData> MainFrame::readItemsFromCsv()
{
    std::ifstream stream(std::string("/aapl-1d.csv")); // should be copied by CMake to the bin directory

    // ignore header
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<ItemData> items;

    while (stream)
    {
        auto item = ItemData::fromCsvLine(stream);
        if (!item.date.empty())
        {
            items.push_back(item);
        }
    }

    return items;
}

void MainFrame::populateVirtualListView()
{
    virtualListView->setItems(items);
    virtualListView->RefreshAfterUpdate();
}

void MainFrame::populatePlainListView()
{
    for (int i = 0; i < items.size(); i++)
    {
        const auto &item = items[i];
        int insertionPoint = plainListView->GetItemCount();

        plainListView->InsertItem(insertionPoint, item.date);
        plainListView->SetItem(insertionPoint, 1, wxString::Format("%.2f", item.low));
        plainListView->SetItem(insertionPoint, 2, wxString::Format("%.2f", item.high));
        plainListView->SetItem(insertionPoint, 3, wxString::Format("%.2f", item.open));
        plainListView->SetItem(insertionPoint, 4, wxString::Format("%.2f", item.close));
        plainListView->SetItem(insertionPoint, 5, wxString::Format("%.0f", item.volume));
        plainListView->SetItem(insertionPoint, 6, wxString::Format("%d", item.ivr));
    }
}

void MainFrame::setupLayout()
{
    wxMenuBar *menuBar = new wxMenuBar;
    wxMenu *appMenu = new wxMenu;
    menuBar->Append(appMenu, "&Application");
        
    wxMenuItem *startitem = new wxMenuItem(appMenu, wxID_ANY, "&Start Game");
    appMenu->Append(startitem);
    Bind(wxEVT_MENU, &MainFrame::OnStartGame, this, startitem->GetId());

    SetMenuBar(menuBar);


//////////////////

    addVirtualList();
    //populateVirtualListView();
    
    AddButton = new wxButton(this, wxID_ANY, "Add");
    DeleteButton = new wxButton(this, wxID_ANY, "Delete");
    EditButton = new wxButton(this, wxID_ANY, "Edit");
    SearchButton = new wxButton(this, wxID_ANY, "Search");

    auto sizerVert = new wxBoxSizer(wxVERTICAL);
    auto buttonSizerHorizontal = new wxBoxSizer(wxHORIZONTAL);
    sizerVert->Add(virtualListView, 1, wxALL | wxEXPAND, 0);
    buttonSizerHorizontal->Add(AddButton, 0, wxALIGN_LEFT | wxLEFT | wxTOP | wxBOTTOM, 5);
    buttonSizerHorizontal->Add(DeleteButton, 0, wxALIGN_LEFT | wxLEFT | wxTOP | wxBOTTOM, 5);
    buttonSizerHorizontal->Add(EditButton, 0, wxALIGN_LEFT | wxLEFT | wxTOP | wxBOTTOM, 5);
    buttonSizerHorizontal->Add(SearchButton, 0, wxALIGN_LEFT | wxLEFT | wxTOP | wxBOTTOM, 5);
    sizerVert->Add(buttonSizerHorizontal);

    this->SetSizer(sizerVert);
    this->Layout();

}

void MainFrame::addPlainList()
{
    plainListView = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(800, 500), wxLC_REPORT);

    plainListView->AppendColumn("Date");
    plainListView->AppendColumn("Low");
    plainListView->AppendColumn("High");
    plainListView->AppendColumn("Open");
    plainListView->AppendColumn("Close");
    plainListView->AppendColumn("Volume");
    plainListView->AppendColumn("IVR");

    plainListView->SetColumnWidth(0, 180);
    plainListView->SetColumnWidth(5, 100);
}

void MainFrame::addVirtualList()
{
    virtualListView = new virtualShowListControl(this, wxID_ANY, wxDefaultPosition, wxSize(800, 500));
}


void MainFrame::OnQuit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a Rock Paper Scissors game", "About RPS", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnStartGame(wxCommandEvent& event)
{
    int dialog_return_value = wxNO; // initialize to a sane default value
    wxMessageDialog* dial = new wxMessageDialog(NULL, _("Select 'Yes' for TV show watchlist and 'No' for Song List"), _("Mode Selection"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    dialog_return_value = dial->ShowModal();
    // You do not have cancel button so only check wxYES and wxNO
    //cout << dialog_return_value << endl;
    switch( dialog_return_value) // Use switch, scales to more buttons later
    {
        case 5103 : //yes
            std::cout << "show" << std::endl;
            mode = "show";
        break;
        case 5104 : //no
            std::cout << "song" << std::endl;
            mode = "song";
        break;
        default : /* do nothing */ ;
    };
}