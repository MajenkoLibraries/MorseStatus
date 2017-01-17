#ifndef _MORSE_STATUS_H
#define _MORSE_STATUS_H

#include <Arduino.h>

/*! Blink an LED repeatedly depicting a status value using morse code.
 *  Supports status values of 0-9 and A-Z
 */

class MorseStatus {
    private:
        volatile uint8_t _led;
        volatile const __FlashStringHelper *_status;
        volatile uint32_t _ts;
        volatile bool _ledstate;
        bool _actlow;
        volatile bool _on;
        volatile bool _off;
        volatile int8_t _digit;
        
    public:
        MorseStatus(uint8_t led) : _led(led), _actlow(false) {}
        MorseStatus(uint8_t led, bool actlow) : _led(led), _actlow(actlow) {}
        void begin();
        void setStatus(char s);
        void run();
};

#endif
