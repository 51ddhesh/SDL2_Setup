# SDL2 - Simple DirectMedia Layer 2
- SDL2 is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, and graphics hardware via OpenGL and Direct3D. It is commonly used for game development, multimedia applications, and other performance-sensitive tasks that require direct interaction with hardware components.
- SDL2 is highly portable, running on Windows, macOS, Linux, and even mobile platforms like iOS and Android. It abstracts away the complexity of handling different operating systems, providing a unified API for creating rich multimedia experiences. With SDL2, developers can focus on building their application's logic without worrying about platform-specific details.
- SDL2 is often chosen by developers for its simplicity, performance, and ease of integration into both small and large projects. Whether you're building a game, a multimedia tool, or an emulator, SDL2 provides a solid foundation for your application's needs.
<br><br>

# Installing SDL2 on Windows
### Step 1 - Downloading the release
- Go to the [Official Releases of SDL2  on GitHub]([https://github.com/libsdl-org](https://github.com/libsdl-org/SDL/releases))
- Download the developer version of SDL2. As of 04-01-2024, it is <code>SDL2-devel-2.30.11-mingw.tar.gz</code>
- **NOTE**: It is necessary to install <code>SDL2</code> library. Check out the documentations at [the official SDL website](https://libsdl.org/).
### Step 2 - Extracting
- Navigate to Downloads
```sh
# bash
cd Downloads
```
- Make a directory to store the extracted contents
```sh
# bash
mkdir SDL
```
- Extract and store the contents in the newly created folder
```sh
# bash
tar -xvzf SDL2-devel-2.30.11-mingw.tar.gz -C SDL
```
- Now move the <code>SDL</code> directory to the home directory to keep track of it.

### Step 3 - Setting up the project
- Create the project directory in home folder
```sh
# bash
mkdir Project
cd Project
```
- Create a <code>src</code> folder to place the <code>SDL</code> libraries and headers
```sh
# bash
mkdir src
```
- From the <code>SDL</code> directory, choose the correct version (32/64 bit) and copy the <code>include</code> and the <code>lib</code> folders to the <code>Project/src</code> directory.
Copy the <code>SDL2.dll</code> binary from the compatible version and paste it into the <code>Project</code> directory. 

```sh
SDL2-2.30.11/
├── cmake/
├── docs/
├── i686-w64-mingw32/
│   ├── include/
│   ├── bin/
│   │   ├── SDL2.dll
│   │   └── sdl2-config
│   └── lib/
├── tests/
└── x86_64-w64-mingw32/
    ├── include/
    ├── bin/
    │   ├── SDL2.dll
    │   └── sdl2-config
    └── lib/
```

```sh
Project/
└── src/
│   ├── include/
│   └── lib/
└── SDL2.dll
```

#### The setup is now complete and the <code>main.cpp</code> or the <code>main.c</code> file should run properly without any errors. The compilation and run functionalities and configuration can be found in the below.

You can test the setup by making the <code>main.cpp</code> or the <code>main.c</code>
```sh
# bash
touch main.cpp
```
Fill in this sample program in <code>main.cpp</code> to test.
```cpp
// cpp

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
```

# Compiling and Running 

## **Compiling**
### Method 1 - Using <code> makefile</code>
#### Step 1: Check if <code>make</code> is available
```sh
# bash
make --version
```
If <code>make</code> was installed from MinGW,
```sh
# bash
mingw32-make --version
```
#### Step 2: Configuring <code>makefile</code>
Create a <code>makefile</code> in the same directory as <code>main.cpp</code> or <code>main.c</code>
as given below
```sh
# bash
touch Makefile
```
Setup the linker and include paths
```makefile
# Makefile
all:
    g++ -Isrc/Include -Lsrc/Lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
```
#### Step 3: Compiling and Running
Compile <code>main.cpp</code> using 
```sh
# bash
make
```
For MinGW-based <code>make</code>, compile using
```sh
# bash
mingw32-make
```
To run
```sh
# bash
./main
```

### Method 2: Explicit Compilation
> It is recommended to use <code>make</code> to run these files. But if <code>make</code> is not configured properly or does not support a system, the program can be explicitly compiled.

#### Step 1: To compile
```sh
# bash
g++ -Isrc/Include -Lsrc/Lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
```
#### Step 2: To run
```sh
# bash
./main
```

With this setup, the program should run successfully.<br>
Feel free to raise issues if you face any problems.
