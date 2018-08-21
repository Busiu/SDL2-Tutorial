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

SDL_Color textColor = {0, 0, 0, 255};
LTexture promptTextTexture;
LTexture timeTextTexture;
TTF_Font* font;
Uint32 startTime = 0;

//In memory text stream
stringstream timeText;

int main(int argc, char** argv)
{

    if(!init())
    {
        printf("Failed to init SDL & IMG!\n");
    }
    else
    {
        if(!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            while(!quit)
            {
                //Handle events in queue
                while (SDL_PollEvent(&event) != 0)
                {
                    //User requests quit
                    if (event.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    //Reset start time on return keypress
                    else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
                    {
                        startTime = SDL_GetTicks();
                    }
                }

                //Set text to be rendered
                timeText.str("");
                timeText << "Milliseconds since start time: " << SDL_GetTicks() - startTime;

                //Render text
                if(!timeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
                {
                    printf("Failed to render time texture!\n");
                }

                //Clear screen
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                //Render textures
                promptTextTexture.render((SCREEN_WIDTH - promptTextTexture.getWidth()) / 2, 0);
                timeTextTexture.render((SCREEN_WIDTH - timeTextTexture.getWidth()) / 2, promptTextTexture.getHeight());

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}