#ifndef BOARD_H
#define BOARD_H

#include "Helicopter.hpp"
#include <wx/wx.h>

class Board : public wxPanel
{

    public:
        Board(wxFrame *parent);

    protected:
        void OnPaint(wxPaintEvent& event);
        void OnKeyDown(wxKeyEvent& event);

    private:
        void DrawTriangle(wxPaintDC &dc, int x, int y, int size);

        Helicopter helicopter;
        wxStatusBar *m_stsbar;
};

#endif