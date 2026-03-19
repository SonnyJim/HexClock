#include <time.h>

void time_setup() {
    log_write("Setting up NTP");
    log_write("Next Loop-Step: " + String(millis()) + ":");

    if (setTimezoneFromString(cfg.regioncity) != true)
    {
      log_write ("Couldn't read timezone from cfg, defaulting to GMT");
      configTime("GMT","pool.ntp.org");
    }


    // Wait for time to be set
    log_write("Waiting for NTP sync");
    time_t now = time(nullptr);
    while (now < 8 * 3600 * 2) { // roughly 1970 + offset; ensures time is valid
        delay(500);
        Serial.print(".");
        now = time(nullptr);
    }
    Serial.print("\n");

    // Print current time
    struct tm timeinfo;
    localtime_r(&now, &timeinfo);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeinfo);
    log_write(String("Current time: ") + buf);
}