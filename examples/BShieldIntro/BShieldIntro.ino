#include "rbd-simon-says.h"

void setup () {
    Serial.begin(9600);
    setupshield();
    delay(1000);
}

void loop () {
    for (int pin=0;pin<4;pin++){
        int swval = digitalRead(SWITCH_PINS[pin]);
        if ( swval == LOW && debounce(pin,true) ){           
            digitalWrite(LED_PINS[pin], HIGH);
            playtone(pin);
        } else if ( debounce(pin,false) ) {
            digitalWrite(LED_PINS[pin], LOW);
        }
    }
}