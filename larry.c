#include <SDL2/SDL.h>
#include <math.h>

//Function to draw a circle
void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int thickness)
{
    for (int angle = 0; angle < 360; angle++){
        double rad = angle * M_PI/180;
        for (int t = 0; t < thickness; t++){
        int x = centerX + (radius + t) * cos(rad);
        int y = centerY + (radius + t) * sin(rad);
        SDL_RenderDrawPoint(renderer, x, y);
    }
    }

}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Larry",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        600, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);


 // Mouth top
SDL_RenderDrawLine(renderer, 100, 240, 400, 240);


// Mouth middle
SDL_RenderDrawLine(renderer, 100, 200, 400, 200);


// Mouth bottom
SDL_RenderDrawLine(renderer, 100, 270, 400, 270);

// Teeth
for (int x = 100; x <= 400; x += 30) {
    SDL_RenderDrawLine(renderer, x, 200, x, 270);
}

// Eyes
drawCircle(renderer, 200 , 150 , 40, 1); 
drawCircle(renderer, 300 , 150 , 40, 1);
//Pupils
drawCircle(renderer, 200 , 150 , 5, 5); 
drawCircle(renderer, 300 , 150 , 5, 5);


// Head
SDL_RenderDrawLine(renderer, 260, 80, 210, 95);
SDL_RenderDrawLine(renderer, 120, 180, 210, 95);
SDL_RenderDrawLine(renderer, 140, 300, 120, 180);
SDL_RenderDrawLine(renderer, 200, 350, 140, 300);
SDL_RenderDrawLine(renderer, 140, 300, 200, 350);
SDL_RenderDrawLine(renderer, 350, 300, 200, 350);
SDL_RenderDrawLine(renderer, 350, 150, 350, 300);
SDL_RenderDrawLine(renderer, 260, 80, 350, 150);
//Shoulders 
SDL_RenderDrawLine(renderer, 300, 400, 350, 300);
SDL_RenderDrawLine(renderer, 400, 450, 300, 400);

SDL_RenderDrawLine(renderer, 600, 400, 400, 450);
//Shoulders 
SDL_RenderDrawLine(renderer, 150, 500, 200, 350);
SDL_RenderDrawLine(renderer, 50, 600, 150, 500);

 

SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


