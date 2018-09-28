#pragma once
template <typename Fn>
class DelayedUpdater
{
private:
  unsigned long _delay;
  unsigned long _lastUpdateMillis;
  Fn _updateFn;

public:
  DelayedUpdater(unsigned long delay, Fn updateFn) : _delay(delay), _lastUpdateMillis(0), _updateFn(updateFn)
  {
  }

  void update(unsigned long currentTimeMillis)
  {
    unsigned long delta = currentTimeMillis - this->_lastUpdateMillis;
    if (delta > this->_delay)
    {
      this->_updateFn();
      this->_lastUpdateMillis = currentTimeMillis;
    }
  }
};

template <typename Fn>
DelayedUpdater<Fn> make_delayed_updater(unsigned long delay, Fn updateFn)
{
  return DelayedUpdater<Fn>(delay, updateFn);
}