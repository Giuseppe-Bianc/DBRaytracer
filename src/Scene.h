#pragma once
#include "Camera.h"
#include "Ray.h"
#include "RenderImage.h"
#include "Timer.h"
#include "headers.h"
#include "objsphere.h"
class Scene {
public:
    Scene();

    bool Render(RenderImage &outputImage) const;

private:
    Camera camera;
    ObjSphere testSphere;
};
