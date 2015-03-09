#include "graphic_element.h"

GraphicElement::GraphicElement(double x, double y) : m_pos_x(x), m_pos_y(y), m_rotation_angle(0), m_scale(1.0) {
}

GraphicElement::~GraphicElement() {

}

std::string GraphicElement::getLabel() {
    return m_label;
}

void GraphicElement::setLabel(std::string label) {
    m_label = label;
}

std::string GraphicElement::getCode() {
    return m_code;
}

void GraphicElement::setCode(std::string code) {
    m_code = code;
}

Color GraphicElement::getColor() {
    return m_color;
}

void GraphicElement::setColor(double r, double g, double b, double alpha) {
    m_color = Color(r, g, b, alpha);
}

void GraphicElement::setColor(Color &color) {
    m_color = color;
}

GLenum GraphicElement::getDrawMode() {
    return m_draw_mode;
}

void GraphicElement::setDrawMode(GLenum draw_mode) {
    m_draw_mode = draw_mode;
}

double GraphicElement::getX() {
    return m_pos_x;
}

void GraphicElement::setX(double x) {
    m_pos_x = x;

    onChangedPosition();
}

double GraphicElement::getY() {
    return m_pos_y;
}

void GraphicElement::setY(double y) {
    m_pos_y = y;

    onChangedPosition();
}

void GraphicElement::setPosition(double x, double y) {
    m_pos_x = x;
    m_pos_y = y;

    onChangedPosition();
}

double GraphicElement::getScale() {
    return m_scale;
}

void GraphicElement::setScale(double scale) {
    m_scale = scale;
}

double GraphicElement::getRotation() {
    return m_rotation_angle;
}

void GraphicElement::setRotation(double angle) {
    m_rotation_angle = angle;
}

std::vector< std::pair< double, double > >& GraphicElement::getVertexVec() {
    return m_vertex_vec;
}
