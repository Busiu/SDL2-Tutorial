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

LTexture billyTexture;
LTexture vanTexture;

Uint8 a = 255;

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
                            //Increase alpha on "w"
                            case SDLK_w:{
                                //Cap if over 255
                                if(a + 32 > 255){
                                    a = 255;
                                }
                                //Increment otherwise
                                else{
                                    a += 32;
                                }
                                break;
                            }
                            //Decrease alpha on "s"
                            case SDLK_s:{
                                //Cap if below 0
                                if (a - 32 < 0) {
                                    a = 0;
                                }
                                    //Decreament otherwise
                                else {
                                    a -= 32;
                                }
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

                //Render background (Billy's)
                billyTexture.render(0, 0);

                //Render front (Van's) blended
                vanTexture.setAlpha(a);
                vanTexture.render(0,0);

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}