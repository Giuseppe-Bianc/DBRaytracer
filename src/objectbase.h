#pragma once
#include "Ray.h"
#include "headers.h"
class ObjectBase {
public:
    // Constructor and destructor.
    ObjectBase() = default;
    virtual ~ObjectBase() = default;

    // Function to test for intersections.
    virtual bool TestIntersection(const Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal, SDL_Color &localColor) const;

    // Function to test whether two floating-point numbers are close to being equal.
    bool CloseEnough(const double f1, const double f2) const;

    // Public member variables.
public:
    // The base colour of the object.
    SDL_Color m_baseColor{0, 0, 0, 255};
};
