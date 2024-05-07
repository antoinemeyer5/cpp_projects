#include <wx/wx.h>

#include "MyMain.hpp"

class MyApp : public wxApp
{
public:
    MyApp();
    ~MyApp();

private:
    MyMain *m_frame = nullptr;

public:
    virtual bool OnInit();
};
