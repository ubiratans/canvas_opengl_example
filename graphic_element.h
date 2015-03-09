#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <GL/gl.h>
#include <string>
#include <vector>

struct Color {
    Color() {
        m_r = m_alpha = 1.0;
        m_g = m_b = 0.0;
    }

    Color(double r, double g, double b, double alpha = 1.0) : m_r(r), m_g(g), m_b(b), m_alpha(alpha) {

    }

    double m_r;
    double m_g;
    double m_b;
    double m_alpha;
};

class GraphicElement {
public:
    virtual ~GraphicElement();

    std::string getLabel();
    void setLabel(std::string label);

    std::string getCode();
    void setCode(std::string code);

    Color getColor();
    void setColor(double r, double g, double b, double alpha = 1.0);
    void setColor(Color &color);

    GLenum getDrawMode();
    void setDrawMode(GLenum draw_mode);

    double getX();
    void setX(double x);

    double getY();
    void setY(double y);

    void setPosition(double x, double y);
    virtual void onChangedPosition() = 0;

    double getScale();
    void setScale(double scale);

    double getRotation();
    void setRotation(double angle);

    std::vector< std::pair< double, double > >& getVertexVec();

protected:
    GraphicElement(double x, double y);

    virtual void calculateVertices() = 0;

    std::vector< std::pair< double, double > > m_vertex_vec;
    GLenum m_draw_mode;

    double m_scale;
    double m_rotation_angle;
    double m_pos_x;
    double m_pos_y;

    Color m_color;
    std::string m_label;
    std::string m_code;
};

#endif // GRAPHICELEMENT_H
