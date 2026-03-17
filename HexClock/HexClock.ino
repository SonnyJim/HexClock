#include "HexClock.h"

//Digits color values in RGB
int r=255;
int g=255;
int b=255;

const char* ESP_HOST_NAME = "esp-" + ESP.getFlashChipId();
//Your Wifi info
const char* ssid    = SECRET_SSID;
const char* password = SECRET_PASSWORD;

#include <TZ.h>


WiFiClient wifiClient;

void connectWifi() 
{ 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  //Serial.setDebugOutput(true);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
    Serial.print(WiFi.status());

  }
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());
  Serial.println();

}

void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);
  FastLED.setBrightness(BRIGHTNESS);
  for (int i = 0; i < NUM_LEDS;i++)
    leds[i] = CRGB(255,0,0);
  FastLED.show();
  
  Serial.begin(115200);

  delay(500);
  Serial.println();
  Serial.println();
  Serial.println("******************* BOOT *******************");
  connectWifi();
  cfg_setup (); //Also mounts LittleFS
  log_setup ();

  //TODO Fallback to Hotspot
   
  for (int i = 0; i < NUM_LEDS;i++)
    leds[i] = CRGB(0,255,0);
  FastLED.show();
  
  //Serial.println ("Setting up OTA");
  ota_setup();
  ftp_setup();
  
  for (int i = 0; i < NUM_LEDS;i++)
    leds[i] = CRGB(0,0,255);
  FastLED.show();
  
  time_setup ();

  
  
  ha_setup();
  anim_state = ANIM_PRIDE;
  FastLED.clear();
  FastLED.show();
  web_setup ();
  Serial.println ("Setup complete, entering loop");
}

void loop()
{
   ota_loop();
   ftp_loop();

    if (!ha_connected)
      cube();
      //pride();
    else if (ha_state)
    {
      switch (anim_state)
      {
          case ANIM_NONE:
            
            for (int i = 0; i < NUM_LEDS; i++)
            {
              leds[i] = CRGB(scale8(ha_color.r, 50),scale8(ha_color.g, 50),scale8(ha_color.b, 50));
            }
            break;
          case ANIM_PRIDE:
            pride();
            break;
          case ANIM_PACIFICA:
            pacifica();
            break;
          case ANIM_BPM:
            bpm();
            break;
          case ANIM_SINELON:
            sinelon();
            break;
      }
    }
    else
      FastLED.clear();
    //pride();
    //cube();
    //pacifica();
    //bpm();
    //sinelon();
    //juggle();
    draw_time();
    FastLED.show(); 
    ha_loop(); 
    
}



