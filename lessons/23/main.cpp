//
// Created by Busiu on 26.08.2018.
//

#include "headers/functions.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

LTexture startPromptTexture;
LTexture pausePromptTexture;
LTexture timeTextTexture;
LTimer timer;
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
                    else if(event.type == SDL_KEYDOWN)
                    {
                        //Start/stop
                        if(event.key.keysym.sym == SDLK_s)
                        {
                            if(timer.isStarted())
                            {
                                timer.stop();
                            }
                            else
                            {
                                timer.start();
                            }
                        }
                        //Pause/unpause
                        else if(event.key.keysym.sym == SDLK_p)
                        {
                            if(timer.isPaused())
                            {
                                timer.unpause();
                            }
                            else
                            {
                                timer.pause();
                            }
                        }
                    }
                }

                //Set text to be rendered
                timeText.str("");
                timeText << "Seconds since start time: " << (timer.getTicks() / 1000.f);

                //Render text
                if(!timeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
                {
                    printf("Failed to render time texture!\n");
                }

                //Clear screen
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                //Render textures
                startPromptTexture.render((SCREEN_WIDTH - startPromptTexture.getWidth()) / 2, 0);
                pausePromptTexture.render((SCREEN_WIDTH - pausePromptTexture.getWidth()) / 2, startPromptTexture.getHeight());
                timeTextTexture.render((SCREEN_WIDTH - timeTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - timeTextTexture.getHeight()) / 2);

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}