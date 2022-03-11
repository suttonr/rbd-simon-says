#include "rbd-simon-says-shield.h"

#define MAX_PATTERN 4

uint8_t PATTERN[MAX_PATTERN] = {0};
uint8_t PATTERN_LENGTH = MAX_PATTERN;
uint16_t PATTERN_DELAY = 1000;

uint8_t pattern_loc = 0;

void lose(uint8_t correct_led){
    tone(12,NOTE_D2 ,100);
    flashled(correct_led,100);
    delay(100);
    tone(12,NOTE_CS2,100);
    flashled(correct_led,100);
    delay(100);
    tone(12,NOTE_B1 ,500);
    flashled(correct_led,100);
    delay(200);
    flashallled(1000);
    delay(1000);
    new_game();
}

void win(){
    tone(12,NOTE_D5 ,200);
    flashallled(200);
    delay(100);
    tone(12,NOTE_D5,200);
    flashallled(200);
    tone(12,NOTE_D5 ,200);
    flashallled(200);
    tone(12,NOTE_A5 ,300);
    delay(1000);
    new_game();
}

void new_game() {
    pattern_loc = 0;
    randomSeed(analogRead( A5 ));
    for (int pin=0;pin<4;pin++){
        pinMode(SWITCH_PINS[pin], INPUT_PULLUP);
        pinMode(LED_PINS[pin], OUTPUT);
        flashled(pin);
        playtone(pin);
    }
    delay(1000);
    for (int i=0;i<MAX_PATTERN;i++){
        PATTERN[i] = random(4);
        flashled(PATTERN[i]);
        playtone(PATTERN[i]);
        delay(PATTERN_DELAY);
    }
 
}
void setup () {
    Serial.begin(9600);
    new_game();
}

void loop () {
    for (int pin=0;pin<4;pin++){
        int swval = digitalRead(SWITCH_PINS[pin]);
        if ( swval == LOW && debounce(pin,true) ){           
            digitalWrite(LED_PINS[pin], HIGH);
            playtone(pin);
            if ( pattern_loc == MAX_PATTERN-1 && pin == PATTERN[pattern_loc] ){
                win();
            }
            else if ( pattern_loc < MAX_PATTERN && pin != PATTERN[pattern_loc] ) {
                lose(PATTERN[pattern_loc]);
            }
            else if ( pattern_loc < MAX_PATTERN ) {
                pattern_loc++;
            }
        } else if ( debounce(pin,false) ) {
            digitalWrite(LED_PINS[pin], LOW);
        }
    }
}
