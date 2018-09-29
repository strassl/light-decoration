#include "FastLED.h"
#include "DelayedUpdater.hpp"
#include "SimpleBlinkAction.hpp"
#include "MoveAction.hpp"
#include "RainbowMoveAction.hpp"
#include "RainbowCurtainAction.hpp"

constexpr int Rows = 2;
constexpr int Columns = 12;
constexpr int NumLeds = Rows * Columns;
constexpr int DataPin = 2;

CRGB leds[NumLeds];

static auto ledBlinker = make_delayed_updater(1000, SimpleBlinkAction(LED_BUILTIN));
static auto pixelMover = make_delayed_updater(66, MoveAction<NumLeds>(leds));
static auto rainbowPixelMover = make_delayed_updater(66, RainbowMoveAction<NumLeds>(leds));
static auto rainbowCurtainEffect = make_delayed_updater(333, RainbowCurtainAction<Rows, Columns>(leds));

void setup()
{
  FastLED.addLeds<WS2812B, DataPin>(leds, NumLeds);
}

void loop()
{
  unsigned long currentMillis = millis();

  ledBlinker.update(currentMillis);
  rainbowCurtainEffect.update(currentMillis);
}