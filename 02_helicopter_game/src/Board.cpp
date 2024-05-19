#include "include/Board.hpp"

Board::Board(wxFrame *parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition,
        wxDefaultSize, wxBORDER_NONE)
{
    timer = new wxTimer(this, 1);
    timer->Start(300);
    m_stsbar = parent->GetStatusBar();

    Connect(wxEVT_PAINT, wxPaintEventHandler(Board::OnPaint));
    Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Board::OnKeyDown));
    Connect(wxEVT_TIMER, wxCommandEventHandler(Board::OnTimer));
}

void Board::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    // Helicopter
    DrawTriangle(dc, helicopter.GetCenterX(), helicopter.GetCenterY(),
        helicopter.GetSize());

    // Helicopter's missiles
    for(const Missile& m : helicopter.missiles){
        int h = m.GetHeight();
        int w = m.GetWidth();
        int TopLeftCorner_x = m.GetCenterX() - w/2;
        int TopLeftCorner_y = m.GetCenterY() - h/2;

        dc.DrawRectangle(TopLeftCorner_x, TopLeftCorner_y, w, h);
    }

    // Enemies: todo
    // Asteroids: todo
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
                Refresh();
            }
            break;
        case WXK_RIGHT:
            if(actualX + speed < 250 - speed) { /* !!! STATIC VALUE HERE !!! */
                helicopter.SetCenterX(actualX + speed);
                Refresh();
            }
            break;
        case WXK_UP:
            helicopter.FireMissile();
            break;
        default:
            event.Skip();
    }
}

void Board::OnTimer(wxCommandEvent& event)
{
    // Update helicopter's missiles
    for(Missile& m : helicopter.missiles){
        // Need to remove the missile
        if(m.GetCenterY() < 100){
            m = helicopter.missiles.back();
            helicopter.missiles.pop_back();
        }
        // Need to update the missile
        else {
            m.SetCenterY(m.GetCenterY() - m.GetSpeed());
            Refresh();
        }
    }
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
