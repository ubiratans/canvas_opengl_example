#include "element_manager.h"

ElementManager::ElementManager() : m_reference_id(0) {
}

Triangle& ElementManager::addTriangle(double x, double y, double scale) {
    Triangle *ret = new Triangle(x, y, scale);

    m_elements_map[m_reference_id++] = ret;

    return *ret;
}

Point &ElementManager::addPoint(double x, double y, double scale) {
    Point *ret = new Point(x, y, scale);

    m_elements_map[m_reference_id++] = ret;

    return *ret;
}

void ElementManager::addPointArr(Point *arr, int size) {
    for (int i = 0; i < size; ++i) {
        m_elements_map[m_reference_id++] = arr++;
    }
}

std::map<uint, GraphicElement *>& ElementManager::getElementsMap() {
    return m_elements_map;
}

bool ElementManager::getElement(uint id, GraphicElement *element) {
    auto it = m_elements_map.find(id);

    if (it != m_elements_map.end()) {
        element = (*it).second;

        return true;
    }

    return false;
}

bool ElementManager::removeElement(uint id) {
    auto it = m_elements_map.find(id);

    if (it != m_elements_map.end()) {
        delete (*it).second;

        return true;
    }

    return false;
}
