void ota_setup() {
  ArduinoOTA.onStart([]() {
    log_write("\n\n********\nOTA Start\n********\n");
  });

  ArduinoOTA.onEnd([]() {
    log_write("\n\n********\nOTA End\n********\n");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    // Convert progress to percentage and log as a string
    unsigned int percent = progress / (total / 100);
    Serial.println ("Progress: " + String(percent) + "%"); //log_write() is too slow
  });

  ArduinoOTA.onError([](ota_error_t error) {
    String msg = "Error[" + String(error) + "]: ";
    if (error == OTA_AUTH_ERROR) msg += "Auth Failed";
    else if (error == OTA_BEGIN_ERROR) msg += "Begin Failed";
    else if (error == OTA_CONNECT_ERROR) msg += "Connect Failed";
    else if (error == OTA_RECEIVE_ERROR) msg += "Receive Failed";
    else if (error == OTA_END_ERROR) msg += "End Failed";
    log_write(msg);
  });

  ArduinoOTA.setPassword((const char *)OTA_PASSWORD);
  ArduinoOTA.begin();
}

void ota_loop() {
  ArduinoOTA.handle();
}