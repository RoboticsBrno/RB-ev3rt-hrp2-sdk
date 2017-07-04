/**
 * Test motor PID on LEGO and EV3RT.
 *
 * Motivation: https://vimeo.com/222160106
 *
 * Author: Jaroslav Páral (jarekparal)
 */

#include <cstdlib>

#include "ev3api.h"
#include "ev3cxx.h"
#include "app.h"

using ev3cxx::display;

void main_task(intptr_t unused) {
    ev3cxx::Motor motorRef(ev3cxx::MotorPort::C);
    ev3cxx::Motor motorControl(ev3cxx::MotorPort::D);

    int positionDiff = 0;
    int positionLast = 0;
    int position = 0;

    while(true) {
        position = motorRef.degrees();
        positionDiff = positionLast - position;
        positionLast = position;
        
        motorControl.onForDegrees(50, -positionDiff);

        ev3cxx::display.format("%3  %3  %3\n") 
            % position % positionDiff % positionLast;
        ev3cxx::delayMs(5);
    }
}
