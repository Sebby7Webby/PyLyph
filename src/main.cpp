#define SDL_MAIN_HANDLED

#include <iostream> // Printing and debugging
#include <SDL3/SDL.h> // For basic window rendering and event handling (obviously...)
#include <defs.h> // All constants needed across files as well as structs
#include <collision.h> // Collision objects

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        std::cout << "SDL_Video failed to init: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Blython", DEFS::WINDOW_WIDTH, DEFS::WINDOW_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_Event event;

    SDL_FRect testRect{0, 0, 50, 50};
    CollisionObject Test(&testRect);

    bool running = true;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
            }
        }

              

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &testRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}