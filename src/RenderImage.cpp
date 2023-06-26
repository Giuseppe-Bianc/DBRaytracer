#include "RenderImage.h"

RenderImage::~RenderImage() {
    if(m_pTexture != nullptr)
        SDL_DestroyTexture(m_pTexture);
}

void RenderImage::Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer) {
    m_colorData.resize(xSize, std::vector<SDL_Color>(ySize, {0, 0, 0, 0}));
    m_xSize = xSize;
    m_ySize = ySize;

    // Store the pointer to the renderer.
    m_pRenderer = pRenderer;

    // Initialise the texture.
    InitTexture();
}

void RenderImage::SetPixel(const int x, const int y, const SDL_Color &color) { m_colorData.at(x).at(y) = color; }

void RenderImage::Display() {
    // Allocate memory for a pixel buffer.
    std::vector<SDL_Color> tempPixels{C_ST(C_ST(m_xSize) * m_ySize), {0, 0, 0, 0}};
    std::size_t index{};

#pragma omp parallel for
    for(std::size_t x = 0; x < m_xSize; ++x) {
        for(std::size_t y = 0; y < m_ySize; ++y) {
            index = C_ST((y * m_xSize) + x);
            tempPixels[index] = m_colorData[x][y];
        }
    }

    // Update the texture with the pixel buffer.
    SDL_UpdateTexture(m_pTexture, nullptr, tempPixels.data(), C_I(m_xSize) * sizeof(SDL_Color));

    // Copy the texture to the renderer.
    const SDL_Rect srcRect{0, 0, m_xSize, m_ySize};
    SDL_Rect bounds;
    bounds = srcRect;
    SDL_RenderCopy(m_pRenderer, m_pTexture, &srcRect, &bounds);
}
void RenderImage::InitTexture() noexcept {
    // Delete any previously created texture.
    if(m_pTexture != nullptr)
        SDL_DestroyTexture(m_pTexture);
    // Create the texture that will store the image.
    SDL_Surface *tempSurface = SDL_CreateRGBSurfaceWithFormat(0, m_xSize, m_ySize, 32, SDL_PIXELFORMAT_RGBA32);
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}
