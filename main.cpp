#include <Arduino.h>
#include "inputs/slide_input.h"
#include <Adafruit_NeoPixel.h>


SlideInput slide = SlideInput(A0);
long sample_timer = millis();
long sample_time = 500;
uint8_t n_pixels = 12;

Adafruit_NeoPixel pixels(n_pixels, 4, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(115200);
  slide.init();
  pixels.begin();
  pixels.clear();
  pixels.show();
}

void loop() {
  if((millis() - sample_timer) > sample_time){
    sample_timer = millis();
    slide.sample();
    if (slide.hasChanged()) {
      uint32_t color_value = slide.read();
      Serial.println(color_value);
      pixels.fill(color_value);
      pixels.show();
    }
  }
}