//
// Created by Busiu on 21.08.2018.
//

#include "headers/functions.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

LTexture* currentTexture = nullptr;
LTexture defaultTexture;
LTexture downTexture;
LTexture leftTexture;
LTexture rightTexture;
LTexture upTexture;

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
                }

                //Set texture based on current keystate
                const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
                if(currentKeyStates[SDL_SCANCODE_DOWN]){
                    currentTexture = &downTexture;
                }
                else if(currentKeyStates[SDL_SCANCODE_LEFT]){
                    currentTexture = &leftTexture;
                }
                else if(currentKeyStates[SDL_SCANCODE_RIGHT]){
                    currentTexture = &rightTexture;
                }
                else if(currentKeyStates[SDL_SCANCODE_UP]){
                    currentTexture = &upTexture;
                }
                else{
                    currentTexture = &defaultTexture;
                }

                //Clear screen
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                //Render current texture
                currentTexture->render(0, 0);

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}