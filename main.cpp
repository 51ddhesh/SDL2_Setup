#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Window",           // Window title
        SDL_WINDOWPOS_CENTERED,  // X position (centered)
        SDL_WINDOWPOS_CENTERED,  // Y position (centered)
        800,                     // Width of the window
        600,                     // Height of the window
        SDL_WINDOW_SHOWN         // Show the window
    );

    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer (for drawing to the window)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    bool quit = false;
    SDL_Event event;

    // Main loop
    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the window with a color (RGB: 0, 0, 255 = Blue)
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Set draw color to blue
        SDL_RenderClear(renderer); // Clear the screen with the current color

        // Present the backbuffer to the screen (i.e., update the window)
        SDL_RenderPresent(renderer);
    }

    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
