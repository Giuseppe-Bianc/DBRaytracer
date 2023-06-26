#include "objsphere.h"

bool ObjSphere::TestIntersection(const Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal, SDL_Color &localColor) const {
    // Compute the values of a, b and c.
    glm::dvec3 vhat = castRay.m_lab;
    vhat = glm::normalize(vhat);

    /* Note that a is equal to the squared magnitude of the
        direction of the cast ray. As this will be a unit vector,
        we can conclude that the value of 'a' will always be 1. */
    double a = 1.0;

    // Calculate b.
    double b = 2.0 * glm::dot(castRay.m_point1, vhat);

    // Calculate c.
    double c = glm::dot(castRay.m_point1, castRay.m_point1) - 1.0;

    // Test whether we actually have an intersection.
    double intTest = (b * b) - 4.0 * a * c;

    if(intTest > 0.0) {
        double numSQRT = sqrt(intTest);
        double t1 = (-b + numSQRT) / (2.0 * a);
        double t2 = (-b - numSQRT) / (2.0 * a);

        /* If either t1 or t2 are negative, then at least part of the object is
            behind the camera and so we will ignore it. */
        if((t1 < 0.0) || (t2 < 0.0)) {
            return false;
        } else {
            // Determine which point of intersection was closest to the camera.
            if(t1 < t2) {
                intPoint = castRay.m_point1 + (vhat * t1);
            } else {
                intPoint = castRay.m_point1 + (vhat * t2);
            }
        }

        return true;
    } else {
        return false;
    }
}
