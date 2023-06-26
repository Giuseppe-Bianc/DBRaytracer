#include "Camera.h"
void Camera::UpdateCameraGeometry() {
    // First, compute the vector from the camera position to the LookAt position.
    m_alignmentVector = glm::normalize(m_cameraLookAt - m_cameraPosition);

    // Second, compute the alpha and beta unit vectors.
    m_projectionScreenU = glm::normalize(glm::cross(m_alignmentVector, m_cameraUp));
    m_projectionScreenV = glm::normalize(glm::cross(m_projectionScreenU, m_alignmentVector));

    // Thirdly, compute the position of the center point of the screen.
    m_projectionScreenCentre = m_cameraPosition + (m_cameraLength * m_alignmentVector);

    // Modify the U and V vectors to match the size and aspect ratio.
    m_projectionScreenU *= m_cameraHorzSize;
    m_projectionScreenV *= (m_cameraHorzSize / m_cameraAspectRatio);
}

bool Camera::GenerateRay(double proScreenX, double proScreenY, Ray &cameraRay) const {
    // Compute the location of the screen point in world coordinates.
    glm::dvec3 screenWorldPart1 = m_projectionScreenCentre + (m_projectionScreenU * proScreenX);
    glm::dvec3 screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);

    // Use this point along with the camera position to compute the ray.
    cameraRay.m_point1 = m_cameraPosition;
    cameraRay.m_point2 = screenWorldCoordinate;
    cameraRay.m_lab = screenWorldCoordinate - m_cameraPosition;

    return true;
}
