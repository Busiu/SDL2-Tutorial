//
// Created by Busiu on 27.08.2018.
//

#include "headers/functions.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
const int SCREEN_FPS = 60;
const double SCREEN_TICKS_PER_FRAME = 1000.f / SCREEN_FPS;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

LTexture fpsTextTexture;
LTimer fpsTimer;
LTimer capTimer;
SDL_Color textColor = {0, 0, 0, 255};
TTF_Font* font;

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
            int countedFrames = 0;
            fpsTimer.start();
            while(!quit)
            {
                //Start cap timer
                capTimer.start();

                //Handle events in queue
                while (SDL_PollEvent(&event) != 0)
                {
                    //User requests quit
                    if (event.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }

                //Calculate text to be rendered
                float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);

                //Set text to be rendered
                timeText.str("");
                timeText << "Average Frames Per Second (With Cap): " << avgFPS;

                //Render text
                if(!fpsTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
                {
                    printf("Failed to render FPS texture!\n");
                }

                //Clear screen
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                //Render textures
                fpsTextTexture.render((SCREEN_WIDTH - fpsTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - fpsTextTexture.getHeight()) / 2);

                //Update screen
                SDL_RenderPresent(renderer);
                countedFrames++;

                //If frame finished earlier
                int frameTicks = capTimer.getTicks();
                if(frameTicks < SCREEN_TICKS_PER_FRAME)
                {
                    //Wait remaining time
                    SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
                }
            }
        }
    }

    close();

    return 0;
}