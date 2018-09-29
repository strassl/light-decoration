#pragma once
class SimpleBlinkAction
{
private:
  uint8_t _pin;
  boolean _on;

public:
  SimpleBlinkAction(uint8_t pin)
  {
    this->_pin = pin;
    this->_on = true;
  }

  void operator()()
  {
    digitalWrite(this->_pin, this->_on ? HIGH : LOW);
    this->_on = !this->_on;
  }
};