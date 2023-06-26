#include "objectbase.h"
static inline constexpr double EPSILON = 1e-21;

bool ObjectBase::TestIntersection(const Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal,
                                  SDL_Color &localColor) const {
    return false;
}

bool ObjectBase::CloseEnough(const double f1, const double f2) const { return std::fabs(f1 - f2) < EPSILON; }
