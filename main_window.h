#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "canvas_widget.h"

class QVBoxLayout;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QVBoxLayout *m_main_layout;
    CanvasWidget *m_canvas_widget;
};

#endif // MAIN_WINDOW_H
