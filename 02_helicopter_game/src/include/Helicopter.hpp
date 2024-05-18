#ifndef HELICOPTER_H
#define HELICOPTER_H

class Helicopter
{
    /*
    Helicopter is a triangle.
           A
         / X \
        B --- C
    A, B and C are summit; X is the center.
    */
    public:
        Helicopter(): center_x(125), center_y(320), size(10), speed(5) {}
        int GetCenterX() const { return center_x; }
        int GetCenterY() const { return center_y; }
        int GetSize() const { return size; }
        int GetSpeed() const { return speed; }
        void SetCenterX(int new_x) { center_x = new_x; }
        void SetCenterY(int new_y) { center_y = new_y; }

    private:
        int center_x, center_y;
        int size;
        int speed;
};

#endif
