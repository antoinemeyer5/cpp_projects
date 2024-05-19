#ifndef MISSILE_H
#define MISSILE_H

class Missile
{
    /*
    Missile is a rectangle.
        A --- B
        |  X  |
        C --- D
    A, B, C and D are summit; X is the center.
    */
    public:
        Missile(int x, int y): center_x(x), center_y(y), height(10), width(3), speed(10) {}
        int GetCenterX() const { return center_x; }
        int GetCenterY() const { return center_y; }
        int GetHeight() const { return height; }
        int GetWidth() const { return width; }
        int GetSpeed() const { return speed; }
        void SetCenterY(int new_y) { center_y = new_y; }

    private:
        int center_x, center_y;
        int height, width;
        int speed;
};

#endif
