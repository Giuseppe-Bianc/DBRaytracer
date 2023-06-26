#pragma once
#include "objectbase.h"

class ObjSphere : public ObjectBase {
public:
    ObjSphere() = default;
    virtual ~ObjSphere() override = default;
    virtual bool TestIntersection(const Ray &castRay, glm::dvec3 &intPoint, glm::dvec3 &localNormal,
                                  SDL_Color &localColor) const noexcept override;

private:
};
