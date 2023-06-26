#pragma once
// clang-format off
#include "Timer.h"
#include "headers.h"
#include "RenderImage.h"
#include "Scene.h"
// clang-format on

class CApp {
public:
    CApp() = default;

    int OnExecute();
    bool OnInit();
    void OnEvent(const SDL_Event *event);
    void OnLoop() const;
    void OnRender();
    void OnExit();

private:
    inline void PrintVector(const std::string &msg, const glm::dvec3 &inputVector) const;

private:
    RenderImage image;
    Scene scene;
    //  SDL2 stuff.
    bool isRunning = true;
    SDL_Window *pWindow{nullptr};
    SDL_Renderer *pRenderer{nullptr};
};
