#ifndef POINT_H
#define POINT_H

#include "graphic_element.h"

class Point : public GraphicElement {
public:
    Point();
    Point(double x = 0.0, double y = 0.0, double scale = 0.15);

protected:
    void calculateVertices();

    void onChangedPosition();
};

#endif // POINT_H
