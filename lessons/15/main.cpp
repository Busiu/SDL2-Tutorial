//
// Created by Busiu on 17.08.2018.
//

#include "headers/functions.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

LTexture vanTexture;
double degrees = 0.0;
SDL_RendererFlip flipType = SDL_FLIP_NONE;

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
                    else if(event.type == SDL_KEYDOWN){
                        switch(event.key.keysym.sym){
                            case SDLK_a:{
                                degrees -= 60;
                                break;
                            }

                            case SDLK_d:{
                                degrees += 60;
                                break;
                            }

                            case SDLK_q:{
                                flipType = SDL_FLIP_HORIZONTAL;
                                break;
                            }

                            case SDLK_w:{
                                flipType = SDL_FLIP_NONE;
                                break;
                            }

                            case SDLK_e:{
                                flipType = SDL_FLIP_VERTICAL;
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

                //Render Van
                vanTexture.render((SCREEN_WIDTH - vanTexture.getWidth()) / 2, (SCREEN_HEIGHT - vanTexture.getHeight()) / 2,
                                  nullptr, degrees, nullptr, flipType);

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}