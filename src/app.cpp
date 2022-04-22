#include "app.h"
#include "MainWindow.h"
#include "game.h"

using namespace std;

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    if (!wxApp::OnInit()) return false;
    MainWindow *mainFrame = new MainWindow("Rock Paper Scissors", wxPoint(50, 50), wxSize(450, 340));
    mainFrame->Show(true);

    return true;
}
