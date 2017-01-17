#ifndef _MORSE_STATUS_H
#define _MORSE_STATUS_H

#include <Arduino.h>

/*! Blink an LED repeatedly depicting a status value using morse code.
 *  Supports status values of 0-9 and A-Z
 */

class MorseStatus {
    private:
        uint8_t _led;
        const __FlashStringHelper *_status;
        uint32_t _ts;
        bool _ledstate;
        bool _actlow;
        bool _on;
        bool _off;
        int8_t _digit;
        
    public:
        MorseStatus(uint8_t led) : _led(led), _actlow(false) {}
        MorseStatus(uint8_t led, bool actlow) : _led(led), _actlow(actlow) {}
        void begin();
        void setStatus(char s);
        void run();
};

#endif
