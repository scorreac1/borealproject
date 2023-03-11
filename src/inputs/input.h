#ifndef input_h
#define input_h

#include <Arduino.h>

class Input {
private:
    uint32_t value;
    bool changed;
    virtual uint32_t getValue();
protected:
public:
    uint8_t getColor(uint8_t index);
    void sample();
    uint32_t read();
    bool hasChanged();
};

uint8_t Input::getColor(uint8_t index){
    return this->value >> (24 - (index * 8));
}

bool Input::hasChanged(){
    return this->changed;
}

uint32_t Input::read() {
    this->changed = false;
    return this->value;
}

void Input::sample() {
    uint32_t actual_value = this->getValue();
    if (this->value != actual_value) {
        this->value = actual_value;
        this->changed = true;
    }
}

#endif