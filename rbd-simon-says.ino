#include "rbd-simon-says-shield.h"

#define MAX_PATTERN 100
uint16_t PATTERN_DELAY = 500;

uint8_t pattern[MAX_PATTERN] = {0};
uint8_t pattern_length = 4;
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

    pattern[pattern_length] = random(4);
    pattern_length++;
    pattern_loc = 0;
    show_pattern();
}

void new_game() {
  
    pattern_length = 1;
    pattern_loc = 0;

    // Need to use an unassigned analog input
    randomSeed(analogRead( A5 ));
    
    pattern[0] = random(4);
    
    show_pattern();
}

void show_pattern() {
  for (int i=0; i<pattern_length; i++){
    delay(PATTERN_DELAY);
    flashled(pattern[i]);
    playtone(pattern[i]);
  }
}

void setup () {
    Serial.begin(9600);

    for (int pin=0; pin < pattern_length; pin++){
      pinMode(SWITCH_PINS[pin], INPUT_PULLUP);
      pinMode(LED_PINS[pin], OUTPUT);
    }
    
    new_game();
}


bool button_on = false;
void loop () {
    
    for (int pin=0; pin<4; pin++){
        int swval = digitalRead(SWITCH_PINS[pin]);

        /*
         * If a button is pressed
         *    Light it's light
         *    If it's the correct button
         *       Play it's tone
         *    Else
         *       Play the LOSER tone
         */
        button_on = false;        
        if (swval == LOW && debounce(pin,true) ){           
            digitalWrite(LED_PINS[pin], HIGH);

            // Did user hit the correct button?
            if (pin == pattern[pattern_loc]) {
              tone(12, TONES[pin]);
            }
            else
            { 
              tone(12, NOTE_E2);
            }
        }

        /*
         * If a button is released
         * Unlight it's light
         * Stop playing any tone
         * If it's the correct button
         *   Add another light to the pattern
         *   Play the new pattern
         * Else
         *    Nothing for now... let user keep trying
         */
        if (swval == HIGH && debounce(pin,false) ){
          digitalWrite(LED_PINS[pin], LOW);
          noTone(12);

          // Did the user just finish pressing the correct button
          if (pin == pattern[pattern_loc]) {

            pattern_loc += 1;
            
            // Is this the last button in the pattern
            if (pattern_loc == pattern_length) {
              pattern_loc = 0;
              pattern_length++;
              pattern[pattern_length] = random(4);
              show_pattern();              
            }
              
         }

        }
    }
}
