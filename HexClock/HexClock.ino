#include "HexClock.h"

//Digits color values in RGB
int r=255;
int g=255;
int b=255;

const char* ESP_HOST_NAME = "esp-" + ESP.getFlashChipId();
//Your Wifi info
const char* ssid    = SECRET_SSID;
const char* password = SECRET_PASSWORD;

//Your time zone
int timezone = TIMEZONE * 3600;
int dst = 0;
   
WiFiClient wifiClient;

void connectWifi() 
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  delay(500);
  connectWifi();
  Serial.println();
  Serial.println("\n\nNext Loop-Step: " + String(millis()) + ":");
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  /*
    time_t now = time(nullptr);
    struct tm* p_tm = localtime(&now);
    Serial.print("-------------------------------------------------\n");
    Serial.print("Date & Time : ");
    Serial.print(p_tm->tm_mday);
    Serial.print("/");
    Serial.print(p_tm->tm_mon + 1);
    Serial.print("/");
    Serial.print(p_tm->tm_year + 1900);
    Serial.print(" ");
    int hour=p_tm->tm_hour;
    int minute=p_tm->tm_min;
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(p_tm->tm_sec);
    */
    FastLED.clear();
    pride();
    draw_hours();
    draw_mins();

    
    
    

    FastLED.show();  
}



/*------------------------------------Hour LEDs------------------------------------*/
void hour0()
{
    leds[3] = CRGB(255, 0, 0);
    leds[4] = CRGB(255, 0, 0);
    leds[15] = CRGB(255, 0, 0);
    leds[16] = CRGB(255, 0, 0);
    leds[23] = CRGB(255, 0, 0);
    leds[24] = CRGB(255, 0, 0);
}
void hour1()
{
    leds[3] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
}
void hour2()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour3()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour4()
{
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
}
void hour5()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour6()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour7()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
}
void hour8()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour9()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour10()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour11()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);  
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
}
void hour12()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour13()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour14()
{
    leds[2] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour15()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour16()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour17()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour18()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour19()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour20()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour21()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour22()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour23()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour24()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
/*----------------------------Minutes LEDs----------------------------*/
void min0()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min1()
{
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min2()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min3()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min4()
{
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
}
void min5()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min6()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min7()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
}
void min8()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min9()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min10()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min11()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
}
void min12()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min13()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min14()
{
    leds[62] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min15()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min16()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min17()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min18()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min19()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min20()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min21()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min22()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min23()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min24()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min25()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min26()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min27()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min28()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min29()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min30()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min31()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min32()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min33()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min34()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min35()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min36()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min37()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min38()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min39()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min40()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min41()
{
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min42()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min43()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min44()
{
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min45()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min46()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min47()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min48()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min49()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min50()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min51()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min52()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min53()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min54()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min55()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min56()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min57()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min58()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min59()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min60()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
