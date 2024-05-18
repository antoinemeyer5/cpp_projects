#include "include/main.hpp"
#include "include/Frame.hpp"

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Frame *m_frame = new Frame(wxT("Helicopter Game"));
    m_frame->Centre();
    m_frame->Show(true);

    return true;
}
