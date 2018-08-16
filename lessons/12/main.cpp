//
// Created by Busiu on 16.08.2018.
//

#include "headers/functions.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

LTexture gachiTexture;

Uint8 r = 255;
Uint8 g = 255;
Uint8 b = 255;

int main(int argc, char** argv){

    if(!init()){
        printf("Failed to init SDL & IMG!\n");
    }
    else{
        if(!loadMedia()){
            printf("Failed to load media!\n");
        }
        else{
            while(!quit) {
                //Handle events in queue
                while (SDL_PollEvent(&event) != 0) {
                    //User requests quit
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    //On keypress change rgb values
                    else if(event.type == SDL_KEYDOWN){
                        switch(event.key.keysym.sym){
                            //Increase red
                            case SDLK_q:{
                                r += 32;
                                break;
                            }
                            //Increase green
                            case SDLK_w:{
                                g += 32;
                                break;
                            }
                            //Increase blue
                            case SDLK_e:{
                                b += 32;
                                break;
                            }
                            //Decrease red
                            case SDLK_a:{
                                r -= 32;
                                break;
                            }
                            //Decrease green
                            case SDLK_s:{
                                g -= 32;
                                break;
                            }
                            //Decrease blue
                            case SDLK_d:{
                                b -= 32;
                                break;
                            }

                            default:{
                                break;
                            }
                        }
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                //Modulate and render picture
                gachiTexture.setColor(r, g, b);
                gachiTexture.render(0, 0);

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}