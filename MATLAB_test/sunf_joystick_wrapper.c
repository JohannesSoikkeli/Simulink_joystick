
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <SDL2/SDL.h>
#include <stdio.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
static SDL_Joystick *joy = NULL;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void sunf_joystick_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
    // ITIALIZE:
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    // Check for joystick
    if (SDL_NumJoysticks() > 0) {
        // Open joystick
        joy = SDL_JoystickOpen(0);

        if (joy) {
            ssPrintf("Opened Joystick 0\n");
            ssPrintf("Name: %s\n", SDL_JoystickNameForIndex(0));
            ssPrintf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
            ssPrintf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
            ssPrintf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
        } else {
            ssWarning("Warning:Joystick","Could not open Joystick 0\n");
        }
    }
    SDL_JoystickEventState(SDL_IGNORE);

    
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void sunf_joystick_Outputs_wrapper(uint32_T *y0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
    SDL_JoystickUpdate();
    for (int j = 0; j < SDL_JoystickNumAxes(joy); ++j) {
        y0[j] = (((int) SDL_JoystickGetAxis(joy, j)) + 32768);
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void sunf_joystick_Terminate_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
    if (SDL_JoystickGetAttached(joy)) {
        SDL_JoystickClose(joy);
    }
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

