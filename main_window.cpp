#include "main_window.h"

#include <GL/gl.h>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    m_canvas_widget = new CanvasWidget(this);

    m_main_layout = new QVBoxLayout();
   // m_main_layout->addWidget(m_canvas_widget, 1);

    setCentralWidget(m_canvas_widget);

   // setLayout(m_main_layout);
    setMinimumSize(950, 950);
}

MainWindow::~MainWindow()
{

}
