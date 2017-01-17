MorseStatus
===========

The MorseStatus library is a handy class that blinks an LED
for you. It blinks repeatedly in a pattern defined by the
Morse Code for a character that you specify. That character,
and the associated Morse pattern, can indicate a status
in your program.

Usage
-----

    #include <MorseStatus.h>

    MorseStatus myLED(13);

    void setup() {
        myLED.begin();
        myLED.setStatus('L');
    }

    void loop() {
        myLED.run();
    }

Constructor
-----------

The constructor takes either one or two parameters. The first,
and required, parameter is the pin number to blink. The second
optional parameter indicates if the LED is active LOW or active
HIGH (most are active HIGH).  A `true` indicates the LED is
active LOW:

    // Active HIGH (normal) LED on pin 13:
    MorseStatus myLED(13);
    // or
    MorseStatus myLED(13, false);

    // Active LOW (inverted) LED on pin 4:
    MorseStatus myLED(4, true);

Status Codes
------------

The library understands the status codes 0-9 and A-Z as
ASCII characters. 0-9 can also be used as integers.

    myLED.setStatus(3);
    // ... is the same as:
    myLED.setStatus('3');

It treats upper- and lower-case characters the same.

Running
-------

The library is completely asynchronous and non-blocking. To
do the actual blinking the `.run()` method has to be called
at frequent intervals within your main loop. Any blocking
routines within your loop will interfere with the blinking
and could upset the rhythm.

It is safe to call the `.run()` method from a timer interrupt
for fully asynchronous operation.
