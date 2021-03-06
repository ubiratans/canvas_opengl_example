#ifndef CANVAS_WIDGET_H
#define CANVAS_WIDGET_H

#include <QGLWidget>

#include "camera.h"
#include "element_manager.h"

class Painter;
class QWheelEvent;

class CanvasWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = 0);
    void initializeGL();

    void resizeGL(int w, int h);
    void paintGL();

protected:
    void wheelEvent(QWheelEvent *event);
    void mouseDoubleClickEvent ( QMouseEvent * event );

    void keyPressEvent(QKeyEvent *event);

    void zoomIn(double zoom_factor, double focus_x, double focus_y);
    void zoomOut(double zoom_factor, double focus_x, double focus_y);

private:
    void init();

    Camera m_camera;
    ElementManager m_element_manager;
    Painter *m_painter;

    void setProjection(int w, int h);

    static const double m_max_width;
    static const double m_max_height;

signals:

public slots:

};

#endif // CANVAS_WIDGET_H
