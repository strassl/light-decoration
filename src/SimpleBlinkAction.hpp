#pragma once
class SimpleBlinkAction
{
private:
  int _pin;
  boolean _on;

public:
  SimpleBlinkAction(int pin)
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