#include "include/Frame.hpp"
#include "include/Board.hpp"

Frame::Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 420))
{
    wxStatusBar *sb = CreateStatusBar();
    sb->SetStatusText(wxT("0"));
    Board *board = new Board(this);
    board->SetFocus();
}
