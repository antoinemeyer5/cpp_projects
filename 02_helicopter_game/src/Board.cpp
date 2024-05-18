#include "include/Board.hpp"

Board::Board(wxFrame *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition,
        wxDefaultSize, wxBORDER_NONE)
{
    m_stsbar = parent->GetStatusBar();

    Connect(wxEVT_PAINT, wxPaintEventHandler(Board::OnPaint));
    Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Board::OnKeyDown));
}

void Board::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    DrawTriangle(dc, helicopter.GetCenterX(), helicopter.GetCenterY(),
        helicopter.GetSize());
}

void Board::OnKeyDown(wxKeyEvent& event)
{
    int keycode = event.GetKeyCode();

    int actualX = helicopter.GetCenterX();
    int speed = helicopter.GetSpeed();

    switch (keycode) {
        case WXK_LEFT:
            if(actualX - speed > speed) {
                helicopter.SetCenterX(actualX - speed);
            }
            break;
        case WXK_RIGHT:
            if(actualX + speed < 250 - speed) { // !!!! STATIC VALUE HERE
                helicopter.SetCenterX(actualX + speed);
            }
            break;
        default:
            event.Skip();
    }

    Refresh();
}

void Board::DrawTriangle(wxPaintDC& dc, int center_x, int center_y, int size)
{

    /*
    Triangle is:
           A
         / X \
        B --- C
    */

    wxPen pen(wxColour(248, 159, 171));
    pen.SetCap(wxCAP_PROJECTING);
    dc.SetPen(pen);

    // A -> B
    dc.DrawLine(center_x, center_y - size,
                center_x - size, center_y + size);
    // A -> C
    dc.DrawLine(center_x, center_y - size,
                center_x + size, center_y + size);
    // B -> C
    dc.DrawLine(center_x - size, center_y + size,
                center_x + size, center_y + size);

}