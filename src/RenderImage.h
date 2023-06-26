#pragma once
#include "headers.h"

class RenderImage {
public:
    RenderImage() = default;

    ~RenderImage();

    void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);

    // Function to set the colour of a pixel.
    void SetPixel(const int x, const int y, const SDL_Color &color);

    // Function to return the image for display.
    void Display();

    // Functions to return the dimensions of the image.
    inline int GetXSize() const noexcept { return m_xSize; }
    inline int GetYSize() const noexcept { return m_ySize; }

private:
    // SDL_Color ConvertColor(const double red, const double green, const double blue) const noexcept;
    void InitTexture() noexcept;

private:
    // Arrays to store image data.
    std::vector<std::vector<SDL_Color>> m_colorData;

    // And store the size of the image.
    int m_xSize = 0, m_ySize = 0;

    // SDL2 stuff.
    SDL_Renderer *m_pRenderer{nullptr};
    SDL_Texture *m_pTexture{nullptr};
};
