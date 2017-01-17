#include <MorseStatus.h>

MorseStatus myLED(LED_BUILTIN);

void setup() {
    myLED.begin();
    myLED.setStatus('L');
}

void loop() {
    myLED.run();
}
