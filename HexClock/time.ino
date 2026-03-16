#include "timez.h"

void time_setup ()
{
  Serial.println("Setting up NTP");
  Serial.println("Next Loop-Step: " + String(millis()) + ":");
  configTime(MYTZ, "pool.ntp.org");
}