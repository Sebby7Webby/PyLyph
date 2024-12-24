#define SDL_MAIN_HANDLED

#include <iostream> // Printing and debugging
#include <string> // For strings :cool-emoji
#include <SDL3/SDL.h> // For basic window rendering and event handling (obviously...)
#include <SDL3_image/SDL_image.h> // For images..?
#include <defs.h> // All constants needed across files as well as structs
#include <collision.h> // Collision objects

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        std::cout << "SDL_Video failed to init: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Blython", DEFS::WINDOW_WIDTH, DEFS::WINDOW_HEIGHT, SDL_WINDOW_MAXIMIZED);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_Event event;

    std::string imgPath = "../imgs/";
    SDL_Surface *testSurface = IMG_Load((imgPath + "EMOTION.png").c_str());
    SDL_Texture *testTexture = SDL_CreateTextureFromSurface(renderer, testSurface);
    SDL_free(testSurface);

    SDL_FRect dragRect{0, 0, 50, 50};
    CollisionObject Drag(&dragRect);

    SDL_FRect collideRect{DEFS::WINDOW_WIDTH/2, DEFS::WINDOW_HEIGHT/2, 100, 100};
    CollisionObject Collide(&collideRect);

    float mouseX;
    float mouseY;

    bool running = true;
    bool mouseDown = false;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        mouseDown = true;
                    }
                    break;
                case SDL_EVENT_MOUSE_BUTTON_UP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        mouseDown = false;
                    }
            }
        }
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseDown) {
            dragRect.x = mouseX - dragRect.w/2;
            dragRect.y = mouseY - dragRect.h/2; 
        }
        
        std::cout << Drag.isColliding(&Collide);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &collideRect);

        SDL_RenderTexture(renderer, testTexture, nullptr, &dragRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}