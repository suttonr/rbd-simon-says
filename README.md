# rbd-simon-says

<img width="200px" align="right" src="doc/img/shield-bench.jpg?raw=true" /> To celebrate the 100th birthday of Ralph H. Baer we created an Arduino shield which enables learning basic electronics and coding though games.  Ralph H. Baer along with Howard J. Morrison invented the popular [Simon Game](https://en.wikipedia.org/wiki/Simon_(game)), the components on this shield allow someone to create similar style of game as well as come up with their own.

<br/>

This repo is a library intended to obfuscate some more advanced concepts like debouncing, setup routines, etc to promote accessability of the subject.

[Video of original game being played](https://photos.app.goo.gl/dYGP8RQ6wSfXUUKX9)

# Installation

* [Download rbdWorkshop.zip](https://github.com/suttonr/rbd-simon-says/raw/main/rbdWorkshop.zip) from this repo.

![download screen shot](doc/img/gh-download.png?raw=true)

## [Option 1] Arduino Cloud ( Required for Chromebooks )
Arduino Cloud is the best option for Chromebooks and is a quick way to get started on computer which has the chrome browser. Start with your Arduino *NOT* plugged in. If you perfer to install the traditional Arduino IDE proceed to the next section.
* Goto https://create.arduino.cc/editor in Chrome ( other browsers will not work properly )
* Create or link an account
* <img width="400px" align="right" src="doc/img/arduino-helper-install.png?raw=true" /><span clear="right"/> The first time you will be prompted to install a plugin which allows the page to access the USB port the Arduino board will be pluged into. Click 'Install' and follow installation specific to your OS.   For Chromebooks you will be taken to install a chrome extension.

* Once you complete the plugin install return to then [editor](https://create.arduino.cc/editor)
* Plug in your Arduino to a USB port
* <img width="400px" align="right" src="doc/img/arduino-cloud-selectboard.png?raw=true" /> Select the '...' and you should see your board, select it.<br clear="right"/> 
* <img width="400px" align="right" src="doc/img/arduino-cloud-lib-install.png?raw=true" /> Install the library by 
  * Select Library
  * Click Import 
  * Select the [rbdWorkshop.zip](https://github.com/suttonr/rbd-simon-says/raw/main/rbdWorkshop.zip) file you downloaded eariler <br clear="right"/>

## [Option 2] Install Arduino to your computer
( If you already setup Arduino Cloud you can skip this )
* If you do not have the Arduino IDE installed, follow instructions here to install it. https://www.arduino.cc/en/software

* Install the library to Arduino
![arduino-install](doc/img/arduino-install.png?raw=true)

# Hardware
<img width="200px" align="right" src="doc/img/shield.jpg?raw=true" /> 
Simple breakout of 4 LEDs, 4 switches, and a buzzer. The library assumes things are connected as shown.

* LEDs: A0,A1,A2,A3
* Switches: 4,5,6,7
* Buzzer: 12

<br clear="right"/>

![shield schematic.png ](doc/img/shield-schematic.png?raw=true)

# Program Board
<img width="400px" align="right" src="doc/img/arduino-cloud-examples.png?raw=true" />  The library has a number of examples to explore the shield.  You can find these under the `Examples` menu ( File -> Examples -> rbd-simon-says-main ) in the Arduino IDE. In Arduino Cloud this can be found in 'Libraries' -> 'Custom' -> 'RBDWORKSHOP' <br clear="right"/>

To install an example once open select the upload button in the Arduino IDE

<img width="400px"
     src="doc/img/arduino-upload.png?raw=true" />

Once the upload is complete, there will be a message at the bottom.  If you get an error make sure your board and port ate setup in the `Tools` menu.

<img width="400px"
     src="doc/img/arduino-upload-done.png?raw=true" />

# Examples

## AHelloWorld
Examples which chases lights around the board
### Things to try
* Can you make the lights go faster?
* Can you make the lights go in the reverse direction?
* Can you make all the lights flash at the same time?

## BShieldIntro
This example lights up the corresponding light and plays a note when a switch is pressed.
### Things to try
* Can you make the tone only play when the red switch is pressed?
* Can you make the light next to the pressed key light?
* (Advanced) Can you play a song instead of a single note?

## CLetsPlay
Here we start to play a game resembling simon says.  After the initiation, a two light pattern will show. If the pattern is successfully entered an additional light will be added.  This continues until the incorrect pattern is entered.

### Things to try
* Can you play different win music?
* Can you make the game start with a 4 light pattern?
* (Advanced) Can you allow the user to generate their own pattern?
