#include "FastLED.h"
#include "DelayedUpdater.hpp"
#include "SimpleBlinkAction.hpp"
#include "MoveAction.hpp"
#include "RainbowMoveAction.hpp"
#include "RainbowCurtainAction.hpp"
#include "SineCurtainAction.hpp"

constexpr uint8_t Rows = 2;
constexpr uint8_t Columns = 12;
constexpr uint8_t NumLeds = Rows * Columns;
constexpr uint8_t DataPin = 2;

CRGB leds[NumLeds];

static auto ledBlinker = make_delayed_updater(1000, SimpleBlinkAction(LED_BUILTIN));
static auto pixelMover = make_delayed_updater(66, MoveAction<NumLeds>(leds));
static auto rainbowPixelMover = make_delayed_updater(66, RainbowMoveAction<NumLeds>(leds));
static auto rainbowCurtainEffect = make_delayed_updater(333, RainbowCurtainAction<Rows, Columns>(leds));
static auto sineCurtainEffect = make_delayed_updater(66, SineCurtainAction<Rows, Columns>(leds));

void setup()
{
  FastLED.addLeds<WS2812B, DataPin>(leds, NumLeds);
}

void loop()
{
  unsigned long currentMillis = millis();

  ledBlinker.update(currentMillis);
  sineCurtainEffect.update(currentMillis);
}