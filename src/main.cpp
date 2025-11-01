#include <SDL.h>
#include <iostream>

int main(int, char**) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << "\n";
        return 1;
    }
    SDL_Window* w = SDL_CreateWindow(
        "PBL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!w) { std::cerr << "CreateWindow: " << SDL_GetError() << "\n"; SDL_Quit(); return 1; }

    SDL_Renderer* r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!r) { std::cerr << "CreateRenderer: " << SDL_GetError() << "\n"; SDL_DestroyWindow(w); SDL_Quit(); return 1; }

    bool run = true; SDL_Event e;
    while (run) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) run = false;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) run = false;
        }
        SDL_SetRenderDrawColor(r, 30,30,30,255); SDL_RenderClear(r);
        SDL_Rect rect{100,100,200,150}; SDL_SetRenderDrawColor(r,220,80,80,255); SDL_RenderFillRect(r,&rect);
        SDL_RenderPresent(r);
    }
    SDL_DestroyRenderer(r); SDL_DestroyWindow(w); SDL_Quit();
    return 0;
}
