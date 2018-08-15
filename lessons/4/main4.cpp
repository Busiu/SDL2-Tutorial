//
// Created by Busiu on 23.07.2018.
//

#include "../../headers/enums.h"
#include "../headers/4/functions4.h"

//Global variables
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;
SDL_Surface* currentSurface = nullptr;
SDL_Surface* xOpuszczamySurface = nullptr;
SDL_Surface* keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Event event;

int main(int argc, char** argv){

    if(!init()){
        printf("Failed to init SDL!\n");
    }
    else{
        if(!loadMedia()){
            printf("Failed to load media!\n");
        }
        else{
            //Set initial image
            currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
            updateWindow(currentSurface);

            //Main loop
            while(!quit){
                //Event loop
                while(SDL_PollEvent(&event) != 0){
                    //Request of closing
                    if(event.type == SDL_QUIT){
                        quit = true;
                    }
                        //User presses a key
                    else if(event.type = SDL_KEYDOWN){
                        //Select surfaces based on key press
                        switch(event.key.keysym.sym){
                            case SDLK_UP:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_UP];
                                break;

                            case SDLK_DOWN:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                                break;

                            case SDLK_LEFT:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                                break;

                            case SDLK_RIGHT:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                                break;

                            default:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                                break;

                        }
                    }
                }

                updateWindow(currentSurface);
            }
        }
    }

    updateWindow(xOpuszczamySurface);
    SDL_Delay(500);

    close();

    return 0;
}