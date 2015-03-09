#ifndef CANVAS_WIDGET_H
#define CANVAS_WIDGET_H

#include <QGLWidget>

#include "element_manager.h"

class Painter;

class CanvasWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = 0);
    void initializeGL();
    void draw();

    void resizeGL(int w, int h);
    void paintGL();

private:
    void init();

    ElementManager m_element_manager;
    Painter *m_painter;

signals:

public slots:

};

#endif // CANVAS_WIDGET_H
