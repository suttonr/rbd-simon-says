#include "rbd-simon-says.h"

int pin=0;

void setup () {
    Serial.begin(9600);
    setupshield();
    delay(1000);
}

void loop () {
    if ( pin > 3 ) {
        pin=0;
    }
    digitalWrite(LED_PINS[pin], HIGH);
    delay(1000);
    digitalWrite(LED_PINS[pin], LOW);
    pin = pin + 1;
}
