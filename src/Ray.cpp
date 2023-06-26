#include "Ray.h"

Ray::Ray(const glm::dvec3 &point1, const glm::dvec3 &point2) : m_point1(point1), m_point2(point2), m_lab(m_point2 - m_point1) {}
