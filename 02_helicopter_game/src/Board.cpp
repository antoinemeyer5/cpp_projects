#include "include/Board.hpp"

Board::Board(wxFrame *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition,
        wxDefaultSize, wxBORDER_NONE)
{
    m_stsbar = parent->GetStatusBar();

    Connect(wxEVT_PAINT, wxPaintEventHandler(Board::OnPaint));
}

void Board::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    DrawTriangle(dc, helicopter.GetCenterX(), helicopter.GetCenterY(), helicopter.GetSize());
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