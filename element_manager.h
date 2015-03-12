#ifndef ELEMENT_MANAGER_H
#define ELEMENT_MANAGER_H

#include <cstdint>
#include <map>

#include "triangle.h"
#include "point.h"

class ElementManager {
public:
    ElementManager();

    Triangle& addTriangle(double x, double y, double scale = 1.0);
    Point& addPoint(double x, double y, double scale = 1.0);

    void addPointArr(Point* arr, int size);

    std::map< uint, GraphicElement*>& getElementsMap();

    bool getElement(uint id, GraphicElement *element);
    bool removeElement(uint id);

private:
    std::map< uint, GraphicElement* > m_elements_map;
    uint m_reference_id;
};

#endif // ELEMENT_MANAGER_H
