#include "include/MyMain.hpp"

MyMain::MyMain()
    : wxFrame(NULL, wxID_ANY, "Hello World", wxPoint(30, 30), wxSize(800, 600))
{
}

MyMain::~MyMain()
{
}

void MyMain::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyMain::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyMain::OnExit(wxCommandEvent& event)
{
    Close(true);
}
