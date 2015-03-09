#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "graphic_element.h"

class Triangle : public GraphicElement {
public:
    Triangle(double x = 0.0, double y = 0.0, double scale = 1.0);

protected:
    void calculateVertices();

    void onChangedPosition();
};

#endif // TRIANGLE_H
