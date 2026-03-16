#include "draw_time.h"

void draw_pattern(const uint8_t* pattern, uint8_t count) {
  for (uint8_t i = 0; i < count; i++)
    leds[pattern[i]] = CRGB(r, g, b);
}

void draw_hours() {
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  int hour = p_tm->tm_hour;
  if (hour > 23 || hour < 0)
    hour = 0;

  if (hour == 0) {
    r = 255;
    g = 0;
    b = 0;
  } else {
    r = 255;
    g = 255;
    b = 255;
  }
  draw_pattern(hour_patterns[hour], hour_sizes[hour]);
}

void draw_mins() {
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  int minute = p_tm->tm_min;
  if (minute < 0 || minute > 59)
    minute = 0;

  draw_pattern(min_patterns[minute], min_sizes[minute]);
}