#pragma once
#include "Ray.h"
#include "headers.h"
class Camera {
public:
    Camera() = default;

    void SetPosition(const glm::dvec3 &newPosition) { m_cameraPosition = newPosition; }
    void SetLookAt(const glm::dvec3 &newLookAt) { m_cameraLookAt = newLookAt; }
    void SetUp(const glm::dvec3 &upVector) { m_cameraUp = upVector; }
    void SetLength(double newLength) { m_cameraLength = newLength; }
    void SetHorzSize(double newHorzSize) { m_cameraHorzSize = newHorzSize; }
    void SetAspect(double newAspect) { m_cameraAspectRatio = newAspect; }

    glm::dvec3 GetPosition() const { return m_cameraPosition; }
    glm::dvec3 GetLookAt() const { return m_cameraLookAt; }
    glm::dvec3 GetUp() const { return m_cameraUp; }
    double GetLength() const { return m_cameraLength; }
    double GetHorzSize() const { return m_cameraHorzSize; }
    double GetAspect() const { return m_cameraAspectRatio; }
    glm::dvec3 GetU() const { return m_projectionScreenU; }
    glm::dvec3 GetV() const { return m_projectionScreenV; }
    glm::dvec3 GetScreenCentre() const { return m_projectionScreenCentre; }

    bool GenerateRay(double proScreenX, double proScreenY, Ray &cameraRay) const;

    void UpdateCameraGeometry();

private:
    glm::dvec3 m_cameraPosition{0.0, -10.0, 0.0};
    glm::dvec3 m_cameraLookAt{0.0, 0.0, 0.0};
    glm::dvec3 m_cameraUp{0.0, 0.0, 1.0};
    double m_cameraLength = 1.0;
    double m_cameraHorzSize = 1.0;
    double m_cameraAspectRatio = 1.0;

    glm::dvec3 m_alignmentVector;
    glm::dvec3 m_projectionScreenU;
    glm::dvec3 m_projectionScreenV;
    glm::dvec3 m_projectionScreenCentre;
};
