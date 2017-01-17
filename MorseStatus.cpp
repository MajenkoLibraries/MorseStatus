#include <MorseStatus.h>

static const uint32_t interWordDelay = 1000;
static const uint32_t interDigitDelay = 250;
static const uint32_t dotDelay = 250;
static const uint32_t dashDelay = 750;

void MorseStatus::begin() {
    pinMode(_led, OUTPUT);
    _off = _actlow ? HIGH : LOW;
    _on = _actlow ? LOW : HIGH;
    setStatus(-1); // -1 = do not blink
}

void MorseStatus::setStatus(char s) {
    switch(s) {
        case -1: _status = F(""); break;
        case '0':
        case 0: _status = F("-----"); break;
        case '1':
        case 1: _status = F(".----"); break;
        case '2':
        case 2: _status = F("..---"); break;
        case '3':
        case 3: _status = F("...--"); break;
        case '4':
        case 4: _status = F("....-"); break;
        case '5':
        case 5: _status = F("....."); break;
        case '6':
        case 6: _status = F("-...."); break;
        case '7':
        case 7: _status = F("--..."); break;
        case '8':
        case 8: _status = F("---.."); break;
        case '9':
        case 9: _status = F("----."); break;

        case 'a':
        case 'A': _status = F(".-"); break;

        case 'b':
        case 'B': _status = F("-..."); break;

        case 'c':
        case 'C': _status = F("-.-."); break;

        case 'd':
        case 'D': _status = F("-.."); break;
   
        case 'e':
        case 'E': _status = F("."); break;

        case 'f':
        case 'F': _status = F("..-."); break;

        case 'g':
        case 'G': _status = F("--."); break;

        case 'h':
        case 'H': _status = F("...."); break;

        case 'i':
        case 'I': _status = F(".."); break;

        case 'j':
        case 'J': _status = F(".---"); break;

        case 'k':
        case 'K': _status = F("-.-"); break;

        case 'l':
        case 'L': _status = F(".-.."); break;

        case 'm':
        case 'M': _status = F("--"); break;

        case 'n':
        case 'N': _status = F("-."); break;

        case 'o':
        case 'O': _status = F("---"); break;

        case 'p':
        case 'P': _status = F(".--."); break;

        case 'q':
        case 'Q': _status = F("--.-"); break;

        case 'r':
        case 'R': _status = F(".-."); break;

        case 's':
        case 'S': _status = F("..."); break;

        case 't':
        case 'T': _status = F("-"); break;

        case 'u':
        case 'U': _status = F("..-"); break;

        case 'v':
        case 'V': _status = F("...-"); break;

        case 'w':
        case 'W': _status = F(".--"); break;

        case 'x':
        case 'X': _status = F("-..-"); break;

        case 'y':
        case 'Y': _status = F("-.--"); break;

        case 'z':
        case 'Z': _status = F("--.."); break;

        default: _status = F(""); break;

    }

    digitalWrite(_led, _off);
    _ts = millis();
    _digit = -1; // Inter-word delay
    _ledstate = false;
}

void MorseStatus::run() {
    uint32_t whatDelay = 0;
    if (_digit == -1) { // We are in the interword delay
        whatDelay = interWordDelay;
    } else if (_ledstate == false) { // LED is off between digits
        whatDelay = interDigitDelay;
    } else if (pgm_read_byte_near(_status + _digit) == '-') {
        whatDelay = dashDelay;
    } else {
        whatDelay = dotDelay;
    }

    if (millis() - _ts >= whatDelay) {
        _ts = millis();
        if (_ledstate == false) {
            _digit++;
            if (_digit >= strlen_P((const char *)_status)) {
                _digit = -1;
                digitalWrite(_led, _off);
            } else {
                digitalWrite(_led, _on);
                _ledstate = true;
            }
        } else {
            digitalWrite(_led, _off);
            _ledstate = false;
        }
    }
}
