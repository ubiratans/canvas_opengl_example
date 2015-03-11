#include "canvas_widget.h"

#include <GL/gl.h>
#include <QWheelEvent>

#include <QDebug>

#include "painter.h"

CanvasWidget::CanvasWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers|QGL::AlphaChannel), parent)
{
    m_element_manager.addTriangle(5, 5, 3);

    //m_element_manager.addTriangle(0, 0, 10);

    /*Triangle &t = m_element_manager.addTriangle(50, 0, 10);

    t.setRotation(-180);
    t.setColor(1.0, 0, 0);*/

    m_painter = new Painter(*this, m_element_manager);
}

void CanvasWidget::initializeGL() {
    m_painter->init();
}

void CanvasWidget::resizeGL(int w, int h) {
    setProjection(w, h);
}

void CanvasWidget::paintGL() {
    m_painter->paint();

    setProjection(width(), height());

}

void CanvasWidget::wheelEvent(QWheelEvent *event) {
    double max_width = 800;
    double max_height = 600;

    double zoom_prop = m_camera.getZoom() + (event->delta() < 0? -1.0: +1.0);

    double width_prop = width() / (max_width);
    double height_prop = height() / (max_height);

    // pontos de origem da camera em coordenadas do mundo
    double camera_x = m_camera.getPosition().first;
    double camera_y = m_camera.getPosition().second;

    double canvas_right = camera_x + (m_camera.getWorldWidth() * width_prop) / m_camera.getZoom();
    double canvas_top = camera_y + (m_camera.getWorldHeight() * height_prop) / m_camera.getZoom();

    if (!m_camera.setZoom(zoom_prop)) {
        return;
    }

    double current_x = camera_x + ((canvas_right - camera_x) / width()) * event->x();
    double current_y = camera_y + ((canvas_top - camera_y) / height()) * (height() - event->y());

    double camera_new_x = camera_x + (current_x - camera_x) / m_camera.getZoom();
    double camera_new_y = camera_y + (current_y - camera_y) / m_camera.getZoom();

    double canvas_new_right = camera_new_x + (m_camera.getWorldWidth() * width_prop) / m_camera.getZoom();
    double canvas_new_top = camera_new_y + (m_camera.getWorldHeight() * height_prop) / m_camera.getZoom();

    while (canvas_new_right > m_camera.getWorldRight() || canvas_new_top > m_camera.getWorldTop()) {
        m_camera.setZoom(m_camera.getZoom() + 0.05);

        camera_new_x = camera_x + (current_x - camera_x) / m_camera.getZoom();
        camera_new_y = camera_y + (current_y - camera_y) / m_camera.getZoom();

        canvas_new_right = camera_new_x + (m_camera.getWorldWidth() * width_prop) / m_camera.getZoom();
        canvas_new_top = camera_new_y + (m_camera.getWorldHeight() * height_prop) / m_camera.getZoom();
    }

    qDebug() << "Canvas World Limits: (" << camera_x << ", " << canvas_right << ") (" << camera_y << ", " << canvas_top << ")";
    qDebug() << "Canvas New World Limits: (" << camera_new_x << ", " << canvas_new_right << ") (" << camera_new_y << ", " << canvas_new_top << ")";
    qDebug() << "Current mouse position: " << event->x() << "," << event->y();
    qDebug() << "Current world position: " << current_x << "," << current_y;
    qDebug() << "Zoom: " << m_camera.getZoom();

    m_camera.setPosition(camera_new_x, camera_new_y);

    updateGL();
}

void CanvasWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    m_camera.reset();

    updateGL();
}

void CanvasWidget::setProjection(int w, int h) {
    setMaximumSize(800, 600);

    double max_width = 800;
    double max_height = 600;

    glViewport(0, 0, w, h); // screen coordinates

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // wgs-84 ou UTM
    // definir: w-max e h-max

    // FRUSTRUM
    double width_prop = w / (max_width);
    double height_prop = h / (max_height);

    double pos_x = m_camera.getPosition().first;
    double pos_y = m_camera.getPosition().second;

    double right = pos_x + (m_camera.getWorldWidth() * width_prop) / m_camera.getZoom();
    double top = pos_y + (m_camera.getWorldHeight() * height_prop) / m_camera.getZoom();

    glOrtho(
                pos_x,
                right,
                pos_y,
                top,
                0.0,
                1.0
            );

    glMatrixMode(GL_MODELVIEW);
}
