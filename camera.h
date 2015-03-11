#ifndef CAMERA_H
#define CAMERA_H

#include <utility>

class Camera {
public:
    Camera();

    std::pair< double, double > getPosition();
    void setPosition(double x, double y);

    double getZoom();
    bool setZoom(double zoom);

    double getWorldLeft();
    double getWorldRight();

    double getWorldTop();
    double getWorldBottom();

    double getWorldWidth();
    double getWorldHeight();

    void reset();

private:
    void init();

    double m_pos_x;
    double m_pos_y;

    double m_world_left;
    double m_world_right;
    double m_world_top;
    double m_world_bottom;

    double m_world_width;
    double m_world_height;

    double m_zoom;
};

#endif // CAMERA_H
