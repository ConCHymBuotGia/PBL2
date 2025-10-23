#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Test SDL2 Window",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       640, 480, SDL_WINDOW_SHOWN);
    if (!win) {
        std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    std::cout << "Window created successfully!" << std::endl;

    SDL_Delay(3000);  // giữ cửa sổ 3 giây

    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
