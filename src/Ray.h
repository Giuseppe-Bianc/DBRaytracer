#pragma once
#include "headers.h"
class Ray {
public:
    explicit Ray() = default;

    Ray(const glm::dvec3 &point1, const glm::dvec3 &point2);

    glm::dvec3 GetPoint1() const { return m_point1; }

    glm::dvec3 GetPoint2() const { return m_point2; }

    glm::dvec3 m_point1{0.0, 0.0, 0.0};
    glm::dvec3 m_point2{0.0, 0.0, 1.0};
    glm::dvec3 m_lab = m_point2 - m_point1;
};
