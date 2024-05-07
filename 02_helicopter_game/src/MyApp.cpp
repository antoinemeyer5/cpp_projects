#include "include/MyApp.hpp"

wxIMPLEMENT_APP(MyApp);

MyApp::MyApp()
{
}

MyApp::~MyApp()
{
}

bool MyApp::OnInit()
{
    m_frame = new MyMain();
    m_frame->Show(true);
    return true;
}
