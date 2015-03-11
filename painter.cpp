#include "painter.h"

Painter::Painter(CanvasWidget &canvas, ElementManager &manager) : m_canvas(&canvas), m_element_manager(&manager) {
}

void Painter::init() {
    m_canvas->makeCurrent();

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Painter::paint() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawElements();

    glFlush();
}

void Painter::drawElements() {
    for (auto it : m_element_manager->getElementsMap()) {
        drawElement(*it.second);
    }
}

void Painter::drawElement(GraphicElement &element) {
    glColor3d(element.getColor().m_r, element.getColor().m_g, element.getColor().m_b);

    bool rotate = (int(element.getRotation() / 360) * 360 == element.getRotation()? false: true);
    bool scale = (element.getScale() != 1.0? true: false);

    if (rotate) {
        glTranslated(element.getX(), element.getY(), 0.0);

        glRotated(element.getRotation(), 0.0, 0.0, 1.0);

        glTranslated(-1 * element.getX(), -1 * element.getY(), 0.0);
    }

    if (scale) {
        glTranslated(element.getX(), element.getY(), 0.0);

        glScaled(element.getScale(), element.getScale(), 1.0);

        glTranslated(-1 * element.getX(), -1 * element.getY(), 0.0);
    }

    glBegin(element.getDrawMode());
        for (auto vertex : element.getVertexVec()) {
            glVertex2d( vertex.first, vertex.second );
        }
    glEnd();

    glLoadIdentity();
}
