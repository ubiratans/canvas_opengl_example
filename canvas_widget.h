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

    void zoomIn();
    void zoomOut();

protected:
    void wheelEvent(QWheelEvent *event);
    void mouseDoubleClickEvent ( QMouseEvent * event );

private:
    void init();

    Camera m_camera;
    ElementManager m_element_manager;
    Painter *m_painter;

    void setProjection(int w, int h);

signals:

public slots:

};

#endif // CANVAS_WIDGET_H
