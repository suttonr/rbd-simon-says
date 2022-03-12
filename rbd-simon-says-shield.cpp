#include "rbd-simon-says-shield.h"

uint8_t SWITCH_PINS[] = { A0, A1, A2, A3 };
uint8_t LED_PINS[] = { 4, 5, 6, 7 };
int TONES[] = { NOTE_E4, NOTE_CS4, NOTE_A4, NOTE_E3 };

bool buttonStates[] = { false,false,false,false };
unsigned long buttonStateChange[] = { 0,0,0,0 };

void flashled ( int pin, int time ) {
    if ( pin < 4 && pin >= 0 ) {
        digitalWrite(LED_PINS[pin], HIGH);
        delay(time);
        digitalWrite(LED_PINS[pin], LOW);
    }
}

void flashallled ( int time ) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    delay(time);
    digitalWrite(LED_PINS[0], LOW);
    digitalWrite(LED_PINS[1], LOW);
    digitalWrite(LED_PINS[2], LOW);
    digitalWrite(LED_PINS[3], LOW);
}


void playtone ( int pin, int time ){
    if ( pin < 4 && pin >= 0 ) {
        tone(12, TONES[pin], time);
    }
}


bool debounce(int pin, bool state){
    if ( state != buttonStates[pin] &&
        ((millis() - buttonStateChange[pin]) > DEBOUNCE_TIME) ) {
            buttonStates[pin] = state;
            buttonStateChange[pin] = millis();
            return true;
    } 
    return false;
}
