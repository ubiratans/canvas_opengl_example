#ifndef PAINTER_H
#define PAINTER_H

#include "graphic_element.h"
#include "canvas_widget.h"
#include "element_manager.h"

class Painter {
public:
    Painter(CanvasWidget &canvas, ElementManager &manager);

    void init();
    void paint();

    void drawElements();
    void drawElement(GraphicElement &element);

private:
    ElementManager *m_element_manager;
    CanvasWidget *m_canvas;
};

#endif // PAINTER_H
