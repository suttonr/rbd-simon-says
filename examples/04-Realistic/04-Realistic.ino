#include "rbd-simon-says.h"

#define MAX_PATTERN 100

uint8_t pattern[MAX_PATTERN] = {0};
uint8_t pattern_length = 4;
uint8_t pattern_loc = 0;
uint16_t pattern_delay = 500;

void new_game() {

  pattern_length = 1;
  pattern_loc = 0;
  pattern_delay = 500;

  pattern[0] = random(4);

  show_pattern();
}

void show_pattern() {
  for (int i = 0; i < pattern_length; i++) {
    delay(pattern_delay);
    flashled(pattern[i]);
    playtone(pattern[i]);
  }
}

void setup () {
  Serial.begin(9600);

  // Setup the buttons and LEDs on the arduino
  for (int pin = 0; pin < pattern_length; pin++) {
    pinMode(SWITCH_PINS[pin], INPUT_PULLUP);
    pinMode(LED_PINS[pin], OUTPUT);
  }

  // Need to use an unassigned analog input
  randomSeed(analogRead( A5 ));

  new_game();
}

/*
 * Main program loop. Do what's in here forever
 */
void loop () {

  // Check the condition of all 4 buttons
  for (int pin = 0; pin < 4; pin++) {
    int swval = digitalRead(SWITCH_PINS[pin]);

    /*
       If a button is pressed down (but not released yet)
          Light it's light
          If it's the correct button
             Play it's tone
          Else
             Play the LOSER tone
    */
    if (swval == LOW && debounce(pin, true) ) {
      digitalWrite(LED_PINS[pin], HIGH);

      if (pin == pattern[pattern_loc]) { // Correct pin?
        tone(12, TONES[pin]);
      }
      else
      {
        tone(12, NOTE_E2);
        delay(1000); // play fail tone for at least 1 second - full shame
      }
    }

    /*
       If a button is released
       Unlight it's light
       Stop playing any tone
       If it's the correct button
         Add another light to the pattern
         Play the new pattern
       Else
         Start a new game
    */
    if (swval == HIGH && debounce(pin, false) ) {
      digitalWrite(LED_PINS[pin], LOW);
      noTone(12);

      // Did the user just finish pressing the correct button
      if (pin == pattern[pattern_loc]) {

        pattern_loc += 1;

        if (pattern_loc == pattern_length) { // Pattern complete?
          pattern_loc = 0;
          pattern_length++;
          pattern[pattern_length] = random(4);

          if (pattern_length == 5) // if on the 5th location, speed things up
          {
            pattern_delay = 200;
          }
          
          show_pattern();
        }
      } else { // User just released the wrong button
        new_game();
      }
    }
  }
}
