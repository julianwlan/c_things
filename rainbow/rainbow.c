#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600
#define BLACK 0xffffff

Uint32 rgb_from_hsl(SDL_PixelFormat* pformat, double h, double s, double l) {
    double c = (1 - fabs(2 * l - 1)) * s;
    double hd = h/60;
    double x = c * (1 - fabs(fmod(hd, 2) - 1));

    double r1, g1, b1;
    if(hd >= 0 && hd < 1) {
        r1 = c;
        g1 = x;
        b1 = 0;
    }
    if(hd >= 1 && hd < 2) {
        r1 = x;
        g1 = c;
        b1 = 0;
    }
    if(hd >= 2 && hd < 3) {
        r1 = 0;
        g1 = c;
        b1 = x;
    }
    if(hd >= 3 && hd < 4) {
        r1 = 0;
        g1 = x;
        b1 = c;
    }
    if(hd >= 4 && hd < 5) {
        r1 = x;
        g1 = 0;
        b1 = c;
    }
    if(hd >= 5 && hd < 6) {
        r1 = c;
        g1 = 0;
        b1 = x;
    }

    double m = l - c / 2;
    Uint8 r = (int) ((r1 + m) * 255);
    Uint8 g = (int) ((g1 + m) * 255);
    Uint8 b = (int) ((b1 + m) * 255);
    return SDL_MapRGB(pformat, r, g, b);
}

int animate(SDL_Window* pwindow, SDL_Surface* psurface, double time) {
    SDL_PixelFormat* pformat = psurface -> format;
    SDL_Rect delete_rect = (SDL_Rect) {0, 0, WIDTH, HEIGHT};
    SDL_FillRect(psurface, &delete_rect, BLACK);
    double h = 240;
    double s = 1.0;
    double l = 0.5;
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            SDL_Rect rect = (SDL_Rect) {x, y, 1, 1};

            double h_x = pow(sin(2 * M_PI / 2 * (double) x / (double) WIDTH + time), 2);
            double h_y = pow(cos(2 * M_PI / 2 * (double) y / (double) WIDTH + time), 2);
            h = fabs(360 * h_x * h_y);

            Uint32 rgb = rgb_from_hsl(pformat, h, s, l);
            SDL_FillRect(psurface, &rect, rgb); 
        }
    }  
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* pwindow = SDL_CreateWindow("Rainbow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    int game_is_still_running = 1;
    double time;
    while (game_is_still_running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                game_is_still_running = 0;
            }
        } 
        time += 0.01;
        animate(pwindow, psurface, time);
        SDL_UpdateWindowSurface(pwindow);

        SDL_Delay(1);
    }
}