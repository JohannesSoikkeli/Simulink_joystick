#include <stdio.h>
#include <unistd.h>
#include "SDL2/SDL.h"

static SDL_Joystick *joy = NULL;

int
main(int argc, char *argv[])
{

    // ITIALIZE:
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    // Check for joystick
    if (SDL_NumJoysticks() > 0) {
        // Open joystick
        joy = SDL_JoystickOpen(0);

        if (joy) {
            printf("Opened Joystick 0\n");
            printf("Name: %s\n", SDL_JoystickNameForIndex(0));
            printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
            printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
            printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
        } else {
            printf("Could not open Joystick 0\n");
            return 0;
        }
    }
    SDL_JoystickEventState(SDL_IGNORE);

    // READ VALUES:
    for (int i = 1; i < 100; ++i){
        SDL_JoystickUpdate();
        for (int j = 0; j < SDL_JoystickNumAxes(joy); ++j) {
            int value = (((int) SDL_JoystickGetAxis(joy, j)) + 32768);
            printf("Axes %d: %d ", j, value);
        }
        printf("\n");
        usleep(100000);
    }

    // CLOSE:
    if (SDL_JoystickGetAttached(joy)) {
        SDL_JoystickClose(joy);
    }

    return 1;
}

