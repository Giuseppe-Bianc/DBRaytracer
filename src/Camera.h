#pragma once
#include "Ray.h"
#include "headers.h"
class Camera {
public:
    Camera() = default;

    void SetPosition(const glm::dvec3 &newPosition) noexcept { m_cameraPosition = newPosition; }
    void SetLookAt(const glm::dvec3 &newLookAt) noexcept { m_cameraLookAt = newLookAt; }
    void SetUp(const glm::dvec3 &upVector) noexcept { m_cameraUp = upVector; }
    void SetLength(double newLength) noexcept { m_cameraLength = newLength; }
    void SetHorzSize(double newHorzSize) noexcept { m_cameraHorzSize = newHorzSize; }
    void SetAspect(double newAspect) noexcept { m_cameraAspectRatio = newAspect; }

    glm::dvec3 GetPosition() const noexcept { return m_cameraPosition; }
    glm::dvec3 GetLookAt() const noexcept { return m_cameraLookAt; }
    glm::dvec3 GetUp() const noexcept { return m_cameraUp; }
    double GetLength() const noexcept { return m_cameraLength; }
    double GetHorzSize() const noexcept { return m_cameraHorzSize; }
    double GetAspect() const noexcept { return m_cameraAspectRatio; }
    glm::dvec3 GetU() const noexcept { return m_projectionScreenU; }
    glm::dvec3 GetV() const noexcept { return m_projectionScreenV; }
    glm::dvec3 GetScreenCentre() const noexcept { return m_projectionScreenCentre; }

    bool GenerateRay(double proScreenX, double proScreenY, Ray &cameraRay) const noexcept;

    void UpdateCameraGeometry();

private:
    glm::dvec3 m_cameraPosition{0.0, -10.0, 0.0};
    glm::dvec3 m_cameraLookAt{0.0, 0.0, 0.0};
    glm::dvec3 m_cameraUp{0.0, 0.0, 1.0};
    double m_cameraLength = 1.0;
    double m_cameraHorzSize = 1.0;
    double m_cameraAspectRatio = 1.0;

    glm::dvec3 m_alignmentVector{0.0};
    glm::dvec3 m_projectionScreenU{0.0};
    glm::dvec3 m_projectionScreenV{0.0};
    glm::dvec3 m_projectionScreenCentre{0.0};
};
