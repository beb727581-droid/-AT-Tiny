// TinyLED.cpp
#include "TinyLED.h"

// --- Реализация конструктора ---
TinyLED::TinyLED(uint8_t pin) {
  _pin = pin;
}

// --- Реализация функции begin() ---
void TinyLED::begin() {
  pinMode(_pin, OUTPUT);
  off(); // По умолчанию выключаем светодиод при старте
}

// --- Реализация функции on() ---
void TinyLED::on() {
  digitalWrite(_pin, HIGH);
  _state = true;
}

// --- Реализация функции off() ---
void TinyLED::off() {
  digitalWrite(_pin, LOW);
  _state = false;
}

// --- Реализация функции toggle() ---
void TinyLED::toggle() {
  if (_state) {
    off();
  } else {
    on();
  }
}

// --- Реализация функции blink() ---
void TinyLED::blink(int count, int duration) {
  for(int i = 0; i < count; i++) {
    on();
    delay(duration);
    off();
    delay(duration);
  }
}

// --- Реализация функции fadeInOut() ---
void TinyLED::fadeInOut(int totalDuration) {
  // Плавное разгорание (0 -> 255)
  for(int i = 0; i <= 255; i++) {
    analogWrite(_pin, i);
    delay(totalDuration / 510); // totalDuration на весь цикл (вверх и вниз)
  }
  
  // Плавное затухание (255 -> 0)
  for(int i = 255; i >= 0; i--) {
    analogWrite(_pin, i);
    delay(totalDuration / 510);
  }
}