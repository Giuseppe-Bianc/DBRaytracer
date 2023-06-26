#include "CApp.h"

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        QBERROR("SDL could not initialize! SDL_Error: {}", SDL_GetError());
        return false;
    }

    pWindow = SDL_CreateWindow("qbRayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

    if(pWindow != nullptr) {
        QBINFO("creazione SDL window di dimensioni(w: {}, h: {})", w, h);
        // Initialise the renderer.
        pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        image.Initialize(w, h, pRenderer);
        scene.Render(image);
        if(pRenderer == nullptr) {
            QBERROR("SDL could not initialize window! SDL_Error: {}", SDL_GetError());
            SDL_DestroyWindow(pWindow);
            SDL_Quit();
            return false;
        }
    } else {
        QBERROR("SDL could not initialize window! SDL_Error: {}", SDL_GetError());
        SDL_Quit();
        return false;
    }

    return true;
}

int CApp::OnExecute() {
    SDL_Event event;

    if(OnInit() == false) {
        return -1;
    }

    while(isRunning) {
        while(SDL_PollEvent(&event) != 0) {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }

    OnExit();
    QBSYSPAUSE()
    return 0;
}

void CApp::OnEvent(const SDL_Event *event) {
    switch(event->type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        switch(event->key.keysym.sym) {
        case SDLK_ESCAPE:
            isRunning = false;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void CApp::OnLoop() const {
    // empty
}

void CApp::OnRender() {
    // Set the background color to white.
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);
    image.Display();
    //  Show the result.
    SDL_RenderPresent(pRenderer);
}

void CApp::OnExit() {
    Timer timer{"OnExit"};
    // Tidy up SDL2 stuff.
    if(pRenderer != nullptr) {
        SDL_DestroyRenderer(pRenderer);
        pRenderer = nullptr;
    }
    if(pWindow != nullptr) {
        SDL_DestroyWindow(pWindow);
        pWindow = nullptr;
    }
    SDL_Quit();
}

// PRIVATE FUNCTIONS.
inline void CApp::PrintVector(const std::string &msg, const glm::dvec3 &inputVector) const {
    QBINFO("{} {}", msg, glm::to_string(inputVector));
}
