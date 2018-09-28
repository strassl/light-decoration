#include "FastLED.h"
#include "DelayedUpdater.hpp"
#include "SimpleBlinkAction.hpp"
#include "MoveAction.hpp"
#include "RainbowMoveAction.hpp"

#define NUM_LEDS 12
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

static auto ledBlinker = make_delayed_updater(1000, SimpleBlinkAction(LED_BUILTIN));
static auto pixelMover = make_delayed_updater(66, MoveAction<NUM_LEDS>(leds));
static auto rainbowPixelMover = make_delayed_updater(66, RainbowMoveAction<NUM_LEDS>(leds));

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  unsigned long currentMillis = millis();

  ledBlinker.update(currentMillis);
  rainbowPixelMover.update(currentMillis);
}