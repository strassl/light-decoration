#include "FastLED.h"
#include "DelayedUpdater.hpp"
#include "SimpleBlinkAction.hpp"
#include "MoveAction.hpp"

#define NUM_LEDS 12
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

static auto ledBlinker = make_delayed_updater(1000, SimpleBlinkAction(LED_BUILTIN));
static auto pixelMover = make_delayed_updater(33, MoveAction<NUM_LEDS>(leds));

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  unsigned long currentMillis = millis();

  ledBlinker.update(currentMillis);
  pixelMover.update(currentMillis);
}

void setAll(CRGB color)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = color;
  }
}