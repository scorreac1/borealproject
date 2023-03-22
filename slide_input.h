#ifndef slide_input_h
#define slide_input_h 
#include "input.h"

class SlideInput: public Input {
    private:
        uint8_t pin;
        uint32_t getValue();
    public:
    void init();
    SlideInput(uint8_t pin):Input() {
        this->pin = pin;
    };
};

uint32_t SlideInput::getValue(){
    uint16_t value = analogRead(this->pin);
    return map(value, 0, 1023, 0, 0x00FFFFFF);
}

void SlideInput::init(){
    pinMode(this->pin, INPUT);
}

#endif