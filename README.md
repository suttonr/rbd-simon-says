# rbd-simon-says

<img width="150px" align="right" src="doc/img/shield-bench.jpg?raw=true" /> To celebrate the 100th birthday of Ralph H. Baer we created an Arduino shield which enables learning basic electronics and coding though games.  Ralph H. Baer along with Howard J. Morrison invented the popular [Simon Game](https://en.wikipedia.org/wiki/Simon_(game)), the components on this shield allow someone to create similar style of game as well as come up with their own.

<br/>

This repo is a library intended to obfuscate some more advanced concepts like debouncing, setup routines, etc to promote accessibility of the subject.

[Video of original game being played](https://photos.app.goo.gl/dYGP8RQ6wSfXUUKX9)

---
# Installation

* [Download rbdWorkshop.zip](https://github.com/suttonr/rbd-simon-says/raw/main/rbdWorkshop.zip) from this repo.

<img width="300px" align="right" src="doc/img/gh-download.png?raw=true" /> 
<br clear="right"/>

## [Option 1] Arduino Cloud ( Required for Chromebooks )
Arduino Cloud is the best option for Chromebooks and is a quick way to get started on computer which has the chrome browser. Start with your Arduino *NOT* plugged in. If you prefer to install the traditional Arduino IDE proceed to the next section.
* Goto https://create.arduino.cc/editor in Chrome ( other browsers will not work properly )
* Create or link an account
* <img width="400px" align="right" src="doc/img/arduino-helper-install.png?raw=true" /><span clear="right"/> The first time you will be prompted to install a plugin which allows the page to access the USB port the Arduino board will be pluged into. Click 'Install' and follow installation specific to your OS.   For Chromebooks you will be taken to install a chrome extension.

* Once you complete the plugin install return to then [editor](https://create.arduino.cc/editor)
* Plug in your Arduino to a USB port
* <img width="400px" align="right" src="doc/img/arduino-cloud-selectboard.png?raw=true" /> Select the '...' and you should see your board, select it.<br clear="right"/> 
* <img width="400px" align="right" src="doc/img/arduino-cloud-lib-install.png?raw=true" /> Install the library by 
  * Select Library
  * Click Import 
  * Select the [rbdWorkshop.zip](https://github.com/suttonr/rbd-simon-says/archive/refs/heads/main.zip) file you downloaded earlier <br clear="right"/>

## [Option 2] Install Arduino to your computer
( If you already setup Arduino Cloud you can skip this )
* If you do not have the Arduino IDE installed, follow instructions here to install it. https://www.arduino.cc/en/software

* Install the library to Arduino

<img width="250px" align="right" src="doc/img/arduino-install.png?raw=true" /> 
<br clear="right"/>

# Hardware
<img width="150px" align="right" src="doc/img/shield.jpg?raw=true" /> 
Simple breakout of 4 LEDs, 4 switches, and a buzzer. The library assumes things are connected as shown.

* LEDs: A0,A1,A2,A3
* Switches: 4,5,6,7
* Buzzer: 12

<br clear="right"/>

<img width="400px" src="doc/img/shield-schematic.png?raw=true" /> 

# Program Board
<img width="400px" align="right" src="doc/img/arduino-cloud-examples.png?raw=true" />  The library has a number of examples to explore the shield.  You can find these under the `Examples` menu ( File -> Examples -> rbd-simon-says-main ) in the Arduino IDE. In Arduino Cloud this can be found in 'Libraries' -> 'Custom' -> 'RBDWORKSHOP' <br clear="right"/>

To install an example once open select the upload button in the Arduino IDE

<img width="300px"
     src="doc/img/arduino-upload.png?raw=true" />

Once the upload is complete, there will be a message at the bottom.  If you get an error make sure your board and port ate setup in the `Tools` menu.

<img width="300px"
     src="doc/img/arduino-upload-done.png?raw=true" />

---
# Arduino Basics
Bellow is a small example program. Arduino programs are made up of at least two sections, a setup function and a loop function. This program also has a reference to a library for the shield we are using.

```
#include "rbd-simon-says.h"

void setup () {
		digitalWrite(LED_PINS[0], LOW);
		digitalWrite(LED_PINS[1], LOW);
		digitalWrite(LED_PINS[2], LOW);
		digitalWrite(LED_PINS[3], LOW);
}

void loop () {
    digitalWrite(LED_PINS[0], HIGH);
    delay(1000);
    digitalWrite(LED_PINS[0], LOW);
}
```

## rbd-simon-says library

```
#include "rbd-simon-says.h"
```
A library is a collection of code which is written in other files from this program.  Many Arduino shields include libraries to make using them easier.  In this case the shield allows us to reference the lights on the shield as 0, 1, 2, and 3 rather than having to know which Arduino pins they are attached to. All of the examples below will use this library.


## setup() function
```
void setup () {
		digitalWrite(LED_PINS[0], LOW);
		digitalWrite(LED_PINS[1], LOW);
		digitalWrite(LED_PINS[2], LOW);
		digitalWrite(LED_PINS[3], LOW);
}
```

What is put into the setup function is run once when the Arduino board is turned on.  This section is used to set the starting conditions, for example we make sure all the lights are turned off to start.  The `digitalWrite` command is an Arduino command which sets a pin to either a high voltage or a low voltage.  In the setup function here we are setting all the LED pins to a low voltage which turns them off.
> **How Computers Count**: When counting things computers tend to start at 0, so first LED is `LED_PINS[0]`; the second LED is `LED_PINS[1]` and so on.

## loop() function
```
void loop () {
    digitalWrite(LED_PINS[0], HIGH);
    delay(1000);
    digitalWrite(LED_PINS[0], LOW);
}
```
The loop function continually runs while the board is powered on.  Statements in the loop function execute from top to bottom, once the last statement is run it restarts from the top.  In this example we are again using the `digitalWrite` command, this time we set the first LED to a high voltage.  We then wait for 1 second and then turn the light back off.  This will continue to repeat blinking the first LED.   
> **Time**: You may notice that to wait for 1 second we used the command `delay(1000)`. The Arduino board runs about 16 million commands every second, there are many times when programs need to pause for very short periods of time.   For this reason the `delay` command user milliseconds what are 1000 times smaller than a second so to wait for a second we need to wait for 1000 milliseconds. 

# Examples

## AHelloWorld
Examples which chases lights around the board
### Program Details
#### Set the starting pin
```
int pin=0;
```
This sets which LED should light first.

#### setup()
```
void setup () {
    Serial.begin(9600);
    setupshield();
    delay(1000);
}
```
The `setupshield();` is included in the shield library and initializes the shield for use when the board starts up. We'll see this in all of the examples. `delay(1000)` pauses for 1 second before starting to run the loop

#### loop()
```
void loop () {
    if ( pin > 3 ) {
        pin=0;
    }
    digitalWrite(LED_PINS[pin], HIGH);
    delay(1000);
    digitalWrite(LED_PINS[pin], LOW);
    pin = pin + 1;
}
```
The loop function executes over and over while the board is on.  This should look similar to the example we saw above in the basics section. The difference here is that we want to light each LED in turn.  To do this we add 1 to the pin number after we finish blinking the light with the statement `pin = pin + 1;`. If we just continually added 1 though we quickly would run out of LEDs to light, we only have 4. This is why we set the pin back to 0 if it gets bigger than 3.

##### if statement
```
    if ( pin > 3 ) {
        pin=0;
    }
```
An `if` statement allows the program to do something only *if* a condition is met. These conditions are called booleans, which just means that they are either true or false. In this case we would like to set the pin to 0 only if the pin is greater than the number of LEDs we have. (Remember how computers count from above?). This is written `pin > 3`.  The `>` symbol means 'greater than', so reading left to right the statement is, *`pin` greater than 3*.  If `pin` is 0,1,2,3 this will be false; and if `pin` is 4 or higher this will be true.

###### Boolean Statements
Some other common boolean operators in addition to `>` are:

* `<`  : Less than - Opposite of greater than
* `<=` : Less than or equal - Is less than or equal
* `>=` : Greater than or equal - Is greater than or equal
* `==` : Equals - Two things have the same exact value
* `!`  : Not  - Reverses a condition; is something would normally be true make it false

### Things to try
* Can you make the lights go faster?
* Can you make the lights go in the reverse direction?
* Can you make all the lights flash at the same time?

## BShieldIntro
This example lights up the corresponding light and plays a note when a switch is pressed.
### Program Details
#### loop()
```
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
```
##### digitalRead command
In the first example we just lit the LEDs, here since we are lighting the light next to the switch which is pressed we need to find out which switch is pressed. This is done with the `digitalRead` command.  This command is provided by Arduino and is similar to the `digitalWrite` we use to light the LEDs.   Here we get the status of a switch, then use the `if` statement from the previous example to decide if it's pressed or not.  When a switch is pressed the switch connects a pin of the Arduino to ground, this shows up as a LOW signal to the `digitalRead` command.  

##### for statement
The `for` statement is typically used to run a set of commands for a number of times.  Here we have some commands we want to run for each switch and LED. We could replace this `for` section with separate commands for each pin similar to whats in the *Arduino Basics* section from earlier.  This section is reading each of the switches on the shield, lighting up the corresponding LED, and playing a tone on the speaker.

##### debounce command
When reading physical switches, no matter how quickly you press the switch there is always a very small period of time when the metal contacts in the switch fluctuate between connected and dis connected.  To prevent this from registering more presses than expected we prevent the state from changing very rapidly.  This is called debouncing the input. For simplicity here there is a debounce command provided by the shield library which we are using here.

##### playtone command
In the shield's library there are two commands to play tones.  `playtone` plays the note which corresponds to a specific LED in the original Simon game. There is another command which is just `tone` that we will use in the next example which allows you to play any musical note from the speaker.

### Things to try
* Can you make the tone only play when the red switch is pressed?
* Can you make the light next to the pressed key light?
* (Advanced) Can you play a song instead of a single note?

## CLetsPlay
Here we start to play a game resembling simon says.  After the initiation, a two light pattern will show. If the pattern is successfully entered an additional light will be added.  This continues until the incorrect pattern is entered. This is a much more complicated program however uses just the same commands and statements from the previous examples.  

The one new thing in this example is that we are creating our own commands for things which are used regularly, these are called functions. Programmers do this to make programs easier to understand where things happen and where to make changes or look for errors.

```
void increment_pattern(){
    pattern_loc = 0;
    if (PATTERN_LENGTH<MAX_PATTERN){
        PATTERN[PATTERN_LENGTH] = random(4);
        PATTERN_LENGTH += 1;
    }
    for (int i=0;i<PATTERN_LENGTH;i++){
        flashled(PATTERN[i]);
        playtone(PATTERN[i]);
        delay(PATTERN_DELAY);
    }
}
```

This is one of the functions we have in this example. This is just a group of commands which are run when called.  The first line defines what the function returns, in this case it doesn't return anything which is called `void`. `increment_pattern` is the name of the function, if this function took parameters they would go into `()` in this case there are none.  This function adds a random new LED position to the end of the pattern, then lights the pattern to the player.

```
void win(){
    tone(12,NOTE_D5 ,200);
    flashallled(200);
    delay(100);
    tone(12,NOTE_D5,200);
    flashallled(200);
    tone(12,NOTE_D5 ,200);
    flashallled(200);
    tone(12,NOTE_A5 ,300);
    delay(2000);

    increment_pattern();
}
```

The `increment_pattern` function which was defined above is called each time the player enters the pattern correctly.  This happens in the `win()` function. 

```
void loop () {
    for (int pin=0;pin<4;pin++){
        int swval = digitalRead(SWITCH_PINS[pin]);
        if ( swval == LOW && debounce(pin,true) ){           
            digitalWrite(LED_PINS[pin], HIGH);
            playtone(pin);
            if ( pattern_loc == PATTERN_LENGTH-1 && pin == PATTERN[pattern_loc] ){
                win();
            } else if ( pattern_loc < PATTERN_LENGTH && pin != PATTERN[pattern_loc] ) {
                lose(PATTERN[pattern_loc]);
                pattern_loc = PATTERN_LENGTH ;
            } else if ( pattern_loc < PATTERN_LENGTH  ) {
                pattern_loc++;
            }
        } else if ( debounce(pin,false) ) {
            digitalWrite(LED_PINS[pin], LOW);
        }
    }
}
```

As we have seen in the other examples most of the work is being done in the loop section.  This is very similar to what we saw the in previous example where we are reading all the switches on each loop.  

What we have added is an `if` statement which is checking if the user has pressed the correct switch.  To do this we keep track of where the player is in the pattern with `pattern_loc`.
  
* If the player presses the correct switch the pin will equal the number in the pattern at the location they are at, this is written as `pin == PATTERN[pattern_loc]`. 
* If the player presses the incorrect switch the pin will not equal where they are in the patter, that is written as `pin != PATTERN[pattern_loc]`. 
* If the player presses a switch and we are at the next to last position and they pressed the correct switch they 'win', that is written as `( pattern_loc == PATTERN_LENGTH-1 && pin == PATTERN[pattern_loc] )` to combine the two conditions we use `&&` to mean that both conditions must be true.

### Things to try
* Can you play different win music?
* Can you make the game start with a 4 light pattern?
* (Advanced) Can you allow the user to generate their own pattern?
