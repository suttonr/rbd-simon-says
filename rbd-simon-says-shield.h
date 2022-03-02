#include "Arduino.h"
#include "pitches.h"
#include "stdint.h"

#define NUM_PINS 4
#define DEBOUNCE_TIME 100

extern uint8_t SWITCH_PINS[];
extern uint8_t LED_PINS[];
extern int TONES[];
extern bool buttonStates[];
extern unsigned long buttonStateChange[];

void flashled ( int pin, int time=200 );
void flashallled ( int time=200 );
void playtone( int pin, int time=200 );
bool debounce( int pin, bool state );
