/**
 * This is program for testing Bluetooth connection in EV3RT C++ API.
 *
 * Author: Jaroslav Páral (jarekparal)
 */

#include "ev3cxx.h"
#include "app.h"

void main_task(intptr_t unused) {
    ev3cxx::Bluetooth bt{true};

    while(true) {
        while(!bt.isConnected()) {}

        format(bt, "\nHello World\nWaiting for data.\n");

        int ch;
        while(bt.isConnected()) {
            if((ch = bt.readChar()) > 0)
                bt.write(ch);
        }
    }
}