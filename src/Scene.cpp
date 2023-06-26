#include "Scene.h"

Scene::Scene() {
    camera.SetPosition({0.0, -10.0, 0.0});
    camera.SetLookAt({0.0, 0.0, 0.0});
    camera.SetUp({0.0, 0.0, 1.0});
    camera.SetHorzSize(0.25);
    camera.SetAspect(16.0 / 9.0);
    camera.UpdateCameraGeometry();
}

bool Scene::Render(RenderImage &outputImage) const {
    Timer timer{"scene.Render"};
    SDL_Color color{0, 0, 0, 255};
    auto xSize = outputImage.GetXSize();
    auto ySize = outputImage.GetYSize();
    auto halfXSise = static_cast<double>(xSize) / 2.0;
    auto halfYSise = static_cast<double>(ySize) / 2.0;

    // Loop over each pixel in our image.
    Ray cameraRay;
    glm::dvec3 intPoint{0.0};
    glm::dvec3 localNormal{0.0};
    SDL_Color localColor{0, 0, 0, 0};
    double xFact = 1.0 / halfXSise;
    double yFact = 1.0 / halfYSise;
    double minDist = 1e6;
    double maxDist = 0.0;
    double normX = 0;
    double normY = 0;
#pragma omp parallel for
    for(auto x : std::views::iota(0, xSize)) {
        normX = (static_cast<double>(x) * xFact) - 1.0;
        for(auto y : std::views::iota(0, ySize)) {
            // Normalize the x and y coordinates.
            normY = (static_cast<double>(y) * yFact) - 1.0;

            camera.GenerateRay(normX, normY, cameraRay);

            bool validInt = testSphere.TestIntersection(cameraRay, intPoint, localNormal, localColor);

            if(validInt) {
                double dist = glm::length(intPoint - cameraRay.m_point1);

                if(dist > maxDist)
                    maxDist = dist;

                if(dist < minDist)
                    minDist = dist;
                color = SDL_COLOR(255.0 - ((dist - 9.0) / 0.94605) * 255.0, 0.0, 0.0, 255.0);
                outputImage.SetPixel(x, y, color);
            } else {
                color = {0, 0, 0, 255};
                outputImage.SetPixel(x, y, color);
            }
        }
    }

    QBINFO("Minimum distance: {}", minDist);
    QBINFO("Maximum distance: {}", maxDist);

    return true;
}
