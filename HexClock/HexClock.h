#include <ESP8266WiFi.h>
#include <time.h>
#include "FastLED.h"
#include "secrets.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    2
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define NUM_LEDS    96
#define BRIGHTNESS  255
#define TIMEZONE    10

CRGB leds[NUM_LEDS];
extern void pride (void);
extern void draw_hours (void);
extern void draw_mins (void);