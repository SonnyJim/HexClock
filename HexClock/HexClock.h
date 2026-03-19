#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <time.h>
#include "FastLED.h"
#include <ArduinoHA.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "LittleFS.h"
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebSrv.h>
#include <SimpleFTPServer.h>

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    2
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define NUM_LEDS    96
#define BRIGHTNESS  255

#define DEFAULT_REGIONCITY "Europe/London"
#define DEFAULT_USERNAME  "hexclock"
#define DEFAULT_PASSWORD  "groovy"
#define DEFAULT_MQTT_ADDR "192.168.0.100"
#define DEFAULT_MQTT_USERNAME     "homeassistant" // replace with your credentials
#define DEFAULT_MQTT_PASSWORD     ""
#define OTA_PASSWORD "heebygeebees"
#define HOSTNAME "Hexclock"

CRGB leds[NUM_LEDS];
CRGB ha_color;
int ha_state;
int ha_brightness;
int anim_state;
bool ha_connected;
bool fs_mounted;
bool cfg_loaded;

struct cfg_t 
{
  bool ftp_enabled;
  char username[32];
  char password[32];
  bool ha_enabled;
  char mqtt_addr[17];
  char mqtt_username[17];
  char mqtt_password[255];
  char regioncity[50];
  char wifi_essid[32];
  char wifi_password[64];
  uint8_t checksum;
} cfg;

#define LOGFILE "logfile.txt"
#define LOGFILE_SIZE  (100 * 1024) // Actually as much as 200 KB as we keep one old log
File logfile;

enum anim_states {ANIM_NONE, ANIM_PRIDE, ANIM_PACIFICA, ANIM_BPM, ANIM_SINELON};
const char *anim_names[] {"None", "Pride", "Pacifica", "BPM", "Sinelon"};
extern void pride (void);
extern void draw_hours (void);
extern void draw_mins (void);
extern void cfg_save (void);
extern void ha_start (void);
extern void log_write (String message);
extern bool setTimezoneFromString(const char* regionCity);