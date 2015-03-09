#include "canvas_widget.h"

#include <GL/gl.h>

#include "painter.h"

CanvasWidget::CanvasWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers|QGL::AlphaChannel), parent)
{

    m_element_manager.addTriangle(100, 100, 50);

    Triangle &t = m_element_manager.addTriangle(100, 100, 50);

    t.setRotation(-180);
    t.setColor(1.0, 0, 0);

    m_element_manager.addTriangle(200, 150, 25);

   m_element_manager.addTriangle(150, 100, 30);
    m_element_manager.addTriangle(200, 100, 20);

    Triangle &t2 = m_element_manager.addTriangle(150, 150, 20);
    t2.setRotation(60);

    m_element_manager.addTriangle(200, 150, 20);

    m_element_manager.addTriangle(200, 200, 20);

    m_painter = new Painter(*this, m_element_manager);
}

void CanvasWidget::initializeGL() {
    m_painter->init();
}

void CanvasWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h); // screen coordinates

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // wgs-84 ou UTM
    // definir: w-max e h-max

    // FRUSTRUM
    // Coordenadas do mundo, UTM ou WGS-84
    glOrtho(0.0, w, 0.0, h, 0.0, 1.0); // coordenadas do mundo - que nesse caso vão ser iguais a da camera

    glMatrixMode(GL_MODELVIEW);
}

void CanvasWidget::paintGL() {
    m_painter->paint();
}
