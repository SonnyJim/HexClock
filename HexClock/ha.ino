const byte mac[] = { 0x40, 0xF5, 0x20, 0x29, 0xAF, 0xB3 };
HADevice device(mac, sizeof(mac));
HAMqtt mqtt(wifiClient, device);

// HALight::BrightnessFeature enables support for setting brightness of the light.
// HALight::ColorTemperatureFeature enables support for setting color temperature of the light.
// Both features are optional and you can remove them if they're not needed.
// "prettyLight" is unique ID of the light. You should define your own ID.
HALight light("HexClock", HALight::BrightnessFeature | HALight::ColorTemperatureFeature | HALight::RGBFeature);

void onMqttMessage(const char* topic, const uint8_t* payload, uint16_t length) {
  // This callback is called when message from MQTT broker is received.
  // Please note that you should always verify if the message's topic is the one you expect.
  // For example: if (memcmp(topic, "myCustomTopic") == 0) { ... }
/*
  Serial.print("New message on topic: ");
  Serial.println(topic);
  Serial.print("Data: ");
  Serial.println((const char*)payload);
*/
  //mqtt.publish("myCustomTopic", "hello");
}

void onMqttConnected() {
  Serial.println("Connected to the broker!");
  ha_connected = true;
  log_write("Home assistant connected");
  // You can subscribe to custom topic if you need
  //mqtt.subscribe("myCustomTopic");
}

void onStateCommand(bool state, HALight* sender) {
  /*
  Serial.print("State: ");
  Serial.println(state);
  */
  ha_state = state;
  sender->setState(state);  // report state back to the Home Assistant
}

void onBrightnessCommand(uint8_t brightness, HALight* sender) {
  /*
  Serial.print("Brightness: ");
  Serial.println(brightness);
  */
  ha_brightness = brightness;
  FastLED.setBrightness(brightness);
  sender->setBrightness(brightness);  // report brightness back to the Home Assistant
}

void onColorTemperatureCommand(uint16_t temperature, HALight* sender) {
  /*
  Serial.print("Color temperature: ");
  Serial.println(temperature);
*/
  sender->setColorTemperature(temperature);  // report color temperature back to the Home Assistant
}

void onRGBColorCommand(HALight::RGBColor color, HALight* sender) {
  /*
  Serial.print("Red: ");
  Serial.println(color.red);
  Serial.print("Green: ");
  Serial.println(color.green);
  Serial.print("Blue: ");
  Serial.println(color.blue);
*/
  ha_color.r = color.red;
  ;
  ha_color.g = color.green;
  ha_color.b = color.blue;

  if (ha_color.r >= 254 && ha_color.g == 0 && ha_color.b == 0)
    anim_state = ANIM_PRIDE;
  else if (ha_color.r <= 10 && ha_color.g <= 10 && ha_color.b >= 254)
    anim_state = ANIM_BPM;
  else if (ha_color.r <= 10 && ha_color.g >= 254 && ha_color.b <= 10)
    anim_state = ANIM_PACIFICA;
  else
    anim_state = ANIM_NONE;
  //Serial.println(anim_state);
  sender->setRGBColor(color);  // report color back to the Home Assistant
}

void ha_setup() {
  log_write("Connecting to Homeassistant");
  //WiFi.macAddress(mac); //Set MAC address for hadevice
  ha_connected = false;
  if (MDNS.begin("hexclock")) {
    // at this stage your device will be available using the domain name "arduinoha.local"
    log_write("MDNS initialized - hexclock.local");
  } else {
    log_write("Failed to initialize MDNS");
    return;
  }
  // set device's details (optional)
  device.setName("ESP8266");
  device.setSoftwareVersion("1.0.0");

  // configure light (optional)
  light.setName("HexClock");
  //light.setIcon("hexagon-slice-6");
  // Optionally you can set retain flag for the HA commands
  light.setRetain(true);

  // Maximum brightness level can be changed as follows:
  // light.setBrightnessScale(50);

  // Optionally you can enable optimistic mode for the HALight.
  // In this mode you won't need to report state back to the HA when commands are executed.
  // light.setOptimistic(true);

  // Color temperature range (optional)
  // light.setMinMireds(50);
  // light.setMaxMireds(200);

  // handle light states
  light.onStateCommand(onStateCommand);
  light.onBrightnessCommand(onBrightnessCommand);              // optional
  light.onColorTemperatureCommand(onColorTemperatureCommand);  // optional
  light.onRGBColorCommand(onRGBColorCommand);                  // optional

  mqtt.onMessage(onMqttMessage);
  mqtt.onConnected(onMqttConnected);
  ha_start();
}

void ha_start() {
  log_write("Connect to HA");
  if (cfg.ha_enabled)
    mqtt.begin(cfg.mqtt_addr, cfg.mqtt_username, cfg.mqtt_password);
  else
    log_write("ha_start (): Error!  Trying to start a disabled service");
}
void ha_loop() {
  mqtt.loop();

  // You can also change the state at runtime as shown below.
  // This kind of logic can be used if you want to control your light using a button connected to the device.
  // light.setState(true); // use any state you want
}

void ha_paint() {
  int i;
  for (i = 0; i < NUM_LEDS; i++)
    leds[i] = CRGB(ha_color.r - 50, ha_color.g - 50, ha_color.b - 50);
}