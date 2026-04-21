// TinyLED.h
#ifndef TinyLED_h
#define TinyLED_h

#include "Arduino.h"

class TinyLED {
  public:
    // 1. Конструктор. При создании объекта указываем пин.
    TinyLED(uint8_t pin);

    // 2. Инициализация (аналог pinMode). Нужно вызывать в setup().
    void begin();

    // 3. Основные функции управления:
    void on();           // Включить
    void off();          // Выключить
    void toggle();       // Переключить состояние (вкл <-> выкл)
    
    // 4. Эффекты:
    void blink(int count, int duration); // Мигнуть count раз с задержкой duration (в мс)
    void fadeInOut(int duration);         // Плавное разгорание и затухание (ШИМ)

  private:
    uint8_t _pin;      // Номер пина, к которому подключен светодиод
    bool _state;       // Текущее состояние (true = вкл, false = выкл)
};

#endif