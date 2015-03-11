#include "camera.h"

Camera::Camera() : m_zoom(1.0), m_pos_x(0.0), m_pos_y(0.0) {
    init();
}

std::pair<double, double> Camera::getPosition() {
    return std::make_pair( m_pos_x, m_pos_y );
}

void Camera::setPosition(double x, double y) {
    m_pos_x = x;
    m_pos_y = y;
}

double Camera::getZoom() {
    return m_zoom;
}

bool Camera::setZoom(double zoom) {
    bool ret = false;

    if (zoom >= 0.25 && zoom <= 20.0) {
        m_zoom = zoom;

        ret = true;
    }

    return ret;
}

double Camera::getWorldLeft() {
    return m_world_left;
}

double Camera::getWorldRight() {
    return m_world_right;
}

double Camera::getWorldTop() {
    return m_world_top;
}

double Camera::getWorldBottom() {
    return m_world_bottom;
}

double Camera::getWorldWidth() {
    return m_world_width;
}

double Camera::getWorldHeight() {
    return m_world_height;
}

void Camera::reset() {
    init();
}

void Camera::init() {
    m_world_bottom = 0.0;
    m_world_top = 10.0;

    m_world_left = 0.0;
    m_world_right = 10.0;

    m_world_width = m_world_left - m_world_right;
    m_world_width *= (m_world_width < 0? -1: 1);

    m_world_height = m_world_top - m_world_bottom;
    m_world_height *= (m_world_height < 0? -1: 1);

    m_pos_x = m_world_left;
    m_pos_y = m_world_bottom;

    m_zoom = 1.0;
}
