#include "point.h"

#include "point.h"

#include <cmath>

Point::Point() : GraphicElement(0, 0) {

}

Point::Point(double x, double y, double scale) : GraphicElement(x, y) {
    m_draw_mode = GL_TRIANGLES;
    setColor(0.0, 0.0, 0.0);

    m_scale = scale;

    calculateVertices();
}

void Point::calculateVertices() {
    double inc = 0.5;

    double min_x = getX() - inc;
    double max_x = getX() + inc;
    double min_y = getY() - inc;
    double max_y = getY() + inc;

    m_vertex_vec.clear();

    double vertices[3][2] = {
        { min_x, min_y },
        { getX(), max_y },
        { max_x, min_y}
    };

    m_vertex_vec.push_back(std::make_pair(vertices[0][0], vertices[0][1]));
    m_vertex_vec.push_back(std::make_pair(vertices[1][0], vertices[1][1]));
    m_vertex_vec.push_back(std::make_pair(vertices[2][0], vertices[2][1]));
}

void Point::onChangedPosition() {
    calculateVertices();
}
